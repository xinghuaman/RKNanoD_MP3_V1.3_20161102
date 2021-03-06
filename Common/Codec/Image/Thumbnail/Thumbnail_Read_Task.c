/* ****************************************************************************/
/* * ﾍｯﾀﾞﾌｧｲﾙのｲﾝｸﾙｰﾄ?/
/* ****************************************************************************/
#include "..\ImageInclude\image_main.h"
#include "..\ImageInclude\image_globals.h"

#include "SysInclude.h"

#ifdef THUMB_DEC_INCLUDE
#include "thumbnail_parse.h"

#pragma arm section code = "ImageContrlCode", rodata = "ImageContrlCode", rwdata = "ImageContrlData", zidata = "ImageContrlBss"

#include  "FsInclude.h"
#include  "File.h"
#include "thumbnail_read.h"

/* ID3v2 Header */
typedef struct _id3v2_Header {
    char            Id[3];                          /* ファイル識別子”ID3”(54h,41h,47h)  */
    unsigned char   Ver[2];                         /* タグのバージョン */
    unsigned char   Flg;                            /*  Bit 7:非同期化(通常0)
                                                        Bit 6:拡張ヘッダ有
                                                        Bit 5:実験中(通常0)
                                                        Bit 4:(v2.4のみ)フッタ有
                                                        Bit 3~0:0 */
    unsigned char   Size[4];                        /*  ID3v2ヘッダ以降のサイズ
                                                        独自の数値表現を使用しているので以下の式を使う
                                                        uint32_t val = (((uint8_t)Size[0])<<21) + (((uint8_t)Size[1])<<14) + (((uint8_t)Size[2])<<7) + (uint8_t)Size[3];*/
} ID3V2_HEADER;

/* ID3v23   Frame (ID3v2.2には非対応) */
typedef struct _id3v2_frame {
    char            Id[4];                          /* Frame Id */
    char            Size[4];                        /* Frame Headerを除いたフレームのサイズ*/
    char            Flg[2];                         /* 各種フラグ */
} ID3V23_FRAME;

/* ID3v22   Frame (ID3v2.3には非対応) */
typedef struct _id3v22_frame {
    char            Id[3];                          /* Frame Id */
    char            Size[3];                        /* Frame Headerを除いたフレームのサイズ*/
} ID3V22_FRAME;

/* APIC Frame (ID3v2.2には非対応) */
typedef struct _apic_frame {
    ID3V23_FRAME    Fheader;                        /* フレームヘッダ */
    char            Txtencode;                      /* テキストエンコーディング */
    char            MineType[11];                   /* 埋込みタイプ "image/jpeg" or "JPG" */
    unsigned char   PictureType[2];                 /* 画像タイプ 例.3:カバー表 */
    unsigned char   *Description;                   /* 付属データ */
    unsigned char   *PictureData;                   /* 画像データ */
} APIC_FRAME;

/* PIC  Frame (ID3v2.3には非対応) */
typedef struct _pic_frame {
    ID3V22_FRAME    Fheader;                        /* フレームヘッダ */
    char            Txtencode;                      /* テキストエンコーディング */
    char            MineType[11];                   /* 埋込みタイプ "image/jpeg" or "JPG" */
    unsigned char   PictureType[1];                 /* 画像タイプ 例.3:カバー表 */
    unsigned char   *Description;                   /* 付属データ */
    unsigned char   *PictureData;                   /* 画像データ */
} PIC_FRAME;

/* ATOM Header */
typedef struct _atom_header {
    unsigned int    Length;                         /* ATOM Length */
    char            Atomtype[4];                    /* ATOM Type */
} ATOM_HEADER;

/* ATOM Frame */
typedef struct _atom_frame {
    ATOM_HEADER     Header;                         /* ATOM Header */
    char            *Data;                          /* ATOM Data */
} ATOM_FRAME;

/* iTunesFrame */
typedef struct _itunes_frame {
    ATOM_HEADER     Header;                         /* iTunes Header */
    ATOM_HEADER     dataHeader;                     /* iTunes Header */
    char            atomver;                        /* ATOM Version */
    char            atomflg[3];                     /* ATOM Flag */
    char            null[4];                        /* NULL Data */
    char            *Data;                          /* iTunes Data */
} ITUNES_FRAME;


/* ASF Header */
typedef struct {
    char            Guid[16];                       /* ATOM Flag */
    long            Size[2];                        /* NULL Data */
} ASF_HEADER;

/* ASF Header Object */
typedef struct {
    ASF_HEADER      Header;                         /* ASF Header */
    int             HeaderNum;                      /* 小プロジェクトの数 */
    char            Reserve1;                       /* 予約領域 */
    char            Reserve2;                       /* 予約領域 */
} HEADER_OBJECT;

/* ASF Header Extension Object */
typedef struct {
    ASF_HEADER      Header;                         /* ASF Header */
    char            Reserve1[16];                   /* 予約領域 */
    short           Reserve2;                       /* 予約領域 */
    int             ExtSize;                        /* 拡張ヘッダのバイト数 */
} EXTENSION_OBJECT;

/* MetaData Library Object Record */
typedef struct {
    short           LangIndex;                      /* 言語インデックス */
    short           StreamNum;                      /* ストリーム番号 */
    short           NameLength;                     /* 名前のバイト数 */
    short           DataType;                       /* データ型 */
    int             DataLength;                     /* データのバイト数 */
    char            Name[24];                       /* データ名 */
} METALIB_RECORD;

/* MetaData Library Object */
typedef struct {
    ASF_HEADER      Header;                         /* ASF Header */
    short           MetaNum;                        /* メタデータの総数 */
    METALIB_RECORD  Rec;                            /* Record */
} METALIB_OBJECT;

/* MetaData Library Object Record */
typedef struct {
    short           NameLength;                     /* 名前のバイト数 */
    char            Name[24];                       /* データ名 */
    short           DataType;                       /* データ型 */
    short           DataLength;                     /* データのバイト数 */
} EXTDES_RECORD;

/* MetaData Library Object */
typedef struct {
    ASF_HEADER      Header;                         /* ASF Header */
    short           MetaNum;                        /* メタデータの総数 */
} EXTDES_OBJECT;



#define MP3 1
#define AAC 2

#define ID3V2HOFS 10
#define ID3V2FOFS 10
#define ATOMHOFS 8
#define METALIBOFS 38
#define ITH2DOFS 24

#define BUF_SIZE 10
#define LAYER_NUM 10


static ID3V2_HEADER Id3v2_header;
static int          Id3v2size;


/************************************************************************/
/* 外部 IF用変数 */
static char* Thumb_FileName;
FILE *Thumb_FilePointer;
PIC_DATA ThumbData;
char ThumbType[11];



/************************************************************************/
/* 内部関数  */
static int thumbfilejdg(char* thumb_filename);                                      /* 拡張子解析 戻り値 0:異常 1:MP3 2:AAC 3:WMA */
static int thumbfiletypejdg(FILE *fp);                                              /* 拡張子解析 戻り値 0:異常 1:MP3 2:AAC 3:WMA */
static int analyze_id3(FILE *fp);                                                   /* ID3解析 戻り値 0:異常 1:MP3 2:AAC 3:WMA */
static int getheader(FILE *fp);                                                     /* ID3v2 ヘッダ情報取得 */
static void initid3v2header(void);                                                  /* ヘッダ初期化 */
static void initerrinfo(void);                                                      /* 読込異常時初期化 */
static int seektoapicframe(FILE *fp);                                               /* APIC フレームまで移動 */
static int seektopicframe(FILE *fp);                                                /* PIC フレームまで移動 */
static int parseapicframe(FILE *fp, int *picsize);                                  /* APIC フレーム分解 */
static int parsepicframe(FILE *fp, int *picsize);                                   /* PIC フレーム分解 */
static int atomheadersearch(ATOM_FRAME *atomframe, char *atomname, unsigned int atomsize, FILE *fp);                            /* ATOM Header Read */
static int atomcovrsearch(FILE *fp);                                                /* ATOM covr 検索処理 */
static int atomid32search(FILE *fp);                                                /* ATOM ID32 検索処理 */
static int atomsearchpicdata(FILE *fp);                                             /* ATOM 画像データ検索処理 */
static int itunesheadersearch(ATOM_FRAME *atomframe, char *atomname, unsigned int atomsize, FILE *fp);                          /* iTunes Header Read */
static int parseExtObj(FILE *fp);                                                   /* Header Extension Object 分解 */
static int parseExtConDesObj(FILE *fp);                                             /* Extend Content Description Object 分解 */
static int analyze_asf(FILE *fp);                                                   /* ASF ファイル 解析 */
static int seektoExtObj(FILE *fp, int objnum);                                      /* Header Extension Objectまで移動 */
static int seektoExtConDesObj(FILE *fp, int objnum);                                /* Extend Content Description Objectまで移動 */
static int parsewmpic(FILE *fp);                                                    /* WM/Picture 分解 */




static int seekToRelativeOffset(FILE *fp, unsigned int ofs);                        /* ファイルポインタ移動 */
static unsigned short Lit2Big16bit(unsigned short us);                              /* Little → Big Endian 16bit */
static unsigned int Lit2Big32bit(unsigned int ui);                                  /* Little → Big Endian 32bit */



/*************************************************/
/*  Thumbnail情報解析                            */
/*************************************************/
void Thumbnail_Read_Task()
{
    int     res;                                        /* 取得結果 */
    int     pos = 0;

    (int)FileSeek(0, SEEK_SET, (HANDLE)Thumb_FilePointer);

    initerrinfo();
    /* 拡張子判定処理 */
    res = thumbfiletypejdg(Thumb_FilePointer);          /* 拡張子判別処理 */

    /* 拡張子別解析 */
    switch (res)
    {
    case MP3:
        /* ID3 解析 */
        res = analyze_id3(Thumb_FilePointer);
        break;
    case AAC:
        /* ATOMからID3を抽出 */
            /* ID3までファイルポインタを移動させる */
        res = atomsearchpicdata(Thumb_FilePointer);
        /* 抽出結果を解析 */
        if (res == 2)
        {
            /* ID3 フレーム 発見 */
            pos = FileTell((HANDLE)(Thumb_FilePointer) + 14);
            (int) FileSeek(pos, SEEK_SET, (HANDLE) Thumb_FilePointer);
            res = analyze_id3(Thumb_FilePointer);
        }
        else if (res == 1)
        {

        }

        break;

    default:
        /* 非対応拡張子または読込エラー */

        break;
    }

    if (res < 0) {
        initerrinfo();
    }
    (int) FileSeek(pos, SEEK_SET, (HANDLE) Thumb_FilePointer);
}

/* **************************************** */
/* 読込異常時初期化処理                       */
/* **************************************** */
static void initerrinfo(void)
{
    ThumbData.PicStart = -1;
    ThumbData.PicSize = -1;
    memset(ThumbType, 0, sizeof(ThumbType));
}


/*************************************************/
/*  Thumbnail  拡張子判定                         */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0:異常 1 : MP3 2 : AAC */
/*************************************************/
static int thumbfilejdg(char *thumbfilename)
{
    int res = 0;
    unsigned int i = 0;
    char str[128];
    char* buf[BUF_SIZE], *filetype;

    memset(str, 0, 128);
    memcpy(str, thumbfilename, strlen(thumbfilename));

    /* 拡張子 検索 */
    buf[i] = strtok(str, ".");
    do
    {
        buf[++i] = strtok(NULL, ".");
    } while ((i < BUF_SIZE) && (buf[i] != NULL));

    i = 0;

    while (buf[i] != NULL) {                        /* 最後のトークンが拡張子 */
        filetype = buf[i];
        i++;
    }

    /* 拡張子 判定 */
    for (i = 0; i < strlen(filetype); i++)          /* 大文字を小文字に変換 */
    {
        if ((filetype[i] >= 'A') && (filetype[i] <= 'Z'))
        {
            filetype[i] = filetype[i] - 0x20;
        }
    }

    if (strncmp(filetype, "mp3",3) == 0)
    {
        res = MP3;
    }
    else if ((strncmp(filetype, "aac",3) == 0) || (strncmp(filetype, "mp4",3) == 0) || (strncmp(filetype, "m4a",3) == 0)) {
        res = AAC;
    }
    else {
        res = 0;
    }

    return res;
}

/*************************************************/
/*  Thumbnail  拡張子判定                         */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0:異常 1 : MP3 2 : AAC */
/*************************************************/
static int thumbfiletypejdg(FILE *fp)
{
    int res = 0;
    char str[32];
    char objid[17] = { 0x30, 0x26, 0xB2, 0x75, 0x8E, 0x66, 0xCF, 0x11, 0xA6,
        0xD9, 0x00, 0xAA, 0x00, 0x62, 0xCE, 0x6C };

    memset(str, 0, 32);

    /* ファイル先頭部分読出し */
    res = FileRead((uint8*) &str, (16 * sizeof(char)), (HANDLE) fp);
    if (res < sizeof(ID3V23_FRAME)) {
        return -1;
    }
    if (res < 1) {
        return -1;
    }

    if (strncmp(str, "ID3", 3) == 0)
    {
        res = MP3;
    }
    else if (strncmp(&str[4], "ftyp", 4) == 0 ) {
        res = AAC;
    }
    else {
        res = 0;
    }

    (int) FileSeek(0, SEEK_SET, (HANDLE) fp);
    return res;
}

/*************************************************/
/*  ID3 解析                                   */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int analyze_id3(FILE *fp)
{
    int     res = 0;
    int     picsize;

    res = getheader(fp);                                        /* ヘッダ情報取得 */
    if (res < 0) {
        /* 読込 or 識別子エラー */
        return -1;
    }

    if (Id3v2_header.Ver[0] == 0x02) {
        /* ID3v2.2 */
        res = seektopicframe(fp);                               /* PIC フレームまで移動 */
    }
    else {
        /* ID3v2.3 & ID3v2.4 */
        res = seektoapicframe(fp);                              /* APIC フレームまで移動 */
    }
    if (res < 0) {
        /* APIC/PIC Frame not exist or Cant't Read Err */
        return -1;
    }

    if (Id3v2_header.Ver[0] == 0x02) {
        /* ID3v2.2 */
        res = parsepicframe(fp, &picsize);                      /* PIC フレーム分解 */
    }
    else {
        /* ID3v2.3 & ID3v2.4 */
        res = parseapicframe(fp, &picsize);                     /* APIC フレーム分解 */
    }
    if (res < 0) {
        /* Cant't Read Err */
        return -1;
    }

    return res;
}

/*************************************************/
/*  APICフレーム分解                           */
/*  引数：FILE *fp：ファイルポインタ             */
/*        char *ppicdata：画像データ           */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int parseapicframe(FILE *fp, int *picsize)
{
    int     res = 0, pos = 0;
    int     framesize = 0;
    unsigned int datasize = 0;
    char    buf[2] = { 1 };
    APIC_FRAME  apic_frame;

    /* ID3v2 Header Read */
    if (FileRead((uint8*) &apic_frame.Fheader, (1 * sizeof(ID3V23_FRAME)), (HANDLE) fp) < sizeof(ID3V23_FRAME)) {
        return -1;
    }

    /* サイズ計算 */
    if (Id3v2_header.Ver[0] == 0x03)
    {
        /* ID3v2.3 */
        framesize = ((unsigned char)(apic_frame.Fheader.Size[0]) << 24) + (unsigned char)((apic_frame.Fheader.Size[1]) << 16)
            + ((unsigned char)(apic_frame.Fheader.Size[2]) << 8) + (unsigned char)apic_frame.Fheader.Size[3];
    }
    else {
        /* ID3v2.4 */
        framesize = (unsigned char)((apic_frame.Fheader.Size[0]) << 21) + (unsigned char)((apic_frame.Fheader.Size[1]) << 14)
            + (unsigned char)((apic_frame.Fheader.Size[2]) << 7) + (unsigned char)apic_frame.Fheader.Size[3];
    }

    /* テキストエンコーディング取得 */
    if (FileRead((uint8*) &apic_frame.Txtencode, (1 * sizeof(apic_frame.Txtencode)), (HANDLE) fp) < sizeof(apic_frame.Txtencode)) {
        return -1;
    }
    pos = FileTell((HANDLE)(fp));

    /* NULLまでの量を計測 */
    while (buf[0] != 0) {             /* NULL */
        (int) FileRead((uint8*) &buf[0], 1, (HANDLE) fp);
        if (datasize < 11) {
            datasize++;
        } else {
            break;
        }
    }

    if ((int) FileSeek(pos, SEEK_SET, (HANDLE) fp) != 0) {
        return -1;
    }
    /* 埋め込みタイプ取得 */
    if (FileRead((uint8*) &apic_frame.MineType, (datasize * sizeof(char)), (HANDLE) fp) < (datasize * sizeof(char))) {
        return -1;
    }

    memcpy(&ThumbType, &apic_frame.MineType, datasize);

    /* 画像タイプ取得 */
    if (FileRead((uint8*) &apic_frame.PictureType, (1 * sizeof(apic_frame.PictureType)), (HANDLE) fp) < sizeof(apic_frame.PictureType)) {
        return -1;
    }

    datasize += sizeof(apic_frame.Txtencode);
    datasize += sizeof(apic_frame.PictureType);


    /* NULLまで読み捨てる */
    buf[0] = 1;
    while (buf[0] != 0) {             /* NULL */
        (int) FileRead((uint8*) &buf[0], 1, (HANDLE) fp);
        datasize++;
    }

    /* 画像データのサイズ計算 */
    datasize = framesize - datasize;
    ThumbData.PicStart = (long)FileTell((HANDLE)(fp));
    ThumbData.PicSize = (long)datasize;

    return res;
}

/*************************************************/
/*  PICフレーム分解                                */
/*  引数：FILE *fp：ファイルポインタ             */
/*        char *ppicdata：画像データ           */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int parsepicframe(FILE *fp, int *picsize)
{
    int     res = 0, pos = 0;
    int     framesize = 0;
    unsigned int    datasize = 0;
    char    buf[2] = { 1 };
    PIC_FRAME   pic_frame;

    /* ID3v2 Header Read */
    if (FileRead((uint8*) &pic_frame.Fheader, (1 * sizeof(ID3V22_FRAME)), (HANDLE) fp) < sizeof(ID3V22_FRAME)) {
        return -1;
    }
    /* サイズ計算 */
    framesize = (unsigned char)((pic_frame.Fheader.Size[0]) << 16)
        + ((unsigned char)(pic_frame.Fheader.Size[1]) << 8) + (unsigned char)pic_frame.Fheader.Size[2];

    /* テキストエンコーディング取得 */
    if (FileRead((uint8*) &pic_frame.Txtencode, (1 * sizeof(pic_frame.Txtencode)), (HANDLE) fp) < sizeof(pic_frame.Txtencode)) {
        return -1;
    }

    pos = FileTell((HANDLE)(fp));

    /* 埋め込みタイプ NULLまでの量を計測 */
    while (buf[0] != 0) {             /* NULL */
        (int) FileRead((uint8*) &buf[0], 1, (HANDLE) fp);
        if (datasize < 11) {
            datasize++;
        } else {
            break;
        }
    }
    datasize--;
    if ((int) FileSeek(pos, SEEK_SET, (HANDLE) fp) != 0) {
        return -1;
    }

    /* 埋め込みタイプ取得 */
    if (FileRead((uint8*) &pic_frame.MineType, (datasize * sizeof(char)), (HANDLE) fp) < (datasize * sizeof(char))) {
        return -1;
    }

    memcpy(&ThumbType, &pic_frame.MineType, datasize);

    /* 画像タイプ取得 */
    if (FileRead((uint8*) &pic_frame.PictureType, (1 * sizeof(pic_frame.PictureType)), (HANDLE) fp) < sizeof(pic_frame.PictureType)) {
        return -1;
    }

    datasize += sizeof(pic_frame.Txtencode);
    datasize += sizeof(pic_frame.PictureType);

    /* NULLまで読み捨てる */
    buf[0] = 1;
    while (buf[0] != 0) {             /* NULL */
        (int) FileRead((uint8*) &buf[0], 1, (HANDLE) fp);
        datasize++;
    }

    /* 画像データのサイズ計算 */
    datasize = framesize - datasize;
    ThumbData.PicStart = (long)FileTell((HANDLE)(fp));
    ThumbData.PicSize = (long)datasize;

    return res;
}

/*************************************************/
/*  ID3 ヘッダ情報取得                          */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int getheader(FILE *fp)
{
    int     res = 0;
    int     tmp = 0;

    initid3v2header();

    /* ID3v2 ID Read */
    if (FileRead((uint8*)&Id3v2_header.Id, (1 * sizeof(Id3v2_header.Id)), (HANDLE)fp) < sizeof(Id3v2_header.Id)) {
        return -1;
    }


    /* ID Check */
    if (strncmp(Id3v2_header.Id,"ID3", 3) != 0)
    {
        return -1;
    }

    /* ID3v2 Version Read */
    if (FileRead((uint8*) &Id3v2_header.Ver, (1 * sizeof(Id3v2_header.Ver)), (HANDLE) fp) < sizeof(Id3v2_header.Ver)) {
        return -1;
    }

    /* ID3v2 Version Check */
    if ((Id3v2_header.Ver[0] != 0x02) && (Id3v2_header.Ver[0] != 0x03) && (Id3v2_header.Ver[0] != 0x04))
    {
        return -1;
    }

    /* ID3v2 Flag Read */
    if (FileRead((uint8*) &Id3v2_header.Flg, (1 * sizeof(Id3v2_header.Flg)), (HANDLE) fp) < sizeof(Id3v2_header.Flg)) {
        return -1;
    }

    /* ID3v2 Size Read */
    if (FileRead((uint8*) &Id3v2_header.Size, (1 * sizeof(Id3v2_header.Size)), (HANDLE) fp) < sizeof(Id3v2_header.Size)) {
        return -1;
    }

    /* Size Calc */
    Id3v2size = ((Id3v2_header.Size[0]) << 21) + ((Id3v2_header.Size[1]) << 14)
        + ((Id3v2_header.Size[2]) << 7) + Id3v2_header.Size[3];



    return res;
}


/*************************************************/
/*  APIC Frame 移動処理                          */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int seektoapicframe(FILE *fp)
{
    int     res = -1;
    int     pos = 0;
    int     size = 0;
    char    fid[5];
    ID3V23_FRAME        id3v23_frame;

    if ((int) FileSeek(ID3V2HOFS, SEEK_SET, (HANDLE) fp) != 0) {
        return -1;
    }
    pos = FileTell((HANDLE)(fp));

    while (pos <= (Id3v2size + FileTell((HANDLE)(fp))))
    {
        /* ID3v23 Frame Header Read */
    if (FileRead((uint8*) &id3v23_frame, (1 * sizeof(ID3V23_FRAME)), (HANDLE) fp) < sizeof(ID3V23_FRAME)) {
        return -1;
    }

        //strcpy(fid, id3v23_frame.Id);
        strncpy(fid, id3v23_frame.Id, 4);

        if (Id3v2_header.Ver[0] == 0x03)
        {
            /* ID3v2.3 */
            size = ((unsigned char)(id3v23_frame.Size[0]) << 24) + (unsigned char)((id3v23_frame.Size[1]) << 16)
                + ((unsigned char)(id3v23_frame.Size[2]) << 8) + (unsigned char)id3v23_frame.Size[3];
        }
        else {
            /* ID3v2.4 */
            size = (unsigned char)((id3v23_frame.Size[0]) << 21) + (unsigned char)((id3v23_frame.Size[1]) << 14)
                + (unsigned char)((id3v23_frame.Size[2]) << 7) + (unsigned char)id3v23_frame.Size[3];
        }
        if(size <= 0)
        {
            return -1;
        }

        if (strncmp(fid, "APIC", 4) == 0)
        {
            /* APICを見つけたらフレームヘッダまでポインタをもどす */
            if ((int) FileSeek(pos, SEEK_SET, (HANDLE) fp) != 0) {
                return -1;
            }
            res = 0;
            break;
        }
#if 1
        else if((strncmp(fid, "AENC", 4) != 0)
                    && (strncmp(fid, "ASPI", 4) != 0)
                    && (strncmp(fid, "COMM", 4) != 0)
                    && (strncmp(fid, "COMR", 4) != 0)
                    && (strncmp(fid, "ENCR", 4) != 0)
                    && (strncmp(fid, "EQUA", 4) != 0)
                    && (strncmp(fid, "ETCO", 4) != 0)
                    && (strncmp(fid, "GEOB", 4) != 0)
                    && (strncmp(fid, "GRID", 4) != 0)
                    && (strncmp(fid, "IPLS", 4) != 0)
                    && (strncmp(fid, "LINK", 4) != 0)
                    && (strncmp(fid, "MCDI", 4) != 0)
                    && (strncmp(fid, "MLLT", 4) != 0)
                    && (strncmp(fid, "OWNE", 4) != 0)
                    && (strncmp(fid, "PRIV", 4) != 0)
                    && (strncmp(fid, "PCNT", 4) != 0)
                    && (strncmp(fid, "POPM", 4) != 0)
                    && (strncmp(fid, "POSS", 4) != 0)
                    && (strncmp(fid, "RBUF", 4) != 0)
                    && (strncmp(fid, "RVAD", 4) != 0)
                    && (strncmp(fid, "RVRB", 4) != 0)
                    && (strncmp(fid, "SEEK", 4) != 0)
                    && (strncmp(fid, "SIGN", 4) != 0)
                    && (strncmp(fid, "SYLT", 4) != 0)
                    && (strncmp(fid, "SYTC", 4) != 0)
                    && (strncmp(fid, "TALB", 4) != 0)
                    && (strncmp(fid, "TBPM", 4) != 0)
                    && (strncmp(fid, "TCMP", 4) != 0)
                    && (strncmp(fid, "TCOM", 4) != 0)
                    && (strncmp(fid, "TCON", 4) != 0)
                    && (strncmp(fid, "TCOP", 4) != 0)
                    && (strncmp(fid, "TDAT", 4) != 0)
                    && (strncmp(fid, "TDEN", 4) != 0)
                    && (strncmp(fid, "TDLY", 4) != 0)
                    && (strncmp(fid, "TDOR", 4) != 0)
                    && (strncmp(fid, "TDRC", 4) != 0)
                    && (strncmp(fid, "TDRL", 4) != 0)
                    && (strncmp(fid, "TDTG", 4) != 0)
                    && (strncmp(fid, "TENC", 4) != 0)
                    && (strncmp(fid, "TEXT", 4) != 0)
                    && (strncmp(fid, "TFLT", 4) != 0)
                    && (strncmp(fid, "TIME", 4) != 0)
                    && (strncmp(fid, "TIPL", 4) != 0)
                    && (strncmp(fid, "TIT1", 4) != 0)
                    && (strncmp(fid, "TIT2", 4) != 0)
                    && (strncmp(fid, "TIT3", 4) != 0)
                    && (strncmp(fid, "TKEY", 4) != 0)
                    && (strncmp(fid, "TLAN", 4) != 0)
                    && (strncmp(fid, "TLEN", 4) != 0)
                    && (strncmp(fid, "TMED", 4) != 0)
                    && (strncmp(fid, "TMOO", 4) != 0)
                    && (strncmp(fid, "TOAL", 4) != 0)
                    && (strncmp(fid, "TOFN", 4) != 0)
                    && (strncmp(fid, "TOLY", 4) != 0)
                    && (strncmp(fid, "TOPE", 4) != 0)
                    && (strncmp(fid, "TORY", 4) != 0)
                    && (strncmp(fid, "TOWN", 4) != 0)
                    && (strncmp(fid, "TPE1", 4) != 0)
                    && (strncmp(fid, "TPE2", 4) != 0)
                    && (strncmp(fid, "TPE3", 4) != 0)
                    && (strncmp(fid, "TPE4", 4) != 0)
                    && (strncmp(fid, "TPOS", 4) != 0)
                    && (strncmp(fid, "TPRO", 4) != 0)
                    && (strncmp(fid, "TPUB", 4) != 0)
                    && (strncmp(fid, "TRCK", 4) != 0)
                    && (strncmp(fid, "TRDA", 4) != 0)
                    && (strncmp(fid, "TRSN", 4) != 0)
                    && (strncmp(fid, "TRSO", 4) != 0)
                    && (strncmp(fid, "TSIZ", 4) != 0)
                    && (strncmp(fid, "TSRC", 4) != 0)
                    && (strncmp(fid, "TSOA", 4) != 0)
                    && (strncmp(fid, "TSOC", 4) != 0)
                    && (strncmp(fid, "TSOT", 4) != 0)
                    && (strncmp(fid, "TSOP", 4) != 0)
                    && (strncmp(fid, "TSO2", 4) != 0)
                    && (strncmp(fid, "TSSE", 4) != 0)
                    && (strncmp(fid, "TSST", 4) != 0)
                    && (strncmp(fid, "TYER", 4) != 0)
                    && (strncmp(fid, "TXXX", 4) != 0)
                    && (strncmp(fid, "UFID", 4) != 0)
                    && (strncmp(fid, "USER", 4) != 0)
                    && (strncmp(fid, "USLT", 4) != 0)
                    && (strncmp(fid, "WCOM", 4) != 0)
                    && (strncmp(fid, "WCOP", 4) != 0)
                    && (strncmp(fid, "WOAF", 4) != 0)
                    && (strncmp(fid, "WOAR", 4) != 0)
                    && (strncmp(fid, "WOAS", 4) != 0)
                    && (strncmp(fid, "WORS", 4) != 0)
                    && (strncmp(fid, "WPAY", 4) != 0)
                    && (strncmp(fid, "WPUB", 4) != 0)
                    && (strncmp(fid, "WXXX", 4) != 0))
        {
            printf("\n======Check APIC Error\n");
            return -1;
        }
#endif
        if (seekToRelativeOffset(fp, size-1) != 0){         /* サイズ分移動 */
            return -1;
        }
        //FileSeek(size, SEEK_CUR, (HANDLE) fp);

        pos = FileTell((HANDLE)(fp));
    }

    return res;
}

/*************************************************/
/*  PIC Frame 移動処理                           */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int seektopicframe(FILE *fp)
{
    int     res = -1;
    int     pos = 0;
    int     size = 0;
    char    fid[5];
    ID3V22_FRAME        id3v22_frame;
    if ((int) FileSeek(ID3V2HOFS, SEEK_SET, (HANDLE) fp) != 0) {
        return -1;
    }

    pos = FileTell((HANDLE)(fp));

    while (pos <= Id3v2size)                            /* ID3v2末端まで検索 */
    {
        /* ID3v22 Frame Header Read */
        if (FileRead((uint8*) &id3v22_frame, (1 * sizeof(ID3V22_FRAME)), (HANDLE) fp) < sizeof(ID3V22_FRAME)) {
            return -1;
        }

        //strcpy(fid, id3v22_frame.Id);
        strncpy(fid, id3v22_frame.Id, 3);

        size = (unsigned char)((id3v22_frame.Size[0]) << 16)
            + ((unsigned char)(id3v22_frame.Size[1]) << 8) + (unsigned char)id3v22_frame.Size[2];
        if(size <= 0)
        {
            return -1;
        }

        if (strncmp(fid, "PIC", 3) == 0)
        {
            /* APICを見つけたらフレームヘッダまでポインタをもどす */
            if ((int) FileSeek(pos, SEEK_SET, (HANDLE) fp) != 0) {
                return -1;
            }
            res = 0;
            break;
        }
#if 1
        else if((strncmp(fid, "BUF", 3) != 0)
                    && (strncmp(fid, "COM", 3) != 0)
                    && (strncmp(fid, "CRA", 3) != 0)
                    && (strncmp(fid, "CNT", 3) != 0)
                    && (strncmp(fid, "CRM", 3) != 0)
                    && (strncmp(fid, "EQU", 3) != 0)
                    && (strncmp(fid, "ETC", 3) != 0)
                    && (strncmp(fid, "GEO", 3) != 0)
                    && (strncmp(fid, "IPL", 3) != 0)
                    && (strncmp(fid, "LNK", 3) != 0)
                    && (strncmp(fid, "MCI", 3) != 0)
                    && (strncmp(fid, "MLL", 3) != 0)
                    && (strncmp(fid, "POP", 3) != 0)
                    && (strncmp(fid, "RVA", 3) != 0)
                    && (strncmp(fid, "REV", 3) != 0)
                    && (strncmp(fid, "SLT", 3) != 0)
                    && (strncmp(fid, "STC", 3) != 0)
                    && (strncmp(fid, "TAL", 3) != 0)
                    && (strncmp(fid, "TBP", 3) != 0)
                    && (strncmp(fid, "TCO", 3) != 0)
                    && (strncmp(fid, "TCP", 3) != 0)
                    && (strncmp(fid, "TCM", 3) != 0)
                    && (strncmp(fid, "TCR", 3) != 0)
                    && (strncmp(fid, "TDA", 3) != 0)
                    && (strncmp(fid, "TDY", 3) != 0)
                    && (strncmp(fid, "TEN", 3) != 0)
                    && (strncmp(fid, "TXT", 3) != 0)
                    && (strncmp(fid, "TFT", 3) != 0)
                    && (strncmp(fid, "TIM", 3) != 0)
                    && (strncmp(fid, "TT1", 3) != 0)
                    && (strncmp(fid, "TT2", 3) != 0)
                    && (strncmp(fid, "TT3", 3) != 0)
                    && (strncmp(fid, "TOA", 3) != 0)
                    && (strncmp(fid, "TOF", 3) != 0)
                    && (strncmp(fid, "TOL", 3) != 0)
                    && (strncmp(fid, "TOT", 3) != 0)
                    && (strncmp(fid, "TOR", 3) != 0)
                    && (strncmp(fid, "TP1", 3) != 0)
                    && (strncmp(fid, "TP2", 3) != 0)
                    && (strncmp(fid, "TP3", 3) != 0)
                    && (strncmp(fid, "TP4", 3) != 0)
                    && (strncmp(fid, "TPA", 3) != 0)
                    && (strncmp(fid, "TPB", 3) != 0)
                    && (strncmp(fid, "TRC", 3) != 0)
                    && (strncmp(fid, "TRD", 3) != 0)
                    && (strncmp(fid, "TRK", 3) != 0)
                    && (strncmp(fid, "TSC", 3) != 0)
                    && (strncmp(fid, "TSI", 3) != 0)
                    && (strncmp(fid, "TSS", 3) != 0)
                    && (strncmp(fid, "TYE", 3) != 0)
                    && (strncmp(fid, "TXX", 3) != 0)
                    && (strncmp(fid, "TLA", 3) != 0)
                    && (strncmp(fid, "TLE", 3) != 0)
                    && (strncmp(fid, "TMT", 3) != 0)
                    && (strncmp(fid, "TKE", 3) != 0)
                    && (strncmp(fid, "UFI", 3) != 0)
                    && (strncmp(fid, "ULT", 3) != 0)
                    && (strncmp(fid, "WCM", 3) != 0)
                    && (strncmp(fid, "WCP", 3) != 0)
                    && (strncmp(fid, "WAF", 3) != 0)
                    && (strncmp(fid, "WAR", 3) != 0)
                    && (strncmp(fid, "WAS", 3) != 0)
                    && (strncmp(fid, "WPB", 3) != 0)
                    && (strncmp(fid, "WXX", 3) != 0))
        {
            printf("\n=====Check PIC Error=====\n");
            return -1;
        }
#endif
        if (seekToRelativeOffset(fp, size - 1) != 0){           /* サイズ分移動 */
            return -1;
        }

        pos = FileTell((HANDLE)(fp));
    }

    return res;
}


/*************************************************/
/*  ATOM 解析                                  */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int atomsearchpicdata(FILE *fp)
{
    int     res = -1, i = 0;
    unsigned int        pos = 0;
    int     size = 0, datasize = 0;
    ATOM_FRAME          atomframe;
    ATOM_FRAME          ftypframe;
    ITUNES_FRAME        itunesframe;

    memset(&atomframe, 0, sizeof(ATOM_FRAME));
    memset(&ftypframe, 0, sizeof(ATOM_FRAME));
    memset(&itunesframe, 0, sizeof(ITUNES_FRAME));

    if (FileRead((uint8*) &ftypframe, (1 * sizeof(ATOM_HEADER)), (HANDLE) fp) < sizeof(ATOM_HEADER)) {          /* ATOM ヘッダ 読込 */
        return -1;
    }

    ftypframe.Header.Length = Lit2Big32bit(ftypframe.Header.Length);
    if(ftypframe.Header.Length < ATOMHOFS)
    {
        return -1;
    }

    seekToRelativeOffset(fp, ftypframe.Header.Length - sizeof(ATOM_HEADER) - 1);

    pos = FileTell((HANDLE)(fp));

    res = atomcovrsearch(fp);

    if (res < 0)
    {
        /* Can't Read Err */
    }
    else if (res == 1) {
        /* Found covr ATOM */
//      pos = offsetof(ITUNES_FRAME, Data);
        pos = ITH2DOFS;
        if (FileRead((uint8*) &itunesframe, (1 * pos), (HANDLE) fp) < pos) {
            return -1;
        }

        itunesframe.dataHeader.Length = Lit2Big32bit(itunesframe.dataHeader.Length);
        ThumbData.PicStart = (long)FileTell((HANDLE)(fp));
        ThumbData.PicSize = (long)(itunesframe.dataHeader.Length -sizeof(ATOM_HEADER) - sizeof(ATOM_HEADER));
        ThumbType[0] = 'J';
        ThumbType[1] = 'P';
        ThumbType[2] = 'G';
    }
    else {
        /* Can't Find covr of ATOM */
        /* Next Searching moov/meta */
        (int) FileSeek(pos, SEEK_SET, (HANDLE) fp);
        res = atomid32search(fp);

        if (res < 0)
        {
            /* Can't Read Err */
        }
        else if (res == 2) {
            /* Found ID3 ATOM */
        }
        else {
            /* Can't Find ID3 ATOM */
        }
    }

    return res;
}

/* **************************************** */
/*  情報 初期化                          */
/* **************************************** */
static void initid3v2header(void)
{
    memset(&Id3v2_header, 0, sizeof(Id3v2_header));
    //strcpy(Id3v2_header.Id, "ID3");
    strncpy(Id3v2_header.Id, "ID3", 3);
    Id3v2_header.Ver[0] = 0x03;
}

/* **************************************** */
/* ATOM 解析 covr                         */
/* 引数：FILE *fp:ファイルポインタ         */
/* **************************************** */
static int atomcovrsearch(FILE *fp)
{
    int res = 0, pos = 0;
    int         max_size = 0;
    ATOM_FRAME          atomframe;
    ATOM_FRAME          moovframe;
    ATOM_FRAME          udtaframe;
    ATOM_FRAME          metaframe;
    ATOM_FRAME          ilstframe;

    memset(&atomframe, 0, sizeof(ATOM_FRAME));
    memset(&moovframe, 0, sizeof(ATOM_FRAME));
    memset(&udtaframe, 0, sizeof(ATOM_FRAME));
    memset(&metaframe, 0, sizeof(ATOM_FRAME));
    memset(&ilstframe, 0, sizeof(ATOM_FRAME));

    if (FileRead((uint8*) &moovframe, (1 * sizeof(ATOM_HEADER)), (HANDLE) fp) < sizeof(ATOM_HEADER)) {             /* moov atom 読込 */
        return -1;
    }

#if 1
    max_size = FileGetSize((HANDLE)(fp));
    while
    (
        (strncmp(moovframe.Header.Atomtype,"moov", 4) != 0 ) &&
        (max_size > pos)
    )
    {
        moovframe.Header.Length = Lit2Big32bit(moovframe.Header.Length);
        //if(moovframe.Header.Length <= 0)
        if(moovframe.Header.Length < ATOMHOFS)
        {
            return -1;
        }
        seekToRelativeOffset(fp, (moovframe.Header.Length - ATOMHOFS - 1));
        FileRead((uint8*) &moovframe, (1 * sizeof(ATOM_HEADER)), (HANDLE) fp) < sizeof(ATOM_HEADER);
        pos = FileTell((HANDLE)(fp));
    }
#else
    //FileSeek(0 , SEEK_END, (HANDLE) fp);
    //max_size = FileTell((HANDLE)(fp));
    //FileSeek(pos , SEEK_SET, (HANDLE) fp);
    max_size = FileGetSize((HANDLE)(fp));

    while
    (
        (strncmp(moovframe.Header.Atomtype,"moov", 4) != 0 ) &&
        (max_size > pos)
    )
    {
        moovframe.Header.Length = Lit2Big32bit(moovframe.Header.Length);
        seekToRelativeOffset(fp, (moovframe.Header.Length - ATOMHOFS - 1));
        FileRead((uint8*) &moovframe, (1 * sizeof(ATOM_HEADER)), (HANDLE) fp) < sizeof(ATOM_HEADER);
        pos = FileTell((HANDLE)(fp));
    }
#endif

    /* moovATOM内のudtaを検索 */
    res = atomheadersearch(&atomframe, "udta", moovframe.Header.Length, fp);
    if (res < 0)
    {
        /* Can't Find udta of ATOM */
        return res;
    }

    memcpy(&udtaframe.Header, &atomframe.Header, sizeof(ATOM_HEADER));

    res = atomheadersearch(&atomframe, "meta", udtaframe.Header.Length, fp);
    if (res < 0)
    {
        /* Can't Find meta of ATOM */
        return res;
    }
    (int) FileSeek(4, SEEK_CUR, (HANDLE) fp);
    memcpy(&metaframe.Header, &atomframe.Header, sizeof(ATOM_HEADER));
    res = atomheadersearch(&atomframe, "ilst", metaframe.Header.Length, fp);
    if (res < 0)
    {
        /* Can't Find ilst of ATOM */
        return res;
    }

    memcpy(&ilstframe.Header, &atomframe.Header, sizeof(ATOM_HEADER));
    res = itunesheadersearch(&atomframe, "covr", ilstframe.Header.Length, fp);
    if (res < 0)
    {
        /* Can't Find covr of ATOM */
        return res;
    }
//  pos = FileTell((HANDLE)(fp)) - offsetof(ITUNES_FRAME, Data);
    pos = FileTell((HANDLE)(fp)) - ITH2DOFS;
    (int) FileSeek(pos, SEEK_SET, (HANDLE) fp);

    return res;
}

/* **************************************** */
/* ATOM 解析 id32                         */
/* 引数：FILE *fp:ファイルポインタ         */
/* **************************************** */
static int atomid32search(FILE *fp)
{
    int res = 0, pos = 0;
    int         max_size = 0;
    ATOM_FRAME          atomframe;
    ATOM_FRAME          moovframe;
    ATOM_FRAME          udtaframe;
    ATOM_FRAME          metaframe;
    ATOM_FRAME          ilstframe;

    memset(&atomframe, 0, sizeof(ATOM_FRAME));
    memset(&moovframe, 0, sizeof(ATOM_FRAME));
    memset(&udtaframe, 0, sizeof(ATOM_FRAME));
    memset(&metaframe, 0, sizeof(ATOM_FRAME));
    memset(&ilstframe, 0, sizeof(ATOM_FRAME));

    if (FileRead((uint8*) &moovframe, (1 * sizeof(ATOM_HEADER)), (HANDLE) fp) < sizeof(ATOM_HEADER)) {             /* moov atom 読込 */
        return -1;
    }


#if 1
    max_size = FileGetSize((HANDLE)(fp));
    while
    (
        (strncmp(moovframe.Header.Atomtype,"moov", 4) != 0 ) &&
        (max_size > pos)
    )
    {
        moovframe.Header.Length = Lit2Big32bit(moovframe.Header.Length);
        //if(moovframe.Header.Length <= 0)
        if(moovframe.Header.Length < ATOMHOFS)
        {
            return -1;
        }
        seekToRelativeOffset(fp, (moovframe.Header.Length - ATOMHOFS - 1));
        FileRead((uint8*) &moovframe, (1 * sizeof(ATOM_HEADER)), (HANDLE) fp) < sizeof(ATOM_HEADER);
        pos = FileTell((HANDLE)(fp));
    }
#else
    //FileSeek(0 , SEEK_END, (HANDLE) fp);
    //max_size = FileTell((HANDLE)(fp));
    //FileSeek(pos , SEEK_SET, (HANDLE) fp);
    max_size = FileGetSize((HANDLE)(fp));

    while
    (
        (strncmp(moovframe.Header.Atomtype,"moov", 4) != 0 ) &&
        (max_size > pos)
    )
    {
        moovframe.Header.Length = Lit2Big32bit(moovframe.Header.Length);
        seekToRelativeOffset(fp, (moovframe.Header.Length - ATOMHOFS - 1));
        FileRead((uint8*) &moovframe, (1 * sizeof(ATOM_HEADER)), (HANDLE) fp) < sizeof(ATOM_HEADER);
        pos = FileTell((HANDLE)(fp));
    }
#endif

    /* moovATOM内のmetaを検索 */

    res = atomheadersearch(&metaframe, "meta", moovframe.Header.Length, fp);
    if (res < 0)
    {
        /* Can't Find meta of ATOM */
        return res;
    }
    (int) FileSeek(4, SEEK_CUR, (HANDLE) fp);
    res = atomheadersearch(&atomframe, "ID32", metaframe.Header.Length, fp);
    if (res < 0)
    {
        /* Can't Find ilst of ATOM */
        return res;
    }

    pos = FileTell((HANDLE)(fp)) - sizeof(ATOM_HEADER);
    (int) FileSeek(pos, SEEK_SET, (HANDLE) fp);
    res = 2;

    return res;
}


/* **************************************** */
/* ATOM Header 読込                           */
/* 引数：ATOM_FRAME:格納場所               */
/*      layernum:階層                         */
/* **************************************** */
static int atomheadersearch(ATOM_FRAME *atomframe, char *atomname, unsigned int atomsize, FILE *fp)
{
#if 1                                               //<----20151207
    int res = -1;
    int chk;
    unsigned int totalsize;

    atomsize = Lit2Big32bit(atomsize);
    totalsize = 8;

    while (totalsize < atomsize)
    {
        if (FileRead((uint8*) &atomframe->Header, (1 * sizeof(ATOM_HEADER)), (HANDLE) fp) < sizeof(ATOM_HEADER)) {             /* ATOM Header 取得 */
            return -1;
        }
        if (strncmp(atomframe->Header.Atomtype, atomname, 4) == 0)
        {
            res = 0;
            break;
        }
        atomframe->Header.Length = Lit2Big32bit(atomframe->Header.Length);
        //if(atomframe->Header.Length <= 0)
        if(atomframe->Header.Length < ATOMHOFS)
        {
            break;
        }
        chk = seekToRelativeOffset(fp, atomframe->Header.Length - ATOMHOFS - 1);
        if(chk != 0)
        {
            /* FileSeekError */
            break;
        }
        //totalsize += itunesframe.Header.Length;
        totalsize += atomframe->Header.Length;      //<----20151207
    }
#else
    int res = -1;
    unsigned int    size = 0;
    unsigned long   atomlong = 0;
    atomsize = Lit2Big32bit(atomsize);
    atomlong = atomsize;

    size = FileTell((HANDLE)(fp));
    while (size <= (atomlong + FileTell((HANDLE)(fp))))
    {
        if (FileRead((uint8*) &atomframe->Header, (1 * sizeof(ATOM_HEADER)), (HANDLE) fp) < sizeof(ATOM_HEADER)) {             /* ATOM Header 取得 */
            return -1;
        }
        if (strncmp(atomframe->Header.Atomtype, atomname, 4) == 0)
        {
            res = 0;
            break;
        }
        atomframe->Header.Length = Lit2Big32bit(atomframe->Header.Length);
        seekToRelativeOffset(fp, atomframe->Header.Length - ATOMHOFS - 1);
        size = FileTell((HANDLE)(fp));
    }
#endif
    return res;
}

/* **************************************** */
/* ATOM Header 読込                           */
/* 引数：ATOM_FRAME:格納場所               */
/*      layernum:階層                         */
/* **************************************** */
static int itunesheadersearch(ATOM_FRAME *atomframe, char *atomname, unsigned int atomsize, FILE *fp)
{
    int res = -1;
    ITUNES_FRAME    itunesframe;
    int chk;
    unsigned int totalsize;

    memset(&itunesframe, 0 , sizeof(ITUNES_FRAME));

    atomsize = Lit2Big32bit(atomsize);
    totalsize = 8;

    while (totalsize < atomsize)
    {
        /* iTunes Header 取得 */
        if (FileRead((uint8*) &itunesframe.Header, (1 * ITH2DOFS), (HANDLE) fp) < ITH2DOFS)
        {
            break;
        }
        if (strncmp(itunesframe.Header.Atomtype, atomname, 4) == 0)
        {
            memcpy(&atomframe->Header, &itunesframe.dataHeader, sizeof(ATOM_HEADER));
            res = 1;
            break;
        }
        itunesframe.Header.Length = Lit2Big32bit(itunesframe.Header.Length);

        //if(itunesframe.Header.Length <= 0)
        if(itunesframe.Header.Length < ITH2DOFS)
        {
            break;
        }
        chk = seekToRelativeOffset(fp, itunesframe.Header.Length - ITH2DOFS - 1);
        if(chk != 0)
        {
            /* FileSeekError */
            break;
        }
        totalsize += itunesframe.Header.Length;
    }
#if 0
    int res = -1;
    unsigned int    size = 0;
    unsigned int    hofs = 0;
    ITUNES_FRAME    itunesframe;

    memset(&itunesframe, 0 , sizeof(ITUNES_FRAME));

//  hofs = offsetof(ITUNES_FRAME, Data);
    hofs = ITH2DOFS;

    atomsize = Lit2Big32bit(atomsize);
    size = FileTell((HANDLE)(fp));
    while (size <= (atomsize + FileTell((HANDLE)(fp))))
    {
        if (FileRead((uint8*) &itunesframe.Header, (1 * hofs), (HANDLE) fp) < hofs) {             /* iTunes Header 取得 */
            return -1;
        }
        if (strncmp(itunesframe.Header.Atomtype, atomname, 4) == 0)
        {
            memcpy(&atomframe->Header, &itunesframe.dataHeader, sizeof(ATOM_HEADER));
            res = 1;
            break;
        }
        itunesframe.Header.Length = Lit2Big32bit(itunesframe.Header.Length);
        seekToRelativeOffset(fp, itunesframe.Header.Length - hofs - 1);
        size = FileTell((HANDLE)(fp));
    }
#endif
    return res;
}

/*************************************************/
/*  ASF 解析                                   */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int analyze_asf(FILE *fp)
{
    int     res = 0, pos = 0;
    HEADER_OBJECT   headerobj;
    memset(&headerobj, 0, sizeof(HEADER_OBJECT));

    pos = sizeof(headerobj.Reserve1) + sizeof(headerobj.Reserve2) + sizeof(headerobj.HeaderNum) + sizeof(headerobj.Header);
    /* Header Object Read */
    if (FileRead((uint8*) &headerobj, (1 * pos), (HANDLE) fp) < pos) {
        return -1;
    }

    pos = FileTell((HANDLE) fp);

    res = seektoExtConDesObj(fp, headerobj.HeaderNum);                      /* Extend Content Description  Objectまで移動 */
    if (res < 0) {
        /* Extend Content Description Object not exist or Cant't Read Err */
        if ((int) FileSeek(pos, SEEK_SET, (HANDLE) fp) != 0) {
                return -1;
        }
        res = seektoExtObj(fp, headerobj.HeaderNum);                            /* Header Extension Objectまで移動 */
        if (res < 0) {
            /* Header Extension Object not exist or Cant't Read Err */
            DEBUG("=====Header Extension Object not exist or Cant't Read Err=====\n");
            return -1;
        }

        res = parseExtObj(fp);                                                  /* Header Extension Object 分解 */
        if (res < 0) {
            /* Cant't Read Err */
            DEBUG("=====Header Extension Cant't Read Err=====\n");
            return -1;
        }
    } else {
        res = parseExtConDesObj(fp);                                            /* Extend Content Description Object 分解 */
        if (res < 0) {
            /* Cant't Read Err */
            if ((int) FileSeek(pos, SEEK_SET, (HANDLE) fp) != 0) {
                    return -1;
            }
            res = seektoExtObj(fp, headerobj.HeaderNum);                            /* Header Extension Objectまで移動 */
            if (res < 0) {
                /* Header Extension Object not exist or Cant't Read Err */
                DEBUG("=====Header Extension Object not exist or Cant't Read Err=====\n");
                return -1;
            }

            res = parseExtObj(fp);                                                  /* Header Extension Object 分解 */
            if (res < 0) {
                /* Cant't Read Err */
                DEBUG("=====Header Extension Cant't Read Err=====\n");
                return -1;
            }
        }
    }

    return res;
}


/*************************************************/
/*  ID3 解析                                   */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int parseExtObj(FILE *fp)
{
    int     res = -1;
    int     num = 0, offset = 0;
    int     i = 0, j= 0;
    long    pos = 0, size = 0, startpos = 0;
    char    metalibid[17] = { 0x94, 0x1C, 0x23, 0x44, 0x98, 0x94, 0xD1, 0x49, 0xA1, 0x41, 0x1D, 0x13, 0x4E, 0x45, 0x70, 0x54 };
    char    wmbuf[23] = { 0x57, 0x00, 0x4D, 0x00, 0x2F, 0x00, 0x50, 0x00, 0x69
        , 0x00, 0x63, 0x00, 0x74, 0x00, 0x75, 0x00, 0x72, 0x00, 0x65, 0x00, 0x00, 0x00 };
    ASF_HEADER obj;
    EXTENSION_OBJECT extobj;
    METALIB_OBJECT  metalibobj;
    METALIB_RECORD  metalibrec;
    memset(&extobj, 0, sizeof(EXTENSION_OBJECT));
    memset(&obj, 0, sizeof(ASF_HEADER));
    memset(&metalibobj, 0, sizeof(METALIB_OBJECT));
    memset(&metalibrec, 0, sizeof(METALIB_RECORD));

    pos = FileTell((HANDLE)(fp));
    size = sizeof(extobj.Header) + sizeof(extobj.Reserve1) + sizeof(extobj.Reserve2);
    if (FileRead((uint8*) &extobj, (1 * size), (HANDLE) fp) < size) {
        return -1;
    }

    if (FileRead((uint8*) &extobj.ExtSize, (1 * sizeof(extobj.ExtSize)), (HANDLE) fp) < sizeof(extobj.ExtSize)) {             /* Header Extension Object サイズ 取得 */
        return -1;
    }
    startpos = FileTell((HANDLE)(fp));
    size = extobj.ExtSize;
    while (pos <= (size + startpos)) {
        pos = FileTell((HANDLE)(fp));
        if (FileRead((uint8*) &obj, (1 * sizeof(obj)), (HANDLE) fp) < sizeof(obj)) {             /* オブジェクト 取得 */
            return -1;
        }

        if (strncmp(obj.Guid, metalibid, 16) == 0) {
            if ((int) FileSeek(pos, SEEK_SET, (HANDLE) fp) != 0) {
                return -1;
            }
            num = sizeof(ASF_HEADER) + sizeof(short);
            if (FileRead((uint8*) &metalibobj, (1 * num), (HANDLE) fp) < num) {             /* MetaData Library Object 取得 */
                return -1;
            }

            if (metalibobj.MetaNum == 0) {  /* Not exist Metadata */
                return -1;
            }

            for (i = 0; i < metalibobj.MetaNum; i++) {
                num = (sizeof(short) * 4) + sizeof(int);
                if (FileRead((uint8*) &metalibobj.Rec, (1 * num), (HANDLE) fp) < num) {             /* Record 取得 */
                    return -1;
                }
                /* WM/Picture(2byte char + null)の検索なので24文字以上のものはSkip */
                if (23 < metalibobj.Rec.NameLength) {
                    (int) FileSeek(metalibobj.Rec.NameLength, SEEK_CUR, (HANDLE) fp);
                } else {
                    if (FileRead((uint8*) &metalibobj.Rec.Name, (1 * metalibobj.Rec.NameLength), (HANDLE) fp) < metalibobj.Rec.NameLength) {             /* Name Length 取得 */
                        return -1;
                    }
                }

                j = 0;
                for (num = 0; num < metalibobj.Rec.NameLength; num++) { /* Compare str "WM/Picture" */
                    if ((metalibobj.Rec.Name[num] - wmbuf[num]) != 0) { /* Wrong Charactor */
                        j = 1;
                        break;
                    }
                }
                if (j == 0) {
                    parsewmpic(fp);
                    res = 0;
                    break;
                }else {
                    (int) FileSeek(metalibobj.Rec.DataLength, SEEK_CUR, (HANDLE) fp);
                }
/*
                if (strncmp(metalibobj.Rec.Name, wmbuf, 22) == 0) {
                    parsewmpic(fp);
                    res = 0;
                    break;
                }
*/
            }
        }
        if (res == 0) {
            break;
        }
        (int) FileSeek(pos, SEEK_SET, (HANDLE) fp);
        (int) FileSeek(*obj.Size, SEEK_CUR, (HANDLE) fp);
    }


    return res;
}


static int parseExtConDesObj(FILE *fp)
{
    int     res = -1;
    int     num = 0, offset = 0;
    int     i = 0, j = 0;
    long    pos = 0, size = 0;
    char    wmbuf[23] = { 0x57, 0x00, 0x4D, 0x00, 0x2F, 0x00, 0x50, 0x00, 0x69
        , 0x00, 0x63, 0x00, 0x74, 0x00, 0x75, 0x00, 0x72, 0x00, 0x65, 0x00, 0x00, 0x00 };
    EXTDES_OBJECT   extdesobj;
    EXTDES_RECORD   extdesrec;
    memset(&extdesobj, 0, sizeof(EXTDES_OBJECT));
    memset(&extdesrec, 0, sizeof(EXTDES_RECORD));


    if (FileRead((uint8*) &extdesobj, (1 * (sizeof(EXTDES_OBJECT))), (HANDLE) fp) < sizeof(EXTDES_OBJECT)) {             /* Extend Content Description Object Header 取得 */
        return -1;
    }

    if (extdesobj.MetaNum == 0) {       /* not exist metadata */
        return -1;
    }



    (int) FileSeek(-2, SEEK_CUR, (HANDLE) fp);


    for (i = 0; i < extdesobj.MetaNum; i++) {

        if (FileRead((uint8*) &extdesrec.NameLength, (1 * sizeof(short)), (HANDLE) fp) < sizeof(short)) {             /* Name Length 取得 */
            return -1;
        }

        /* WM/Picture(2byte char + null)の検索なので24文字以上のものはSkip */
        if (23 < extdesrec.NameLength) {
            (int) FileSeek(extdesrec.NameLength, SEEK_CUR, (HANDLE) fp);
        } else {
            if (FileRead((uint8*) &extdesrec.Name, (1 * extdesrec.NameLength), (HANDLE) fp) < extdesrec.NameLength) {             /* Name 取得 */
                return -1;
            }
        }

        if (FileRead((uint8*) &extdesrec.DataType, (2 * sizeof(short)), (HANDLE) fp) < (2 * sizeof(short))) {               /* DataType & DataLength 取得 */
            return -1;
        }

        j = 0;
        for (num = 0; num < extdesrec.NameLength; num++) {      /* Compare str "WM/Picture" */
            if ((extdesrec.Name[num] - wmbuf[num]) != 0) {
                j = 1;                                          /* Wrong Charactor */
                break;
            }
        }
        if (j == 0) {
            parsewmpic(fp);
            res = 0;
            break;
        }

        (int) FileSeek(extdesrec.DataLength, SEEK_CUR, (HANDLE) fp);
    }

    return res;
}

/*************************************************/
/*  ID3 解析                                   */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int parsewmpic(FILE *fp)
{
    int     sum = -1, picsize = 0,pos = 0;
    char    pictype = 0, mine[2];
    memset(mine, 0, 2);


    if (FileRead((uint8*) &pictype, (1 * sizeof(char)), (HANDLE) fp) < sizeof(char)) {             /* Picture Type 取得 */
        return -1;
    }
//  if ((int) FileSeek(1, SEEK_CUR, (HANDLE) fp) != 0) {             /* NULL */
//      return -1;
//  }
    if (FileRead((uint8*) &picsize, (1 * sizeof(int)), (HANDLE) fp) < sizeof(int)) {             /* Picture Size 取得 */
        return -1;
    }


    while (sum != 0) {
        if (FileRead((uint8*) &mine, (2 * sizeof(char)), (HANDLE) fp) < (2 * sizeof(char))) {             /* Mine Type 取得 */
            return -1;
        }
        sum = mine[0] | mine[1];
        ThumbType[pos] = sum;
        pos++;
    }


    sum = -1;
    while (sum != 0) {
        if (FileRead((uint8*) &mine, (2 * sizeof(char)), (HANDLE) fp) < (2 * sizeof(char))) {             /* Mine Path 取得 */
            return -1;
        }
        sum = mine[0] | mine[1];
    }


    ThumbData.PicStart = (long)FileTell((HANDLE)(fp));
    ThumbData.PicSize =  (long)picsize;

    return 0;
}

/*************************************************/
/*  ID3 解析                                   */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int seektoExtObj(FILE *fp, int objnum)
{
    int     res = -1;
    int     pos = 0, num = 0;
    char    extobjguid[17] = {0xB5, 0x03, 0xBF, 0x5F, 0x2E, 0xA9, 0xCF, 0x11, 0x8E, 0xE3, 0x00, 0xC0, 0x0C, 0x20, 0x53, 0x65 }; /* 5FBF03B5-A92E-11CF-8EE3-00C00C205365 */
    ASF_HEADER obj;
    memset(&obj, 0, sizeof(ASF_HEADER));


    while (num < objnum) {
        pos = FileTell((HANDLE)(fp));
        if (FileRead((uint8*) &obj, (1 * sizeof(obj)), (HANDLE) fp) < sizeof(obj)) {             /* Object 取得 */
            return -1;
        }

        if (strncmp(obj.Guid, extobjguid, 16) == 0) {
            if ((int) FileSeek(pos, SEEK_SET, (HANDLE) fp) != 0) {
                return -1;
            }
            res = 0;
            break;
        }
        (int) FileSeek(*obj.Size - sizeof(ASF_HEADER), SEEK_CUR, (HANDLE) fp);
        num++;
    }


    return res;
}

/*************************************************/
/*  ID3 解析                                   */
/*  引数：char *thumbfilename：ファイルネーム   */
/* 戻り値 0<:異常 0 : 異常なし                    */
/*************************************************/
static int seektoExtConDesObj(FILE *fp, int objnum)
{
    int     res = -1;
    int     pos = 0, num = 0;
    char    extcondesobjguid[17] = {0x40, 0xA4, 0xD0, 0xD2, 0x07, 0xE3, 0xD2, 0x11, 0x97, 0xF0, 0x00, 0xA0, 0xC9, 0x5E, 0xA8, 0x50 }; /* D2D0A440-E307-11D2-97F0-00A0C95EA850 */
    ASF_HEADER obj;
    memset(&obj, 0, sizeof(ASF_HEADER));


    while (num < objnum) {
        pos = FileTell((HANDLE)(fp));
        if (FileRead((uint8*) &obj, (1 * sizeof(obj)), (HANDLE) fp) < sizeof(obj)) {             /* Object 取得 */
            return -1;
        }

        if (strncmp(obj.Guid, extcondesobjguid, 16) == 0) {
            if ((int) FileSeek(pos, SEEK_SET, (HANDLE) fp) != 0) {
                return -1;
            }
            res = 0;
            break;
        }
        (int) FileSeek(*obj.Size - sizeof(ASF_HEADER), SEEK_CUR, (HANDLE) fp);
        num++;
    }


    return res;
}

/* ********************************** */
/* カーソル位置移動                   */
/* 引数：*fp:ファイルディスクリプタ     */
/*          ofs：移動量               */
/* ********************************** */
static int seekToRelativeOffset(FILE *fp, unsigned int ofs)
{
    return (int) FileSeek(ofs + 1 , SEEK_CUR, (HANDLE) fp);
}

static unsigned short Lit2Big16bit(unsigned short us)                               /* Little → Big Endian 16bit */
{
    return (us << 8) | ((us >> 8) & 0x00FF);
}


static unsigned int Lit2Big32bit(unsigned int ui)                                   /* Little → Big Endian 32bit */
{
    return
        ((ui << 24) & 0xFF000000) | ((ui << 8) & 0x00FF0000) |
        ((ui >> 8) & 0x0000FF00) | ((ui >> 24) & 0x000000FF);
}

/* ---------------------------------------------------------------------------------------------- */
/*  外部I/F関数                                                                                  */
/* ---------------------------------------------------------------------------------------------- */
void Thumbnail_Task_SetFileName(char *buf[])
{
    Thumb_FileName = buf[0];
}

void Thumbnail_Task_SetFilePointer(FILE *fp)
{
    Thumb_FilePointer = fp;
}


PIC_DATA *Thumbnail_Task_GetPictureData(void)
{
    return &ThumbData;
}

long Thumbnail_Task_GetThumbnailOffset(void)
{
    return ThumbData.PicStart;
}

long Thumbnail_Task_GetThumbnailSize(void)
{
    return ThumbData.PicSize;
}

int Thumbnail_Task_GetPictureType(void)
{
    int res = 0;
    if (strncmp(ThumbType, "image/jpeg", 10) == 0) {
        res = PIC_JPEG;
                DEBUG("=====The album cover is JPEG format=====\n");
    } else if (strncmp(ThumbType, "image/jpg", 9) == 0) {
        res = PIC_JPG;
                DEBUG("=====The album cover is JPG format=====\n");
    } else if (strncmp(ThumbType, "JPG", 3) == 0) {
        res = PIC_JPG;
                DEBUG("=====The album cover is JPG format=====\n");
    } else if (strncmp(ThumbType, "image/peg", 9) == 0) {
        res = PIC_PEG;
                DEBUG("=====The album cover is PEG format=====\n");
    } else if (strncmp(ThumbType, "image/bmp", 9) == 0) {
        res = PIC_BMP;
                DEBUG("=====The album cover is BMP format=====\n");
    } else {
        res = -1;
    }

    return res;
}

#endif

