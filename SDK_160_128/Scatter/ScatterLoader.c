/*
********************************************************************************
*                   Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*                         All rights reserved.
*
* File Name：   StartLoadTab.c
*
* Description:  定义模块信息，在模块调度时需要使用
*
* History:      <author>          <time>        <version>
*             ZhengYongzhi      2009-02-06         1.0
*    desc:    ORG.
********************************************************************************
*/
#define _IN_STARTLOAD_

#include "SysInclude.h"

extern uint32 Load$$MODULE_INFO$$Base;

//SysCode
extern uint32  Load$$SYS_CODE$$Base;
extern uint32 Image$$SYS_CODE$$Base;
extern uint32 Image$$SYS_CODE$$Length;
extern uint32  Load$$SYS_DATA$$Base;
extern uint32 Image$$SYS_DATA$$RW$$Base;
extern uint32 Image$$SYS_DATA$$RW$$Length;
extern uint32 Image$$SYS_DATA$$ZI$$Base;
extern uint32 Image$$SYS_DATA$$ZI$$Length;

extern uint32  Load$$SYS_INIT_CODE$$Base;
extern uint32 Image$$SYS_INIT_CODE$$Base;
extern uint32 Image$$SYS_INIT_CODE$$Length;
extern uint32  Load$$SYS_INIT_DATA$$Base;
extern uint32 Image$$SYS_INIT_DATA$$RW$$Base;
extern uint32 Image$$SYS_INIT_DATA$$RW$$Length;
extern uint32 Image$$SYS_INIT_DATA$$ZI$$Base;
extern uint32 Image$$SYS_INIT_DATA$$ZI$$Length;


extern uint32 Load$$LCD_DRIVER1_CODE$$Base;
extern uint32 Image$$LCD_DRIVER1_CODE$$Base;
extern uint32 Image$$LCD_DRIVER1_CODE$$Length;
extern uint32 Load$$LCD_DRIVER1_DATA$$Base;
extern uint32 Image$$LCD_DRIVER1_DATA$$RW$$Base;
extern uint32 Image$$LCD_DRIVER1_DATA$$RW$$Length;
extern uint32 Image$$LCD_DRIVER1_DATA$$ZI$$Base;
extern uint32 Image$$LCD_DRIVER1_DATA$$ZI$$Length;

extern uint32 Load$$LCD_DRIVER2_CODE$$Base;
extern uint32 Image$$LCD_DRIVER2_CODE$$Base;
extern uint32 Image$$LCD_DRIVER2_CODE$$Length;
extern uint32 Load$$LCD_DRIVER2_DATA$$Base;
extern uint32 Image$$LCD_DRIVER2_DATA$$RW$$Base;
extern uint32 Image$$LCD_DRIVER2_DATA$$RW$$Length;
extern uint32 Image$$LCD_DRIVER2_DATA$$ZI$$Base;
extern uint32 Image$$LCD_DRIVER2_DATA$$ZI$$Length;

//#ifdef _MEDIA_MODULE_
//fileinfosave
extern uint32  Load$$FILE_INFO_SAVE_CODE$$Base;
extern uint32 Image$$FILE_INFO_SAVE_CODE$$Base;
extern uint32 Image$$FILE_INFO_SAVE_CODE$$Length;
extern uint32  Load$$FILE_INFO_SAVE_DATA$$Base;
extern uint32 Image$$FILE_INFO_SAVE_DATA$$RW$$Base;
extern uint32 Image$$FILE_INFO_SAVE_DATA$$RW$$Length;
extern uint32 Image$$FILE_INFO_SAVE_DATA$$ZI$$Base;
extern uint32 Image$$FILE_INFO_SAVE_DATA$$ZI$$Length;

//fileinfosort
extern uint32  Load$$FILE_INFO_SORT_CODE$$Base;
extern uint32 Image$$FILE_INFO_SORT_CODE$$Base;
extern uint32 Image$$FILE_INFO_SORT_CODE$$Length;
extern uint32  Load$$FILE_INFO_SORT_DATA$$Base;
extern uint32 Image$$FILE_INFO_SORT_DATA$$RW$$Base;
extern uint32 Image$$FILE_INFO_SORT_DATA$$RW$$Length;
extern uint32 Image$$FILE_INFO_SORT_DATA$$ZI$$Base;
extern uint32 Image$$FILE_INFO_SORT_DATA$$ZI$$Length;

//FavoReset
extern uint32  Load$$FAVORESET_CODE$$Base;
extern uint32 Image$$FAVORESET_CODE$$Base;
extern uint32 Image$$FAVORESET_CODE$$Length;
extern uint32  Load$$FAVORESET_DATA$$Base;
extern uint32 Image$$FAVORESET_DATA$$RW$$Base;
extern uint32 Image$$FAVORESET_DATA$$RW$$Length;
extern uint32 Image$$FAVORESET_DATA$$ZI$$Base;
extern uint32 Image$$FAVORESET_DATA$$ZI$$Length;

//#ifdef _MEDIA_MODULE_
//媒体库
extern uint32  Load$$MEDIALIBWIN_CODE$$Base;
extern uint32 Image$$MEDIALIBWIN_CODE$$Base;
extern uint32 Image$$MEDIALIBWIN_CODE$$Length;
extern uint32  Load$$MEDIALIBWIN_DATA$$Base;
extern uint32 Image$$MEDIALIBWIN_DATA$$RW$$Base;
extern uint32 Image$$MEDIALIBWIN_DATA$$RW$$Length;
extern uint32 Image$$MEDIALIBWIN_DATA$$ZI$$Base;
extern uint32 Image$$MEDIALIBWIN_DATA$$ZI$$Length;

//媒体库mediabro
extern uint32  Load$$MEDIABROWIN_CODE$$Base;
extern uint32 Image$$MEDIABROWIN_CODE$$Base;
extern uint32 Image$$MEDIABROWIN_CODE$$Length;
extern uint32  Load$$MEDIABROWIN_DATA$$Base;
extern uint32 Image$$MEDIABROWIN_DATA$$RW$$Base;
extern uint32 Image$$MEDIABROWIN_DATA$$RW$$Length;
extern uint32 Image$$MEDIABROWIN_DATA$$ZI$$Base;
extern uint32 Image$$MEDIABROWIN_DATA$$ZI$$Length;

extern uint32  Load$$MEDIABROSUBWIN_CODE$$Base;
extern uint32 Image$$MEDIABROSUBWIN_CODE$$Base;
extern uint32 Image$$MEDIABROSUBWIN_CODE$$Length;
extern uint32  Load$$MEDIABROSUBWIN_DATA$$Base;
extern uint32 Image$$MEDIABROSUBWIN_DATA$$RW$$Base;
extern uint32 Image$$MEDIABROSUBWIN_DATA$$RW$$Length;
extern uint32 Image$$MEDIABROSUBWIN_DATA$$ZI$$Base;
extern uint32 Image$$MEDIABROSUBWIN_DATA$$ZI$$Length;

extern uint32  Load$$MEDIAFAVOSUBWIN_CODE$$Base;
extern uint32 Image$$MEDIAFAVOSUBWIN_CODE$$Base;
extern uint32 Image$$MEDIAFAVOSUBWIN_CODE$$Length;
extern uint32  Load$$MEDIAFAVOSUBWIN_DATA$$Base;
extern uint32 Image$$MEDIAFAVOSUBWIN_DATA$$RW$$Base;
extern uint32 Image$$MEDIAFAVOSUBWIN_DATA$$RW$$Length;
extern uint32 Image$$MEDIAFAVOSUBWIN_DATA$$ZI$$Base;
extern uint32 Image$$MEDIAFAVOSUBWIN_DATA$$ZI$$Length;


//媒体库SVC
extern uint32  Load$$MEDIABRO_SORTGET_CODE$$Base;
extern uint32 Image$$MEDIABRO_SORTGET_CODE$$Base;
extern uint32 Image$$MEDIABRO_SORTGET_CODE$$Length;
extern uint32  Load$$MEDIABRO_SORTGET_DATA$$Base;
extern uint32 Image$$MEDIABRO_SORTGET_DATA$$RW$$Base;
extern uint32 Image$$MEDIABRO_SORTGET_DATA$$RW$$Length;
extern uint32 Image$$MEDIABRO_SORTGET_DATA$$ZI$$Base;
extern uint32 Image$$MEDIABRO_SORTGET_DATA$$ZI$$Length;

//USB Window UI code & data
extern uint32 Load$$USBWIN_CODE$$Base;
extern uint32 Image$$USBWIN_CODE$$Base;
extern uint32 Image$$USBWIN_CODE$$Length;
extern uint32 Load$$USBWIN_DATA$$Base;
extern uint32 Image$$USBWIN_DATA$$RW$$Base;
extern uint32 Image$$USBWIN_DATA$$RW$$Length;
extern uint32 Image$$USBWIN_DATA$$ZI$$Base;
extern uint32 Image$$USBWIN_DATA$$ZI$$Length;

//USB Control & driver code & data
extern uint32 Load$$USBCONTROL_CODE$$Base;
extern uint32 Image$$USBCONTROL_CODE$$Base;
extern uint32 Image$$USBCONTROL_CODE$$Length;
extern uint32 Load$$USBCONTROL_DATA$$Base;
extern uint32 Image$$USBCONTROL_DATA$$RW$$Base;
extern uint32 Image$$USBCONTROL_DATA$$RW$$Length;
extern uint32 Image$$USBCONTROL_DATA$$ZI$$Base;
extern uint32 Image$$USBCONTROL_DATA$$ZI$$Length;

//USB MSC code & data
extern uint32 Load$$USBMSC_CODE$$Base;
extern uint32 Image$$USBMSC_CODE$$Base;
extern uint32 Image$$USBMSC_CODE$$Length;
extern uint32 Load$$USBMSC_DATA$$Base;
extern uint32 Image$$USBMSC_DATA$$RW$$Base;
extern uint32 Image$$USBMSC_DATA$$RW$$Length;
extern uint32 Image$$USBMSC_DATA$$ZI$$Base;
extern uint32 Image$$USBMSC_DATA$$ZI$$Length;

//Audio Decode
extern uint32  Load$$AUDIO_CONTROL_CODE$$Base;
extern uint32 Image$$AUDIO_CONTROL_CODE$$Base;
extern uint32 Image$$AUDIO_CONTROL_CODE$$Length;
extern uint32  Load$$AUDIO_CONTROL_DATA$$Base;
extern uint32 Image$$AUDIO_CONTROL_DATA$$RW$$Base;
extern uint32 Image$$AUDIO_CONTROL_DATA$$RW$$Length;
extern uint32 Image$$AUDIO_CONTROL_DATA$$ZI$$Base;
extern uint32 Image$$AUDIO_CONTROL_DATA$$ZI$$Length;

//Audio Decode
extern uint32  Load$$AUDIO_CONTROL_INIT_CODE$$Base;
extern uint32 Image$$AUDIO_CONTROL_INIT_CODE$$Base;
extern uint32 Image$$AUDIO_CONTROL_INIT_CODE$$Length;
extern uint32  Load$$AUDIO_CONTROL_INIT_DATA$$Base;
extern uint32 Image$$AUDIO_CONTROL_INIT_DATA$$RW$$Base;
extern uint32 Image$$AUDIO_CONTROL_INIT_DATA$$RW$$Length;
extern uint32 Image$$AUDIO_CONTROL_INIT_DATA$$ZI$$Base;
extern uint32 Image$$AUDIO_CONTROL_INIT_DATA$$ZI$$Length;

//Audio RKEq
extern uint32  Load$$AUDIO_RKEQ_CODE$$Base;
extern uint32 Image$$AUDIO_RKEQ_CODE$$Base;
extern uint32 Image$$AUDIO_RKEQ_CODE$$Length;
extern uint32  Load$$AUDIO_RKEQ_DATA$$Base;
extern uint32 Image$$AUDIO_RKEQ_DATA$$RW$$Base;
extern uint32 Image$$AUDIO_RKEQ_DATA$$RW$$Length;
extern uint32 Image$$AUDIO_RKEQ_DATA$$ZI$$Base;
extern uint32 Image$$AUDIO_RKEQ_DATA$$ZI$$Length;

//Audio EQ
extern uint32  Load$$AUDIO_EQ_CODE$$Base;
extern uint32 Image$$AUDIO_EQ_CODE$$Base;
extern uint32 Image$$AUDIO_EQ_CODE$$Length;
extern uint32  Load$$AUDIO_EQ_DATA$$Base;
extern uint32 Image$$AUDIO_EQ_DATA$$RW$$Base;
extern uint32 Image$$AUDIO_EQ_DATA$$RW$$Length;
extern uint32 Image$$AUDIO_EQ_DATA$$ZI$$Base;
extern uint32 Image$$AUDIO_EQ_DATA$$ZI$$Length;

extern uint32  Load$$AUDIO_ID3_CODE$$Base;
extern uint32 Image$$AUDIO_ID3_CODE$$Base;
extern uint32 Image$$AUDIO_ID3_CODE$$Length;
extern uint32  Load$$AUDIO_ID3_DATA$$Base;
extern uint32 Image$$AUDIO_ID3_DATA$$RW$$Base;
extern uint32 Image$$AUDIO_ID3_DATA$$RW$$Length;
extern uint32 Image$$AUDIO_ID3_DATA$$ZI$$Base;
extern uint32 Image$$AUDIO_ID3_DATA$$ZI$$Length;


//MP3
extern uint32  Load$$MP3_DECODE_CODE$$Base;
extern uint32 Image$$MP3_DECODE_CODE$$Base;
extern uint32 Image$$MP3_DECODE_CODE$$Length;
extern uint32  Load$$MP3_DECODE_DATA$$Base;
extern uint32 Image$$MP3_DECODE_DATA$$RW$$Base;
extern uint32 Image$$MP3_DECODE_DATA$$RW$$Length;
extern uint32 Image$$MP3_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$MP3_DECODE_DATA$$ZI$$Length;

//AAC
extern uint32  Load$$AAC_DECODE_CODE$$Base;
extern uint32 Image$$AAC_DECODE_CODE$$Base;
extern uint32 Image$$AAC_DECODE_CODE$$Length;
extern uint32  Load$$AAC_DECODE_DATA$$Base;
extern uint32 Image$$AAC_DECODE_DATA$$RW$$Base;
extern uint32 Image$$AAC_DECODE_DATA$$RW$$Length;
extern uint32 Image$$AAC_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$AAC_DECODE_DATA$$ZI$$Length;


//WAV
extern uint32  Load$$WAV_DECODE_CODE$$Base;
extern uint32 Image$$WAV_DECODE_CODE$$Base;
extern uint32 Image$$WAV_DECODE_CODE$$Length;
extern uint32  Load$$WAV_DECODE_DATA$$Base;
extern uint32 Image$$WAV_DECODE_DATA$$RW$$Base;
extern uint32 Image$$WAV_DECODE_DATA$$RW$$Length;
extern uint32 Image$$WAV_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$WAV_DECODE_DATA$$ZI$$Length;

//OGG
extern uint32  Load$$OGG_DECODE_CODE$$Base;
extern uint32 Image$$OGG_DECODE_CODE$$Base;
extern uint32 Image$$OGG_DECODE_CODE$$Length;
extern uint32  Load$$OGG_DECODE_DATA$$Base;
extern uint32 Image$$OGG_DECODE_DATA$$RW$$Base;
extern uint32 Image$$OGG_DECODE_DATA$$RW$$Length;
extern uint32 Image$$OGG_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$OGG_DECODE_DATA$$ZI$$Length;

//HFLAC
extern uint32  Load$$FLAC_HDECODE_CODE$$Base;
extern uint32 Image$$FLAC_HDECODE_CODE$$Base;
extern uint32 Image$$FLAC_HDECODE_CODE$$Length;
extern uint32  Load$$FLAC_HDECODE_DATA$$Base;
extern uint32 Image$$FLAC_HDECODE_DATA$$RW$$Base;
extern uint32 Image$$FLAC_HDECODE_DATA$$RW$$Length;
extern uint32 Image$$FLAC_HDECODE_DATA$$ZI$$Base;
extern uint32 Image$$FLAC_HDECODE_DATA$$ZI$$Length;

//HALAC
extern uint32  Load$$ALAC_HDECODE_CODE$$Base;
extern uint32 Image$$ALAC_HDECODE_CODE$$Base;
extern uint32 Image$$ALAC_HDECODE_CODE$$Length;
extern uint32  Load$$ALAC_HDECODE_DATA$$Base;
extern uint32 Image$$ALAC_HDECODE_DATA$$RW$$Base;
extern uint32 Image$$ALAC_HDECODE_DATA$$RW$$Length;
extern uint32 Image$$ALAC_HDECODE_DATA$$ZI$$Base;
extern uint32 Image$$ALAC_HDECODE_DATA$$ZI$$Length;

//HAPE
extern uint32  Load$$APE_HDECODE_CODE$$Base;
extern uint32 Image$$APE_HDECODE_CODE$$Base;
extern uint32 Image$$APE_HDECODE_CODE$$Length;
extern uint32  Load$$APE_HDECODE_DATA$$Base;
extern uint32 Image$$APE_HDECODE_DATA$$RW$$Base;
extern uint32 Image$$APE_HDECODE_DATA$$RW$$Length;
extern uint32 Image$$APE_HDECODE_DATA$$ZI$$Base;
extern uint32 Image$$APE_HDECODE_DATA$$ZI$$Length;

//DSD
extern uint32  Load$$DSDIFF_DECODE_CODE$$Base;
extern uint32 Image$$DSDIFF_DECODE_CODE$$Base;
extern uint32 Image$$DSDIFF_DECODE_CODE$$Length;
extern uint32  Load$$DSDIFF_DECODE_DATA$$Base;
extern uint32 Image$$DSDIFF_DECODE_DATA$$RW$$Base;
extern uint32 Image$$DSDIFF_DECODE_DATA$$RW$$Length;
extern uint32 Image$$DSDIFF_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$DSDIFF_DECODE_DATA$$ZI$$Length;

//DSF
extern uint32  Load$$DSF_DECODE_CODE$$Base;
extern uint32 Image$$DSF_DECODE_CODE$$Base;
extern uint32 Image$$DSF_DECODE_CODE$$Length;
extern uint32  Load$$DSF_DECODE_DATA$$Base;
extern uint32 Image$$DSF_DECODE_DATA$$RW$$Base;
extern uint32 Image$$DSF_DECODE_DATA$$RW$$Length;
extern uint32 Image$$DSF_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$DSF_DECODE_DATA$$ZI$$Length;

//Audio Encode
extern uint32  Load$$ENCODE_CODE$$Base;
extern uint32 Image$$ENCODE_CODE$$Base;
extern uint32 Image$$ENCODE_CODE$$Length;
extern uint32  Load$$ENCODE_DATA$$Base;
extern uint32 Image$$ENCODE_DATA$$RW$$Base;
extern uint32 Image$$ENCODE_DATA$$RW$$Length;
extern uint32 Image$$ENCODE_DATA$$ZI$$Base;
extern uint32 Image$$ENCODE_DATA$$ZI$$Length;

//Encode MSADPCM
extern uint32  Load$$ENCODE_MSADPCM_CODE$$Base;
extern uint32 Image$$ENCODE_MSADPCM_CODE$$Base;
extern uint32 Image$$ENCODE_MSADPCM_CODE$$Length;
extern uint32  Load$$ENCODE_MSADPCM_DATA$$Base;
extern uint32 Image$$ENCODE_MSADPCM_DATA$$RW$$Base;
extern uint32 Image$$ENCODE_MSADPCM_DATA$$RW$$Length;
extern uint32 Image$$ENCODE_MSADPCM_DATA$$ZI$$Base;
extern uint32 Image$$ENCODE_MSADPCM_DATA$$ZI$$Length;

//RecordControl
extern uint32  Load$$RECORD_CONTROL_CODE$$Base;
extern uint32 Image$$RECORD_CONTROL_CODE$$Base;
extern uint32 Image$$RECORD_CONTROL_CODE$$Length;
extern uint32  Load$$RECORD_CONTROL_DATA$$Base;
extern uint32 Image$$RECORD_CONTROL_DATA$$RW$$Base;
extern uint32 Image$$RECORD_CONTROL_DATA$$RW$$Length;
extern uint32 Image$$RECORD_CONTROL_DATA$$ZI$$Base;
extern uint32 Image$$RECORD_CONTROL_DATA$$ZI$$Length;

//UI MainMenu
extern uint32  Load$$MAINMENU_CODE$$Base;
extern uint32 Image$$MAINMENU_CODE$$Base;
extern uint32 Image$$MAINMENU_CODE$$Length;
extern uint32  Load$$MAINMENU_DATA$$Base;
extern uint32 Image$$MAINMENU_DATA$$RW$$Base;
extern uint32 Image$$MAINMENU_DATA$$RW$$Length;
extern uint32 Image$$MAINMENU_DATA$$ZI$$Base;
extern uint32 Image$$MAINMENU_DATA$$ZI$$Length;

//UI Music
extern uint32  Load$$MUSICWIN_CODE$$Base;
extern uint32 Image$$MUSICWIN_CODE$$Base;
extern uint32 Image$$MUSICWIN_CODE$$Length;
extern uint32  Load$$MUSICWIN_DATA$$Base;
extern uint32 Image$$MUSICWIN_DATA$$RW$$Base;
extern uint32 Image$$MUSICWIN_DATA$$RW$$Length;
extern uint32 Image$$MUSICWIN_DATA$$ZI$$Base;
extern uint32 Image$$MUSICWIN_DATA$$ZI$$Length;

//UI Video
extern uint32  Load$$VIDEOWIN_CODE$$Base;
extern uint32 Image$$VIDEOWIN_CODE$$Base;
extern uint32 Image$$VIDEOWIN_CODE$$Length;
extern uint32  Load$$VIDEOWIN_DATA$$Base;
extern uint32 Image$$VIDEOWIN_DATA$$RW$$Base;
extern uint32 Image$$VIDEOWIN_DATA$$RW$$Length;
extern uint32 Image$$VIDEOWIN_DATA$$ZI$$Base;
extern uint32 Image$$VIDEOWIN_DATA$$ZI$$Length;

//videocontrol
extern uint32 Load$$VIDEO_CONTROL_CODE$$Base;
extern uint32 Image$$VIDEO_CONTROL_CODE$$Base;
extern uint32 Image$$VIDEO_CONTROL_CODE$$Length;
extern uint32 Load$$VIDEO_CONTROL_DATA$$Base;
extern uint32 Image$$VIDEO_CONTROL_DATA$$RW$$Base;
extern uint32 Image$$VIDEO_CONTROL_DATA$$RW$$Length;
extern uint32 Image$$VIDEO_CONTROL_DATA$$ZI$$Base;
extern uint32 Image$$VIDEO_CONTROL_DATA$$ZI$$Length;

// VIDEO_MP2
extern uint32  Load$$MP2_DECODE_CODE$$Base;
extern uint32 Image$$MP2_DECODE_CODE$$Base;
extern uint32 Image$$MP2_DECODE_CODE$$Length;
extern uint32  Load$$MP2_DECODE_DATA$$Base;
extern uint32 Image$$MP2_DECODE_DATA$$RW$$Base;
extern uint32 Image$$MP2_DECODE_DATA$$RW$$Length;
extern uint32 Image$$MP2_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$MP2_DECODE_DATA$$ZI$$Length;

//AVI
extern uint32  Load$$AVI_DECODE_CODE$$Base;
extern uint32 Image$$AVI_DECODE_CODE$$Base;
extern uint32 Image$$AVI_DECODE_CODE$$Length;
extern uint32  Load$$AVI_DECODE_DATA$$Base;
extern uint32 Image$$AVI_DECODE_DATA$$RW$$Base;
extern uint32 Image$$AVI_DECODE_DATA$$RW$$Length;
extern uint32 Image$$AVI_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$AVI_DECODE_DATA$$ZI$$Length;

//Radio
extern uint32  Load$$RADIOWIN_CODE$$Base;
extern uint32 Image$$RADIOWIN_CODE$$Base;
extern uint32 Image$$RADIOWIN_CODE$$Length;
extern uint32  Load$$RADIOWIN_DATA$$Base;
extern uint32 Image$$RADIOWIN_DATA$$RW$$Base;
extern uint32 Image$$RADIOWIN_DATA$$RW$$Length;
extern uint32 Image$$RADIOWIN_DATA$$ZI$$Base;
extern uint32 Image$$RADIOWIN_DATA$$ZI$$Length;

//Picture
extern uint32  Load$$PICWIN_CODE$$Base;
extern uint32 Image$$PICWIN_CODE$$Base;
extern uint32 Image$$PICWIN_CODE$$Length;
extern uint32  Load$$PICWIN_DATA$$Base;
extern uint32 Image$$PICWIN_DATA$$RW$$Base;
extern uint32 Image$$PICWIN_DATA$$RW$$Length;
extern uint32 Image$$PICWIN_DATA$$ZI$$Base;
extern uint32 Image$$PICWIN_DATA$$ZI$$Length;
//Picture 进程
extern uint32  Load$$IMAGE_CONTROL_CODE$$Base;
extern uint32 Image$$IMAGE_CONTROL_CODE$$Base;
extern uint32 Image$$IMAGE_CONTROL_CODE$$Length;
extern uint32  Load$$IMAGE_CONTROL_DATA$$Base;
extern uint32 Image$$IMAGE_CONTROL_DATA$$RW$$Base;
extern uint32 Image$$IMAGE_CONTROL_DATA$$RW$$Length;
extern uint32 Image$$IMAGE_CONTROL_DATA$$ZI$$Base;
extern uint32 Image$$IMAGE_CONTROL_DATA$$ZI$$Length;
//JPG
extern uint32  Load$$JPG_DECODE_CODE$$Base;
extern uint32 Image$$JPG_DECODE_CODE$$Base;
extern uint32 Image$$JPG_DECODE_CODE$$Length;
extern uint32  Load$$JPG_DECODE_DATA$$Base;
extern uint32 Image$$JPG_DECODE_DATA$$RW$$Base;
extern uint32 Image$$JPG_DECODE_DATA$$RW$$Length;
extern uint32 Image$$JPG_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$JPG_DECODE_DATA$$ZI$$Length;

//BMP
extern uint32  Load$$BMP_DECODE_CODE$$Base;
extern uint32 Image$$BMP_DECODE_CODE$$Base;
extern uint32 Image$$BMP_DECODE_CODE$$Length;
extern uint32  Load$$BMP_DECODE_DATA$$Base;
extern uint32 Image$$BMP_DECODE_DATA$$RW$$Base;
extern uint32 Image$$BMP_DECODE_DATA$$RW$$Length;
extern uint32 Image$$BMP_DECODE_DATA$$ZI$$Base;
extern uint32 Image$$BMP_DECODE_DATA$$ZI$$Length;

//FM
extern uint32 Load$$FM_CONTROL_CODE$$Base;
extern uint32 Image$$FM_CONTROL_CODE$$Base;
extern uint32 Image$$FM_CONTROL_CODE$$Length;
extern uint32 Load$$FM_CONTROL_DATA$$Base;
extern uint32 Image$$FM_CONTROL_DATA$$RW$$Base;
extern uint32 Image$$FM_CONTROL_DATA$$RW$$Length;
extern uint32 Image$$FM_CONTROL_DATA$$ZI$$Base;
extern uint32 Image$$FM_CONTROL_DATA$$ZI$$Length;

// FM DRIVER
extern uint32 Load$$FM_DRIVER1_CODE$$Base;
extern uint32 Image$$FM_DRIVER1_CODE$$Base;
extern uint32 Image$$FM_DRIVER1_CODE$$Length;
extern uint32 Load$$FM_DRIVER1_DATA$$Base;
extern uint32 Image$$FM_DRIVER1_DATA$$RW$$Base;
extern uint32 Image$$FM_DRIVER1_DATA$$RW$$Length;
extern uint32 Image$$FM_DRIVER1_DATA$$ZI$$Base;
extern uint32 Image$$FM_DRIVER1_DATA$$ZI$$Length;

extern uint32 Load$$FM_DRIVER2_CODE$$Base;
extern uint32 Image$$FM_DRIVER2_CODE$$Base;
extern uint32 Image$$FM_DRIVER2_CODE$$Length;
extern uint32 Load$$FM_DRIVER2_DATA$$Base;
extern uint32 Image$$FM_DRIVER2_DATA$$RW$$Base;
extern uint32 Image$$FM_DRIVER2_DATA$$RW$$Length;
extern uint32 Image$$FM_DRIVER2_DATA$$ZI$$Base;
extern uint32 Image$$FM_DRIVER2_DATA$$ZI$$Length;


//Record
extern uint32  Load$$RECORDWIN_CODE$$Base;
extern uint32 Image$$RECORDWIN_CODE$$Base;
extern uint32 Image$$RECORDWIN_CODE$$Length;
extern uint32  Load$$RECORDWIN_DATA$$Base;
extern uint32 Image$$RECORDWIN_DATA$$RW$$Base;
extern uint32 Image$$RECORDWIN_DATA$$RW$$Length;
extern uint32 Image$$RECORDWIN_DATA$$ZI$$Base;
extern uint32 Image$$RECORDWIN_DATA$$ZI$$Length;

//Text
extern uint32  Load$$TEXTWIN_CODE$$Base;
extern uint32 Image$$TEXTWIN_CODE$$Base;
extern uint32 Image$$TEXTWIN_CODE$$Length;
extern uint32  Load$$TEXTWIN_DATA$$Base;
extern uint32 Image$$TEXTWIN_DATA$$RW$$Base;
extern uint32 Image$$TEXTWIN_DATA$$RW$$Length;
extern uint32 Image$$TEXTWIN_DATA$$ZI$$Base;
extern uint32 Image$$TEXTWIN_DATA$$ZI$$Length;

//Browser
extern uint32  Load$$BROWSER_CODE$$Base;
extern uint32 Image$$BROWSER_CODE$$Base;
extern uint32 Image$$BROWSER_CODE$$Length;
extern uint32  Load$$BROWSER_DATA$$Base;
extern uint32 Image$$BROWSER_DATA$$RW$$Base;
extern uint32 Image$$BROWSER_DATA$$RW$$Length;
extern uint32 Image$$BROWSER_DATA$$ZI$$Base;
extern uint32 Image$$BROWSER_DATA$$ZI$$Length;

//Set Menu
extern uint32  Load$$SETMENU_CODE$$Base;
extern uint32 Image$$SETMENU_CODE$$Base;
extern uint32 Image$$SETMENU_CODE$$Length;
extern uint32  Load$$SETMENU_DATA$$Base;
extern uint32 Image$$SETMENU_DATA$$RW$$Base;
extern uint32 Image$$SETMENU_DATA$$RW$$Length;
extern uint32 Image$$SETMENU_DATA$$ZI$$Base;
extern uint32 Image$$SETMENU_DATA$$ZI$$Length;

//Flash Write
extern uint32  Load$$FLASH_WRITE_CODE$$Base;
extern uint32 Image$$FLASH_WRITE_CODE$$Base;
extern uint32 Image$$FLASH_WRITE_CODE$$Length;
extern uint32  Load$$FLASH_WRITE_DATA$$Base;
extern uint32 Image$$FLASH_WRITE_DATA$$RW$$Base;
extern uint32 Image$$FLASH_WRITE_DATA$$RW$$Length;
extern uint32 Image$$FLASH_WRITE_DATA$$ZI$$Base;
extern uint32 Image$$FLASH_WRITE_DATA$$ZI$$Length;


//MDB WIN
extern uint32  Load$$MDB_WIN_CODE$$Base;
extern uint32 Image$$MDB_WIN_CODE$$Base;
extern uint32 Image$$MDB_WIN_CODE$$Length;
extern uint32  Load$$MDB_WIN_DATA$$Base;
extern uint32 Image$$MDB_WIN_DATA$$RW$$Base;
extern uint32 Image$$MDB_WIN_DATA$$RW$$Length;
extern uint32 Image$$MDB_WIN_DATA$$ZI$$Base;
extern uint32 Image$$MDB_WIN_DATA$$ZI$$Length;

//CHARGE WIN
extern uint32  Load$$CHARGE_WIN_CODE$$Base;
extern uint32 Image$$CHARGE_WIN_CODE$$Base;
extern uint32 Image$$CHARGE_WIN_CODE$$Length;
extern uint32  Load$$CHARGE_WIN_DATA$$Base;
extern uint32 Image$$CHARGE_WIN_DATA$$RW$$Base;
extern uint32 Image$$CHARGE_WIN_DATA$$RW$$Length;
extern uint32 Image$$CHARGE_WIN_DATA$$ZI$$Base;
extern uint32 Image$$CHARGE_WIN_DATA$$ZI$$Length;

//FS MEM GET
extern uint32  Load$$FS_MEM_GET_CODE$$Base;
extern uint32 Image$$FS_MEM_GET_CODE$$Base;
extern uint32 Image$$FS_MEM_GET_CODE$$Length;
extern uint32  Load$$FS_MEM_GET_DATA$$Base;
extern uint32 Image$$FS_MEM_GET_DATA$$RW$$Base;
extern uint32 Image$$FS_MEM_GET_DATA$$RW$$Length;
extern uint32 Image$$FS_MEM_GET_DATA$$ZI$$Base;
extern uint32 Image$$FS_MEM_GET_DATA$$ZI$$Length;

//Fwupgrade
extern uint32  Load$$FW_UPGRADE_CODE$$Base;
extern uint32 Image$$FW_UPGRADE_CODE$$Base;
extern uint32 Image$$FW_UPGRADE_CODE$$Length;
extern uint32  Load$$FW_UPGRADE_DATA$$Base;
extern uint32 Image$$FW_UPGRADE_DATA$$RW$$Base;
extern uint32 Image$$FW_UPGRADE_DATA$$RW$$Length;
extern uint32 Image$$FW_UPGRADE_DATA$$ZI$$Base;
extern uint32 Image$$FW_UPGRADE_DATA$$ZI$$Length;

extern uint32  Load$$CP1251_UNICODE_TABLE_CODE$$Base;
extern uint32  Image$$CP1251_UNICODE_TABLE_CODE$$Length;
extern uint32  Load$$CP932_UNICODE_TABLE_CODE$$Base;
extern uint32  Image$$CP932_UNICODE_TABLE_CODE$$Length;
extern uint32  Load$$CP932_UNICODE_TABLE1_CODE$$Base;
extern uint32  Image$$CP932_UNICODE_TABLE1_CODE$$Length;
extern uint32  Load$$CP932_UNICODE_TABLE2_CODE$$Base;
extern uint32  Image$$CP932_UNICODE_TABLE2_CODE$$Length;
extern uint32  Load$$CP950_UNICODE_TABLE_CODE$$Base;
extern uint32  Image$$CP950_UNICODE_TABLE_CODE$$Length;
extern uint32  Load$$CP949_UNICODE_TABLE_CODE$$Base;
extern uint32  Image$$CP949_UNICODE_TABLE_CODE$$Length;
extern uint32  Load$$CP949_UNICODE_TABLE1_CODE$$Base;
extern uint32  Image$$CP949_UNICODE_TABLE1_CODE$$Length;


/****************BB 核*************************/
extern uint32  Load$$BB_SYS_CODE$$Base;
extern uint32 Image$$BB_SYS_CODE$$Base;
extern uint32 Image$$BB_SYS_CODE$$Length;
extern uint32  Load$$BB_SYS_DATA$$Base;
extern uint32 Image$$BB_SYS_DATA$$RW$$Base;
extern uint32 Image$$BB_SYS_DATA$$RW$$Length;
extern uint32 Image$$BB_SYS_DATA$$ZI$$Base;
extern uint32 Image$$BB_SYS_DATA$$ZI$$Length;

//MP3
extern uint32  Load$$MP3_DECODE_BIN_CODE$$Base;
extern uint32 Image$$MP3_DECODE_BIN_CODE$$Base;
extern uint32 Image$$MP3_DECODE_BIN_CODE$$Length;
extern uint32  Load$$MP3_DECODE_BIN_DATA$$Base;
extern uint32 Image$$MP3_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$MP3_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$MP3_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$MP3_DECODE_BIN_DATA$$ZI$$Length;

//AAC
extern uint32  Load$$AAC_DECODE_BIN_CODE$$Base;
extern uint32 Image$$AAC_DECODE_BIN_CODE$$Base;
extern uint32 Image$$AAC_DECODE_BIN_CODE$$Length;
extern uint32  Load$$AAC_DECODE_BIN_DATA$$Base;
extern uint32 Image$$AAC_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$AAC_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$AAC_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$AAC_DECODE_BIN_DATA$$ZI$$Length;


//WAV
extern uint32  Load$$WAV_DECODE_BIN_CODE$$Base;
extern uint32 Image$$WAV_DECODE_BIN_CODE$$Base;
extern uint32 Image$$WAV_DECODE_BIN_CODE$$Length;
extern uint32  Load$$WAV_DECODE_BIN_DATA$$Base;
extern uint32 Image$$WAV_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$WAV_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$WAV_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$WAV_DECODE_BIN_DATA$$ZI$$Length;

//OGG
extern uint32  Load$$OGG_DECODE_BIN_CODE$$Base;
extern uint32 Image$$OGG_DECODE_BIN_CODE$$Base;
extern uint32 Image$$OGG_DECODE_BIN_CODE$$Length;
extern uint32  Load$$OGG_DECODE_BIN_DATA$$Base;
extern uint32 Image$$OGG_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$OGG_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$OGG_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$OGG_DECODE_BIN_DATA$$ZI$$Length;

//HFLAC
extern uint32  Load$$FLAC_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_CODE$$Length;
extern uint32  Load$$FLAC_HDECODE_BIN_DATA$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$FLAC_HDECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_DATA$$ZI$$Length;

//HALAC
extern uint32  Load$$ALAC_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_CODE$$Length;
extern uint32  Load$$ALAC_HDECODE_BIN_DATA$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$ALAC_HDECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_DATA$$ZI$$Length;

//HAPE
extern uint32  Load$$APE_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$APE_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$APE_HDECODE_BIN_CODE$$Length;
extern uint32  Load$$APE_HDECODE_BIN_DATA$$Base;
extern uint32 Image$$APE_HDECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$APE_HDECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$APE_HDECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$APE_HDECODE_BIN_DATA$$ZI$$Length;

//DSD
extern uint32  Load$$DSDIFF_DECODE_BIN_CODE$$Base;
extern uint32 Image$$DSDIFF_DECODE_BIN_CODE$$Base;
extern uint32 Image$$DSDIFF_DECODE_BIN_CODE$$Length;
extern uint32  Load$$DSDIFF_DECODE_BIN_DATA$$Base;
extern uint32 Image$$DSDIFF_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$DSDIFF_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$DSDIFF_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$DSDIFF_DECODE_BIN_DATA$$ZI$$Length;

//DSF
extern uint32  Load$$DSF_DECODE_BIN_CODE$$Base;
extern uint32 Image$$DSF_DECODE_BIN_CODE$$Base;
extern uint32 Image$$DSF_DECODE_BIN_CODE$$Length;
extern uint32  Load$$DSF_DECODE_BIN_DATA$$Base;
extern uint32 Image$$DSF_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$DSF_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$DSF_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$DSF_DECODE_BIN_DATA$$ZI$$Length;

//BT
extern uint32  Load$$BTCONTROL_CODE$$Base;
extern uint32 Image$$BTCONTROL_CODE$$Base;
extern uint32 Image$$BTCONTROL_CODE$$Length;
extern uint32  Load$$BTCONTROL_DATA$$Base;
extern uint32 Image$$BTCONTROL_DATA$$RW$$Base;
extern uint32 Image$$BTCONTROL_DATA$$RW$$Length;
extern uint32 Image$$BTCONTROL_DATA$$ZI$$Base;
extern uint32 Image$$BTCONTROL_DATA$$ZI$$Length;


#ifdef _A2DP_SOUCRE_
//LWBT
extern uint32  Load$$LWBT_UARTIF_CODE$$Base;
extern uint32 Image$$LWBT_UARTIF_CODE$$Base;
extern uint32 Image$$LWBT_UARTIF_CODE$$Length;
extern uint32  Load$$LWBT_UARTIF_DATA$$Base;
extern uint32 Image$$LWBT_UARTIF_DATA$$RW$$Base;
extern uint32 Image$$LWBT_UARTIF_DATA$$RW$$Length;
extern uint32 Image$$LWBT_UARTIF_DATA$$ZI$$Base;
extern uint32 Image$$LWBT_UARTIF_DATA$$ZI$$Length;

//LWBT
extern uint32  Load$$LWBT_INIT_CODE$$Base;
extern uint32 Image$$LWBT_INIT_CODE$$Base;
extern uint32 Image$$LWBT_INIT_CODE$$Length;
extern uint32  Load$$LWBT_INIT_DATA$$Base;
extern uint32 Image$$LWBT_INIT_DATA$$RW$$Base;
extern uint32 Image$$LWBT_INIT_DATA$$RW$$Length;
extern uint32 Image$$LWBT_INIT_DATA$$ZI$$Base;
extern uint32 Image$$LWBT_INIT_DATA$$ZI$$Length;
#endif

//LWBT
extern uint32  Load$$LWBT_CODE$$Base;
extern uint32 Image$$LWBT_CODE$$Base;
extern uint32 Image$$LWBT_CODE$$Length;
extern uint32  Load$$LWBT_DATA$$Base;
extern uint32 Image$$LWBT_DATA$$RW$$Base;
extern uint32 Image$$LWBT_DATA$$RW$$Length;
extern uint32 Image$$LWBT_DATA$$ZI$$Base;
extern uint32 Image$$LWBT_DATA$$ZI$$Length;

//SBC
extern uint32  Load$$SBC_ENCODE_CODE$$Base;
extern uint32 Image$$SBC_ENCODE_CODE$$Base;
extern uint32 Image$$SBC_ENCODE_CODE$$Length;
extern uint32  Load$$SBC_ENCODE_DATA$$Base;
extern uint32 Image$$SBC_ENCODE_DATA$$RW$$Base;
extern uint32 Image$$SBC_ENCODE_DATA$$RW$$Length;
extern uint32 Image$$SBC_ENCODE_DATA$$ZI$$Base;
extern uint32 Image$$SBC_ENCODE_DATA$$ZI$$Length;

//ssrc
extern uint32  Load$$SRC_CODE$$Base;
extern uint32 Image$$SRC_CODE$$Base;
extern uint32 Image$$SRC_CODE$$Length;
extern uint32  Load$$SRC_DATA$$Base;
extern uint32 Image$$SRC_DATA$$RW$$Base;
extern uint32 Image$$SRC_DATA$$RW$$Length;
extern uint32 Image$$SRC_DATA$$ZI$$Base;
extern uint32 Image$$SRC_DATA$$ZI$$Length;

//ssrc table
extern uint32  Load$$SRC_TABLE_CODE_48_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_48_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_48_44$$Length;
extern uint32  Load$$SRC_TABLE_DATA_48_44$$Base;
extern uint32 Image$$SRC_TABLE_DATA_48_44$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_48_44$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_48_44$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_48_44$$ZI$$Length;

extern uint32  Load$$SRC_TABLE_CODE_32_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_32_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_32_44$$Length;
extern uint32  Load$$SRC_TABLE_DATA_32_44$$Base;
extern uint32 Image$$SRC_TABLE_DATA_32_44$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_32_44$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_32_44$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_32_44$$ZI$$Length;

extern uint32  Load$$SRC_TABLE_CODE_24_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_24_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_24_44$$Length;
extern uint32  Load$$SRC_TABLE_DATA_24_44$$Base;
extern uint32 Image$$SRC_TABLE_DATA_24_44$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_24_44$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_24_44$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_24_44$$ZI$$Length;

extern uint32  Load$$SRC_TABLE_CODE_22_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_22_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_22_44$$Length;
extern uint32  Load$$SRC_TABLE_DATA_22_44$$Base;
extern uint32 Image$$SRC_TABLE_DATA_22_44$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_22_44$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_22_44$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_22_44$$ZI$$Length;

extern uint32  Load$$SRC_TABLE_CODE_16_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_16_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_16_44$$Length;
extern uint32  Load$$SRC_TABLE_DATA_16_44$$Base;
extern uint32 Image$$SRC_TABLE_DATA_16_44$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_16_44$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_16_44$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_16_44$$ZI$$Length;

extern uint32  Load$$SRC_TABLE_CODE_12_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_12_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_12_44$$Length;
extern uint32  Load$$SRC_TABLE_DATA_12_44$$Base;
extern uint32 Image$$SRC_TABLE_DATA_12_44$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_12_44$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_12_44$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_12_44$$ZI$$Length;

extern uint32  Load$$SRC_TABLE_CODE_11_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_11_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_11_44$$Length;
extern uint32  Load$$SRC_TABLE_DATA_11_44$$Base;
extern uint32 Image$$SRC_TABLE_DATA_11_44$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_11_44$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_11_44$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_11_44$$ZI$$Length;

extern uint32  Load$$SRC_TABLE_CODE_8_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_8_44$$Base;
extern uint32 Image$$SRC_TABLE_CODE_8_44$$Length;
extern uint32  Load$$SRC_TABLE_DATA_8_44$$Base;
extern uint32 Image$$SRC_TABLE_DATA_8_44$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_8_44$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_8_44$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_8_44$$ZI$$Length;

extern uint32  Load$$SRC_TABLE_CODE_48_44120$$Base;
extern uint32 Image$$SRC_TABLE_CODE_48_44120$$Base;
extern uint32 Image$$SRC_TABLE_CODE_48_44120$$Length;
extern uint32  Load$$SRC_TABLE_DATA_48_44120$$Base;
extern uint32 Image$$SRC_TABLE_DATA_48_44120$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_48_44120$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_48_44120$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_48_44120$$ZI$$Length;

extern uint32  Load$$SRC_TABLE_CODE_44_44120$$Base;
extern uint32 Image$$SRC_TABLE_CODE_44_44120$$Base;
extern uint32 Image$$SRC_TABLE_CODE_44_44120$$Length;
extern uint32  Load$$SRC_TABLE_DATA_44_44120$$Base;
extern uint32 Image$$SRC_TABLE_DATA_44_44120$$RW$$Base;
extern uint32 Image$$SRC_TABLE_DATA_44_44120$$RW$$Length;
extern uint32 Image$$SRC_TABLE_DATA_44_44120$$ZI$$Base;
extern uint32 Image$$SRC_TABLE_DATA_44_44120$$ZI$$Length;

//rtk8761a init script
extern uint32  Load$$BT_INIT_SCRIPT_CODE$$Base;
extern uint32 Image$$BT_INIT_SCRIPT_CODE$$Base;
extern uint32 Image$$BT_INIT_SCRIPT_CODE$$Length;


extern void UC1604C_WriteRAM_Prepare(void);
extern void UC1604C_Init(UINT8 XMirror,UINT8 YMirror,UINT8 Rotary);
extern void UC1604C_SendData(UINT16 data);
extern void UC1604C_SetWindow(UINT16 x0,UINT16 y0,UINT16 x1,INT16 y1);
extern void UC1604C_Clear(UINT16 color);
extern void UC1604C_DMATranfer (UINT8 x0,UINT8 y0,UINT8 x1,UINT8 y1,UINT16 *pSrc);
extern void UC1604C_Standby(void);
extern void UC1604C_WakeUp(void);
extern void UC1604C_SetPixel(UINT16 x, UINT16 y, UINT16 data);
extern void UC1604C_Buffer_Display1(unsigned  int x0,unsigned int y0,unsigned int x1,unsigned int y1);
extern void UC1604C_ClrSrc(void);
extern void UC1604C_ClrRect(int x0, int y0, int x1, int y1);
extern void UC1604C_DEV_FillRect(int x0, int y0, int x1, int y1);

extern void ST7735S_WriteRAM_Prepare(void);
extern void ST7735S_Init(void);
extern void ST7735S_SendData(UINT16 data);
extern void ST7735S_SetWindow(UINT16 x0,UINT16 y0,UINT16 x1,INT16 y1);
extern void ST7735S_Clear(UINT16 color);
extern int32 ST7735S_DMATranfer (UINT8 x0,UINT8 y0,UINT8 x1,UINT8 y1,UINT16 *pSrc);
extern void ST7735S_Standby(void);
extern void ST7735S_WakeUp(void);
extern void ST7735S_MP4_Init(void);
extern void ST7735S_MP4_DeInit(void);
extern void ST7735S_Clear_Screen(void);
extern void  ST7735S_ClrSrc(void);
extern void ST7735S_ClrRect(uint16 x0,uint16 y0,uint16 x1,int16 y1);

extern void ST7735_WriteRAM_Prepare(void);
extern void ST7735_Init(void);
extern void ST7735_SendData(UINT16 data);
extern void ST7735_SetWindow(UINT16 x0,UINT16 y0,UINT16 x1,INT16 y1);
extern void ST7735_Clear(UINT16 color);
extern int32 ST7735_DMATranfer (UINT8 x0,UINT8 y0,UINT8 x1,UINT8 y1,UINT16 *pSrc);
extern void ST7735_Standby(void);
extern void ST7735_WakeUp(void);
extern void ST7735_MP4_Init(void);
extern void ST7735_MP4_DeInit(void);
extern void ST7735_SetPixel(UINT16 x, UINT16 y, UINT16 data);
extern void ST7735_Buffer_Display1(unsigned  int x0,unsigned int y0,unsigned int x1,unsigned int y1);
extern void ST7735_Clear_Screen(void);
extern void ST7735_Clear_Rect(int x0, int y0, int x1, int y1);
extern void ST7735_Fill_Rect(int x0, int y0, int x1, int y1);
extern void  ST7735_ClrSrc(void);
extern void ST7735_ClrRect(uint16 x0,uint16 y0,uint16 x1,int16 y1);

extern void Qn8035_Tuner_SetInitArea(UINT8 area);
extern void Qn8035_Tuner_SetFrequency(UINT32 n10KHz, UINT8 HILO, BOOL ForceMono,UINT16 Area);
extern void Qn8035_Tuner_SetStereo(BOOL bStereo);
extern void Qn8035_Tuner_Vol_Set(UINT8 gain);
extern void Qn8035_Tuner_PowerOffDeinit(void);
extern UINT16 Qn8035_Tuner_SearchByHand(UINT16 direct, UINT32 *FmFreq);
extern void Qn8035_Tuner_PowerDown(void);
extern void Qn8035_Tuner_MuteControl(bool active);
extern BOOLEAN Qn8035_GetStereoStatus(void);

extern void FM5807_Tuner_SetInitArea(UINT8 area);
extern void FM5807_Tuner_SetFrequency(UINT32 n10KHz, UINT8 HILO, BOOL ForceMono,UINT16 Area);
extern void FM5807_Tuner_SetStereo(BOOL bStereo);
extern void FM5807_Tuner_Vol_Set(UINT8 gain);
extern void FM5807_Tuner_PowerOffDeinit(void);
extern UINT16 FM5807_Tuner_SearchByHand(UINT16 direct, UINT32 *FmFreq);
extern void FM5807_Tuner_PowerDown(void);
extern void FM5807_Tuner_MuteControl(bool active);
extern BOOLEAN FM5807_GetStereoStatus(void);


/*
--------------------------------------------------------------------------------
  Function name :
  Author        : ZHengYongzhi
  Description   : 模块信息表，生成固件模块头信息，用于代码调度

  History:     <author>         <time>         <version>
             ZhengYongzhi     2008/07/21         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
__attribute__((section("ModuleInfo")))
FIRMWARE_INFO_T const ModuleInfo =
{

    (uint32)(&Load$$MODULE_INFO$$Base),

    //CODE_INFO_TABLE
    {
        (uint32)(MAX_MODULE_NUM),
        {
            //系统段
            {
                (uint32)(&Load$$SYS_CODE$$Base),
                (uint32)(&Image$$SYS_CODE$$Base),
                (uint32)(&Image$$SYS_CODE$$Length),

                (uint32)(&Load$$SYS_DATA$$Base),
                (uint32)(&Image$$SYS_DATA$$RW$$Base),
                (uint32)(&Image$$SYS_DATA$$RW$$Length),

                (uint32)(&Image$$SYS_DATA$$ZI$$Base),
                (uint32)(&Image$$SYS_DATA$$ZI$$Length),
            },

            //系统初始化段
            {
                (uint32)(&Load$$SYS_INIT_CODE$$Base),
                (uint32)(&Image$$SYS_INIT_CODE$$Base),
                (uint32)(&Image$$SYS_INIT_CODE$$Length),

                (uint32)(&Load$$SYS_INIT_DATA$$Base),
                (uint32)(&Image$$SYS_INIT_DATA$$RW$$Base),
                (uint32)(&Image$$SYS_INIT_DATA$$RW$$Length),

                (uint32)(&Image$$SYS_INIT_DATA$$ZI$$Base),
                (uint32)(&Image$$SYS_INIT_DATA$$ZI$$Length),
            },

            //Flash编程
            {
                (uint32)(&Load$$FLASH_WRITE_CODE$$Base),
                (uint32)(&Image$$FLASH_WRITE_CODE$$Base),
                (uint32)(&Image$$FLASH_WRITE_CODE$$Length),

                (uint32)(&Load$$FLASH_WRITE_DATA$$Base),
                (uint32)(&Image$$FLASH_WRITE_DATA$$RW$$Base),
                (uint32)(&Image$$FLASH_WRITE_DATA$$RW$$Length),

                (uint32)(&Image$$FLASH_WRITE_DATA$$ZI$$Base),
                (uint32)(&Image$$FLASH_WRITE_DATA$$ZI$$Length),
            },


            //lcd驱动段driver1
            {
                (uint32)(&Load$$LCD_DRIVER1_CODE$$Base),
                (uint32)(&Image$$LCD_DRIVER1_CODE$$Base),
                (uint32)(&Image$$LCD_DRIVER1_CODE$$Length),

                (uint32)(&Load$$LCD_DRIVER1_DATA$$Base),
                (uint32)(&Image$$LCD_DRIVER1_DATA$$RW$$Base),
                (uint32)(&Image$$LCD_DRIVER1_DATA$$RW$$Length),

                (uint32)(&Image$$LCD_DRIVER1_DATA$$ZI$$Base),
                (uint32)(&Image$$LCD_DRIVER1_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$LCD_DRIVER2_CODE$$Base),
                (uint32)(&Image$$LCD_DRIVER2_CODE$$Base),
                (uint32)(&Image$$LCD_DRIVER2_CODE$$Length),

                (uint32)(&Load$$LCD_DRIVER2_DATA$$Base),
                (uint32)(&Image$$LCD_DRIVER2_DATA$$RW$$Base),
                (uint32)(&Image$$LCD_DRIVER2_DATA$$RW$$Length),

                (uint32)(&Image$$LCD_DRIVER2_DATA$$ZI$$Base),
                (uint32)(&Image$$LCD_DRIVER2_DATA$$ZI$$Length),
            },


            //MDB WIN
            {
                (uint32)(&Load$$MDB_WIN_CODE$$Base),
                (uint32)(&Image$$MDB_WIN_CODE$$Base),
                (uint32)(&Image$$MDB_WIN_CODE$$Length),

                (uint32)(&Load$$MDB_WIN_DATA$$Base),
                (uint32)(&Image$$MDB_WIN_DATA$$RW$$Base),
                (uint32)(&Image$$MDB_WIN_DATA$$RW$$Length),

                (uint32)(&Image$$MDB_WIN_DATA$$ZI$$Base),
                (uint32)(&Image$$MDB_WIN_DATA$$ZI$$Length),
            },

            //CHARGE WIN
            {
                (uint32)(&Load$$CHARGE_WIN_CODE$$Base),
                (uint32)(&Image$$CHARGE_WIN_CODE$$Base),
                (uint32)(&Image$$CHARGE_WIN_CODE$$Length),

                (uint32)(&Load$$CHARGE_WIN_DATA$$Base),
                (uint32)(&Image$$CHARGE_WIN_DATA$$RW$$Base),
                (uint32)(&Image$$CHARGE_WIN_DATA$$RW$$Length),

                (uint32)(&Image$$CHARGE_WIN_DATA$$ZI$$Base),
                (uint32)(&Image$$CHARGE_WIN_DATA$$ZI$$Length),
            },

            //FS MEM GET
            {
                (uint32)(&Load$$FS_MEM_GET_CODE$$Base),
                (uint32)(&Image$$FS_MEM_GET_CODE$$Base),
                (uint32)(&Image$$FS_MEM_GET_CODE$$Length),

                (uint32)(&Load$$FS_MEM_GET_DATA$$Base),
                (uint32)(&Image$$FS_MEM_GET_DATA$$RW$$Base),
                (uint32)(&Image$$FS_MEM_GET_DATA$$RW$$Length),

                (uint32)(&Image$$FS_MEM_GET_DATA$$ZI$$Base),
                (uint32)(&Image$$FS_MEM_GET_DATA$$ZI$$Length),
            },

            //FW Upgrade
            {
                (uint32)(&Load$$FW_UPGRADE_CODE$$Base),
                (uint32)(&Image$$FW_UPGRADE_CODE$$Base),
                (uint32)(&Image$$FW_UPGRADE_CODE$$Length),

                (uint32)(&Load$$FW_UPGRADE_DATA$$Base),
                (uint32)(&Image$$FW_UPGRADE_DATA$$RW$$Base),
                (uint32)(&Image$$FW_UPGRADE_DATA$$RW$$Length),

                (uint32)(&Image$$FW_UPGRADE_DATA$$ZI$$Base),
                (uint32)(&Image$$FW_UPGRADE_DATA$$ZI$$Length),
            },

            //USB window UI
            {
                (uint32)(&Load$$USBWIN_CODE$$Base),
                (uint32)(&Image$$USBWIN_CODE$$Base),
                (uint32)(&Image$$USBWIN_CODE$$Length),

                (uint32)(&Load$$USBWIN_DATA$$Base),
                (uint32)(&Image$$USBWIN_DATA$$RW$$Base),
                (uint32)(&Image$$USBWIN_DATA$$RW$$Length),

                (uint32)(&Image$$USBWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$USBWIN_DATA$$ZI$$Length),
            },

            //USB Control & driver
            {
                (uint32)(&Load$$USBCONTROL_CODE$$Base),
                (uint32)(&Image$$USBCONTROL_CODE$$Base),
                (uint32)(&Image$$USBCONTROL_CODE$$Length),

                (uint32)(&Load$$USBCONTROL_DATA$$Base),
                (uint32)(&Image$$USBCONTROL_DATA$$RW$$Base),
                (uint32)(&Image$$USBCONTROL_DATA$$RW$$Length),

                (uint32)(&Image$$USBCONTROL_DATA$$ZI$$Base),
                (uint32)(&Image$$USBCONTROL_DATA$$ZI$$Length),
            },

            //USB MSC
            {
                (uint32)(&Load$$USBMSC_CODE$$Base),
                (uint32)(&Image$$USBMSC_CODE$$Base),
                (uint32)(&Image$$USBMSC_CODE$$Length),

                (uint32)(&Load$$USBMSC_DATA$$Base),
                (uint32)(&Image$$USBMSC_DATA$$RW$$Base),
                (uint32)(&Image$$USBMSC_DATA$$RW$$Length),

                (uint32)(&Image$$USBMSC_DATA$$ZI$$Base),
                (uint32)(&Image$$USBMSC_DATA$$ZI$$Length),
            },

            //VIDEO
            {
                (uint32)(&Load$$VIDEOWIN_CODE$$Base),
                (uint32)(&Image$$VIDEOWIN_CODE$$Base),
                (uint32)(&Image$$VIDEOWIN_CODE$$Length),

                (uint32)(&Load$$VIDEOWIN_DATA$$Base),
                (uint32)(&Image$$VIDEOWIN_DATA$$RW$$Base),
                (uint32)(&Image$$VIDEOWIN_DATA$$RW$$Length),

                (uint32)(&Image$$VIDEOWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$VIDEOWIN_DATA$$ZI$$Length),
            },

            //VIDEO CONTROL
            {
                (uint32)(&Load$$VIDEO_CONTROL_CODE$$Base),
                (uint32)(&Image$$VIDEO_CONTROL_CODE$$Base),
                (uint32)(&Image$$VIDEO_CONTROL_CODE$$Length),

                (uint32)(&Load$$VIDEO_CONTROL_DATA$$Base),
                (uint32)(&Image$$VIDEO_CONTROL_DATA$$RW$$Base),
                (uint32)(&Image$$VIDEO_CONTROL_DATA$$RW$$Length),

                (uint32)(&Image$$VIDEO_CONTROL_DATA$$ZI$$Base),
                (uint32)(&Image$$VIDEO_CONTROL_DATA$$ZI$$Length),
            },

            //VIDEO_Mp2 Decode
            {
                (uint32)(&Load$$MP2_DECODE_CODE$$Base),
                (uint32)(&Image$$MP2_DECODE_CODE$$Base),
                (uint32)(&Image$$MP2_DECODE_CODE$$Length),

                (uint32)(&Load$$MP2_DECODE_DATA$$Base),
                (uint32)(&Image$$MP2_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$MP2_DECODE_DATA$$RW$$Length),

                (uint32)(&Image$$MP2_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$MP2_DECODE_DATA$$ZI$$Length),
            },

            //AVI Decode
            {
                (uint32)(&Load$$AVI_DECODE_CODE$$Base),
                (uint32)(&Image$$AVI_DECODE_CODE$$Base),
                (uint32)(&Image$$AVI_DECODE_CODE$$Length),

                (uint32)(&Load$$AVI_DECODE_DATA$$Base),
                (uint32)(&Image$$AVI_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$AVI_DECODE_DATA$$RW$$Length),

                (uint32)(&Image$$AVI_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$AVI_DECODE_DATA$$ZI$$Length),
            },

            //PicWin
            {
                (uint32)(&Load$$PICWIN_CODE$$Base),
                (uint32)(&Image$$PICWIN_CODE$$Base),
                (uint32)(&Image$$PICWIN_CODE$$Length),

                (uint32)(&Load$$PICWIN_DATA$$Base),
                (uint32)(&Image$$PICWIN_DATA$$RW$$Base),
                (uint32)(&Image$$PICWIN_DATA$$RW$$Length),

                (uint32)(&Image$$PICWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$PICWIN_DATA$$ZI$$Length),
            },

            //PicWin jin cheng
            {
                (uint32)(&Load$$IMAGE_CONTROL_CODE$$Base),
                (uint32)(&Image$$IMAGE_CONTROL_CODE$$Base),
                (uint32)(&Image$$IMAGE_CONTROL_CODE$$Length),

                (uint32)(&Load$$IMAGE_CONTROL_DATA$$Base),
                (uint32)(&Image$$IMAGE_CONTROL_DATA$$RW$$Base),
                (uint32)(&Image$$IMAGE_CONTROL_DATA$$RW$$Length),

                (uint32)(&Image$$IMAGE_CONTROL_DATA$$ZI$$Base),
                (uint32)(&Image$$IMAGE_CONTROL_DATA$$ZI$$Length),
            },

            //JPG Decode
            {
                (uint32)( &Load$$JPG_DECODE_CODE$$Base),
                (uint32)(&Image$$JPG_DECODE_CODE$$Base),
                (uint32)(&Image$$JPG_DECODE_CODE$$Length),

                (uint32)( &Load$$JPG_DECODE_DATA$$Base),
                (uint32)(&Image$$JPG_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$JPG_DECODE_DATA$$RW$$Length),

                (uint32)(&Image$$JPG_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$JPG_DECODE_DATA$$ZI$$Length),
            },

            //BMP Decode
            {
                (uint32)( &Load$$BMP_DECODE_CODE$$Base),
                (uint32)(&Image$$BMP_DECODE_CODE$$Base),
                (uint32)(&Image$$BMP_DECODE_CODE$$Length),

                (uint32)( &Load$$BMP_DECODE_DATA$$Base),
                (uint32)(&Image$$BMP_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$BMP_DECODE_DATA$$RW$$Length),

                (uint32)(&Image$$BMP_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$BMP_DECODE_DATA$$ZI$$Length),
            },


            //UI 主菜单
            {
                (uint32)(&Load$$MAINMENU_CODE$$Base),
                (uint32)(&Image$$MAINMENU_CODE$$Base),
                (uint32)(&Image$$MAINMENU_CODE$$Length),

                (uint32)(&Load$$MAINMENU_DATA$$Base),
                (uint32)(&Image$$MAINMENU_DATA$$RW$$Base),
                (uint32)(&Image$$MAINMENU_DATA$$RW$$Length),

                (uint32)(&Image$$MAINMENU_DATA$$ZI$$Base),
                (uint32)(&Image$$MAINMENU_DATA$$ZI$$Length),
            },

            //媒体库
            {
                (uint32)(&Load$$MEDIALIBWIN_CODE$$Base),
                (uint32)(&Image$$MEDIALIBWIN_CODE$$Base),
                (uint32)(&Image$$MEDIALIBWIN_CODE$$Length),

                (uint32)(&Load$$MEDIALIBWIN_DATA$$Base),
                (uint32)(&Image$$MEDIALIBWIN_DATA$$RW$$Base),
                (uint32)(&Image$$MEDIALIBWIN_DATA$$RW$$Length),

                (uint32)(&Image$$MEDIALIBWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$MEDIALIBWIN_DATA$$ZI$$Length),
            },

            //媒体库浏览
            {
                (uint32)(&Load$$MEDIABROWIN_CODE$$Base),
                (uint32)(&Image$$MEDIABROWIN_CODE$$Base),
                (uint32)(&Image$$MEDIABROWIN_CODE$$Length),

                (uint32)(&Load$$MEDIABROWIN_DATA$$Base),
                (uint32)(&Image$$MEDIABROWIN_DATA$$RW$$Base),
                (uint32)(&Image$$MEDIABROWIN_DATA$$RW$$Length),

                (uint32)(&Image$$MEDIABROWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$MEDIABROWIN_DATA$$ZI$$Length),
            },

            {//媒体库 mediasortget
                (uint32)(&Load$$MEDIABRO_SORTGET_CODE$$Base),
                (uint32)(&Image$$MEDIABRO_SORTGET_CODE$$Base),
                (uint32)(&Image$$MEDIABRO_SORTGET_CODE$$Length),

                (uint32)(&Load$$MEDIABRO_SORTGET_DATA$$Base),
                (uint32)(&Image$$MEDIABRO_SORTGET_DATA$$RW$$Base),
                (uint32)(&Image$$MEDIABRO_SORTGET_DATA$$RW$$Length),

                (uint32)(&Image$$MEDIABRO_SORTGET_DATA$$ZI$$Base),
                (uint32)(&Image$$MEDIABRO_SORTGET_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$MEDIABROSUBWIN_CODE$$Base),
                (uint32)(&Image$$MEDIABROSUBWIN_CODE$$Base),
                (uint32)(&Image$$MEDIABROSUBWIN_CODE$$Length),

                (uint32)(&Load$$MEDIABROSUBWIN_DATA$$Base),
                (uint32)(&Image$$MEDIABROSUBWIN_DATA$$RW$$Base),
                (uint32)(&Image$$MEDIABROSUBWIN_DATA$$RW$$Length),

                (uint32)(&Image$$MEDIABROSUBWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$MEDIABROSUBWIN_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$MEDIAFAVOSUBWIN_CODE$$Base),
                (uint32)(&Image$$MEDIAFAVOSUBWIN_CODE$$Base),
                (uint32)(&Image$$MEDIAFAVOSUBWIN_CODE$$Length),

                (uint32)(&Load$$MEDIAFAVOSUBWIN_DATA$$Base),
                (uint32)(&Image$$MEDIAFAVOSUBWIN_DATA$$RW$$Base),
                (uint32)(&Image$$MEDIAFAVOSUBWIN_DATA$$RW$$Length),

                (uint32)(&Image$$MEDIAFAVOSUBWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$MEDIAFAVOSUBWIN_DATA$$ZI$$Length),
            } ,

            //UI 音乐播放
            {
                (uint32)(&Load$$MUSICWIN_CODE$$Base),
                (uint32)(&Image$$MUSICWIN_CODE$$Base),
                (uint32)(&Image$$MUSICWIN_CODE$$Length),

                (uint32)(&Load$$MUSICWIN_DATA$$Base),
                (uint32)(&Image$$MUSICWIN_DATA$$RW$$Base),
                (uint32)(&Image$$MUSICWIN_DATA$$RW$$Length),

                (uint32)(&Image$$MUSICWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$MUSICWIN_DATA$$ZI$$Length),
            },

            //UI收音机
            {
                (uint32)(&Load$$RADIOWIN_CODE$$Base),
                (uint32)(&Image$$RADIOWIN_CODE$$Base),
                (uint32)(&Image$$RADIOWIN_CODE$$Length),

                (uint32)(&Load$$RADIOWIN_DATA$$Base),
                (uint32)(&Image$$RADIOWIN_DATA$$RW$$Base),
                (uint32)(&Image$$RADIOWIN_DATA$$RW$$Length),

                (uint32)(&Image$$RADIOWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$RADIOWIN_DATA$$ZI$$Length),
            },

            //UI 录音窗体
            {
                (uint32)(&Load$$RECORDWIN_CODE$$Base),
                (uint32)(&Image$$RECORDWIN_CODE$$Base),
                (uint32)(&Image$$RECORDWIN_CODE$$Length),

                (uint32)(&Load$$RECORDWIN_DATA$$Base),
                (uint32)(&Image$$RECORDWIN_DATA$$RW$$Base),
                (uint32)(&Image$$RECORDWIN_DATA$$RW$$Length),

                (uint32)(&Image$$RECORDWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$RECORDWIN_DATA$$ZI$$Length),
            },

            //UI电子书
            {
                (uint32)(&Load$$TEXTWIN_CODE$$Base),
                (uint32)(&Image$$TEXTWIN_CODE$$Base),
                (uint32)(&Image$$TEXTWIN_CODE$$Length),

                (uint32)(&Load$$TEXTWIN_DATA$$Base),
                (uint32)(&Image$$TEXTWIN_DATA$$RW$$Base),
                (uint32)(&Image$$TEXTWIN_DATA$$RW$$Length),

                (uint32)(&Image$$TEXTWIN_DATA$$ZI$$Base),
                (uint32)(&Image$$TEXTWIN_DATA$$ZI$$Length),
            },

            //UI资源管理器
            {
                (uint32)(&Load$$BROWSER_CODE$$Base),
                (uint32)(&Image$$BROWSER_CODE$$Base),
                (uint32)(&Image$$BROWSER_CODE$$Length),

                (uint32)(&Load$$BROWSER_DATA$$Base),
                (uint32)(&Image$$BROWSER_DATA$$RW$$Base),
                (uint32)(&Image$$BROWSER_DATA$$RW$$Length),

                (uint32)(&Image$$BROWSER_DATA$$ZI$$Base),
                (uint32)(&Image$$BROWSER_DATA$$ZI$$Length),
            },


            //UI设置菜单
            {
                (uint32)(&Load$$SETMENU_CODE$$Base),
                (uint32)(&Image$$SETMENU_CODE$$Base),
                (uint32)(&Image$$SETMENU_CODE$$Length),

                (uint32)(&Load$$SETMENU_DATA$$Base),
                (uint32)(&Image$$SETMENU_DATA$$RW$$Base),
                (uint32)(&Image$$SETMENU_DATA$$RW$$Length),

                (uint32)(&Image$$SETMENU_DATA$$ZI$$Base),
                (uint32)(&Image$$SETMENU_DATA$$ZI$$Length),
            },

            //CONSOLE 音乐播放后台
            {
                (uint32)(&Load$$AUDIO_CONTROL_CODE$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_CODE$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_CODE$$Length),

                (uint32)(&Load$$AUDIO_CONTROL_DATA$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_DATA$$RW$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_DATA$$RW$$Length),

                (uint32)(&Image$$AUDIO_CONTROL_DATA$$ZI$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$AUDIO_CONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_INIT_CODE$$Length),

                (uint32)(&Load$$AUDIO_CONTROL_INIT_DATA$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_INIT_DATA$$RW$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_INIT_DATA$$RW$$Length),

                (uint32)(&Image$$AUDIO_CONTROL_INIT_DATA$$ZI$$Base),
                (uint32)(&Image$$AUDIO_CONTROL_INIT_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$AUDIO_EQ_CODE$$Base),
                (uint32)(&Image$$AUDIO_EQ_CODE$$Base),
                (uint32)(&Image$$AUDIO_EQ_CODE$$Length),

                (uint32)(&Load$$AUDIO_EQ_DATA$$Base),
                (uint32)(&Image$$AUDIO_EQ_DATA$$RW$$Base),
                (uint32)(&Image$$AUDIO_EQ_DATA$$RW$$Length),

                (uint32)(&Image$$AUDIO_EQ_DATA$$ZI$$Base),
                (uint32)(&Image$$AUDIO_EQ_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$AUDIO_RKEQ_CODE$$Base),
                (uint32)(&Image$$AUDIO_RKEQ_CODE$$Base),
                (uint32)(&Image$$AUDIO_RKEQ_CODE$$Length),

                (uint32)(&Load$$AUDIO_RKEQ_DATA$$Base),
                (uint32)(&Image$$AUDIO_RKEQ_DATA$$RW$$Base),
                (uint32)(&Image$$AUDIO_RKEQ_DATA$$RW$$Length),

                (uint32)(&Image$$AUDIO_RKEQ_DATA$$ZI$$Base),
                (uint32)(&Image$$AUDIO_RKEQ_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$AUDIO_ID3_CODE$$Base),
                (uint32)(&Image$$AUDIO_ID3_CODE$$Base),
                (uint32)(&Image$$AUDIO_ID3_CODE$$Length),

                (uint32)(&Load$$AUDIO_ID3_DATA$$Base),
                (uint32)(&Image$$AUDIO_ID3_DATA$$RW$$Base),
                (uint32)(&Image$$AUDIO_ID3_DATA$$RW$$Length),

                (uint32)(&Image$$AUDIO_ID3_DATA$$ZI$$Base),
                (uint32)(&Image$$AUDIO_ID3_DATA$$ZI$$Length),
            },

            //CONSOLE 媒体库
            {
                (uint32)(&Load$$FILE_INFO_SAVE_CODE$$Base),
                (uint32)(&Image$$FILE_INFO_SAVE_CODE$$Base),
                (uint32)(&Image$$FILE_INFO_SAVE_CODE$$Length),

                (uint32)(&Load$$FILE_INFO_SAVE_DATA$$Base),
                (uint32)(&Image$$FILE_INFO_SAVE_DATA$$RW$$Base),
                (uint32)(&Image$$FILE_INFO_SAVE_DATA$$RW$$Length),

                (uint32)(&Image$$FILE_INFO_SAVE_DATA$$ZI$$Base),
                (uint32)(&Image$$FILE_INFO_SAVE_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$FILE_INFO_SORT_CODE$$Base),
                (uint32)(&Image$$FILE_INFO_SORT_CODE$$Base),
                (uint32)(&Image$$FILE_INFO_SORT_CODE$$Length),

                (uint32)(&Load$$FILE_INFO_SORT_DATA$$Base),
                (uint32)(&Image$$FILE_INFO_SORT_DATA$$RW$$Base),
                (uint32)(&Image$$FILE_INFO_SORT_DATA$$RW$$Length),

                (uint32)(&Image$$FILE_INFO_SORT_DATA$$ZI$$Base),
                (uint32)(&Image$$FILE_INFO_SORT_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$FAVORESET_CODE$$Base),
                (uint32)(&Image$$FAVORESET_CODE$$Base),
                (uint32)(&Image$$FAVORESET_CODE$$Length),

                (uint32)(&Load$$FAVORESET_DATA$$Base),
                (uint32)(&Image$$FAVORESET_DATA$$RW$$Base),
                (uint32)(&Image$$FAVORESET_DATA$$RW$$Length),

                (uint32)(&Image$$FAVORESET_DATA$$ZI$$Base),
                (uint32)(&Image$$FAVORESET_DATA$$ZI$$Length),
            },

//-------------------------decode segment---------------------------------------
            //MP3
            {
                (uint32)(&Load$$MP3_DECODE_CODE$$Base),
                (uint32)(&Image$$MP3_DECODE_CODE$$Base),
                (uint32)(&Image$$MP3_DECODE_CODE$$Length),

                (uint32)(&Load$$MP3_DECODE_DATA$$Base),
                (uint32)(&Image$$MP3_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$MP3_DECODE_DATA$$RW$$Length),

                (uint32)(&Image$$MP3_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$MP3_DECODE_DATA$$ZI$$Length),
            },


            //ACC
            {
                (uint32)(&Load$$AAC_DECODE_CODE$$Base),
                (uint32)(&Image$$AAC_DECODE_CODE$$Base),
                (uint32)(&Image$$AAC_DECODE_CODE$$Length),
                (uint32)(&Load$$AAC_DECODE_DATA$$Base),
                (uint32)(&Image$$AAC_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$AAC_DECODE_DATA$$RW$$Length),
                (uint32)(&Image$$AAC_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$AAC_DECODE_DATA$$ZI$$Length),
            },

            //WAV
            {
                (uint32)(&Load$$WAV_DECODE_CODE$$Base),
                (uint32)(&Image$$WAV_DECODE_CODE$$Base),
                (uint32)(&Image$$WAV_DECODE_CODE$$Length),

                (uint32)(&Load$$WAV_DECODE_DATA$$Base),
                (uint32)(&Image$$WAV_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$WAV_DECODE_DATA$$RW$$Length),

                (uint32)(&Image$$WAV_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$WAV_DECODE_DATA$$ZI$$Length),
            },


            //OGG
            {
                (uint32)(&Load$$OGG_DECODE_CODE$$Base),
                (uint32)(&Image$$OGG_DECODE_CODE$$Base),
                (uint32)(&Image$$OGG_DECODE_CODE$$Length),
                (uint32)(&Load$$OGG_DECODE_DATA$$Base),
                (uint32)(&Image$$OGG_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$OGG_DECODE_DATA$$RW$$Length),
                (uint32)(&Image$$OGG_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$OGG_DECODE_DATA$$ZI$$Length),
            },

            //HIFI FLAC
            {
                (uint32)(&Load$$FLAC_HDECODE_CODE$$Base),
                (uint32)(&Image$$FLAC_HDECODE_CODE$$Base),
                (uint32)(&Image$$FLAC_HDECODE_CODE$$Length),
                (uint32)(&Load$$FLAC_HDECODE_DATA$$Base),
                (uint32)(&Image$$FLAC_HDECODE_DATA$$RW$$Base),
                (uint32)(&Image$$FLAC_HDECODE_DATA$$RW$$Length),
                (uint32)(&Image$$FLAC_HDECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$FLAC_HDECODE_DATA$$ZI$$Length),
            },

            //HIFI ALAC
            {
                (uint32)(&Load$$ALAC_HDECODE_CODE$$Base),
                (uint32)(&Image$$ALAC_HDECODE_CODE$$Base),
                (uint32)(&Image$$ALAC_HDECODE_CODE$$Length),
                (uint32)(&Load$$ALAC_HDECODE_DATA$$Base),
                (uint32)(&Image$$ALAC_HDECODE_DATA$$RW$$Base),
                (uint32)(&Image$$ALAC_HDECODE_DATA$$RW$$Length),
                (uint32)(&Image$$ALAC_HDECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$ALAC_HDECODE_DATA$$ZI$$Length),
            },

            //HIFI APE
            {
                (uint32)(&Load$$APE_HDECODE_CODE$$Base),
                (uint32)(&Image$$APE_HDECODE_CODE$$Base),
                (uint32)(&Image$$APE_HDECODE_CODE$$Length),
                (uint32)(&Load$$APE_HDECODE_DATA$$Base),
                (uint32)(&Image$$APE_HDECODE_DATA$$RW$$Base),
                (uint32)(&Image$$APE_HDECODE_DATA$$RW$$Length),
                (uint32)(&Image$$APE_HDECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$APE_HDECODE_DATA$$ZI$$Length),
            },

            //DSD
            {
                (uint32)(&Load$$DSDIFF_DECODE_CODE$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_CODE$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_CODE$$Length),
                (uint32)(&Load$$DSDIFF_DECODE_DATA$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_DATA$$RW$$Length),
                (uint32)(&Image$$DSDIFF_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_DATA$$ZI$$Length),
            },

           //DSF
            {
                (uint32)(&Load$$DSF_DECODE_CODE$$Base),
                (uint32)(&Image$$DSF_DECODE_CODE$$Base),
                (uint32)(&Image$$DSF_DECODE_CODE$$Length),
                (uint32)(&Load$$DSF_DECODE_DATA$$Base),
                (uint32)(&Image$$DSF_DECODE_DATA$$RW$$Base),
                (uint32)(&Image$$DSF_DECODE_DATA$$RW$$Length),
                (uint32)(&Image$$DSF_DECODE_DATA$$ZI$$Base),
                (uint32)(&Image$$DSF_DECODE_DATA$$ZI$$Length),
            },


            //CONSOLE 收音机
            {
                (uint32)(&Load$$FM_CONTROL_CODE$$Base),
                (uint32)(&Image$$FM_CONTROL_CODE$$Base),
                (uint32)(&Image$$FM_CONTROL_CODE$$Length),

                (uint32)(&Load$$FM_CONTROL_DATA$$Base),
                (uint32)(&Image$$FM_CONTROL_DATA$$RW$$Base),
                (uint32)(&Image$$FM_CONTROL_DATA$$RW$$Length),

                (uint32)(&Image$$FM_CONTROL_DATA$$ZI$$Base),
                (uint32)(&Image$$FM_CONTROL_DATA$$ZI$$Length),
            },

            //FM 驱动
            {
                (uint32)(&Load$$FM_DRIVER1_CODE$$Base),
                (uint32)(&Image$$FM_DRIVER1_CODE$$Base),
                (uint32)(&Image$$FM_DRIVER1_CODE$$Length),

                (uint32)(&Load$$FM_DRIVER1_DATA$$Base),
                (uint32)(&Image$$FM_DRIVER1_DATA$$RW$$Base),
                (uint32)(&Image$$FM_DRIVER1_DATA$$RW$$Length),

                (uint32)(&Image$$FM_DRIVER1_DATA$$ZI$$Base),
                (uint32)(&Image$$FM_DRIVER1_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$FM_DRIVER2_CODE$$Base),
                (uint32)(&Image$$FM_DRIVER2_CODE$$Base),
                (uint32)(&Image$$FM_DRIVER2_CODE$$Length),

                (uint32)(&Load$$FM_DRIVER2_DATA$$Base),
                (uint32)(&Image$$FM_DRIVER2_DATA$$RW$$Base),
                (uint32)(&Image$$FM_DRIVER2_DATA$$RW$$Length),

                (uint32)(&Image$$FM_DRIVER2_DATA$$ZI$$Base),
                (uint32)(&Image$$FM_DRIVER2_DATA$$ZI$$Length),
            },

            //CONSOLE 录音
            {
                (uint32)(&Load$$RECORD_CONTROL_CODE$$Base),
                (uint32)(&Image$$RECORD_CONTROL_CODE$$Base),
                (uint32)(&Image$$RECORD_CONTROL_CODE$$Length),

                (uint32)(&Load$$RECORD_CONTROL_DATA$$Base),
                (uint32)(&Image$$RECORD_CONTROL_DATA$$RW$$Base),
                (uint32)(&Image$$RECORD_CONTROL_DATA$$RW$$Length),

                (uint32)(&Image$$RECORD_CONTROL_DATA$$ZI$$Base),
                (uint32)(&Image$$RECORD_CONTROL_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$ENCODE_MSADPCM_CODE$$Base),
                (uint32)(&Image$$ENCODE_MSADPCM_CODE$$Base),
                (uint32)(&Image$$ENCODE_MSADPCM_CODE$$Length),

                (uint32)(&Load$$ENCODE_MSADPCM_DATA$$Base),
                (uint32)(&Image$$ENCODE_MSADPCM_DATA$$RW$$Base),
                (uint32)(&Image$$ENCODE_MSADPCM_DATA$$RW$$Length),

                (uint32)(&Image$$ENCODE_MSADPCM_DATA$$ZI$$Base),
                (uint32)(&Image$$ENCODE_MSADPCM_DATA$$ZI$$Length),
            },

            // asic to unicode
            {
                (uint32)(&Load$$CP1251_UNICODE_TABLE_CODE$$Base),
                NULL,
                (uint32)(&Image$$CP1251_UNICODE_TABLE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
            },
            {
                (uint32)(&Load$$CP932_UNICODE_TABLE_CODE$$Base),
                NULL,
                (uint32)(&Image$$CP932_UNICODE_TABLE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
            },
            {
                (uint32)(&Load$$CP932_UNICODE_TABLE1_CODE$$Base),
                NULL,
                (uint32)(&Image$$CP932_UNICODE_TABLE1_CODE$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
            },
            {
                (uint32)(&Load$$CP932_UNICODE_TABLE2_CODE$$Base),
                NULL,
                (uint32)(&Image$$CP932_UNICODE_TABLE2_CODE$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
            },
            {
                (uint32)(&Load$$CP950_UNICODE_TABLE_CODE$$Base),
                NULL,
                (uint32)(&Image$$CP950_UNICODE_TABLE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
            },
            {
                (uint32)(&Load$$CP949_UNICODE_TABLE_CODE$$Base),
                NULL,
                (uint32)(&Image$$CP949_UNICODE_TABLE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
            },
            {
                (uint32)(&Load$$CP949_UNICODE_TABLE1_CODE$$Base),
                NULL,
                (uint32)(&Image$$CP949_UNICODE_TABLE1_CODE$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
            },

//----------------------------BB Module ---------------------------------------
            //bb_core
            {
                (uint32)(&Load$$BB_SYS_CODE$$Base),
                (uint32)(&Image$$BB_SYS_CODE$$Base),
                (uint32)(&Image$$BB_SYS_CODE$$Length),

                (uint32)(&Load$$BB_SYS_DATA$$Base),
                (uint32)(&Image$$BB_SYS_DATA$$RW$$Base),
                (uint32)(&Image$$BB_SYS_DATA$$RW$$Length),

                (uint32)(&Image$$BB_SYS_DATA$$ZI$$Base),
                (uint32)(&Image$$BB_SYS_DATA$$ZI$$Length),
            },

            //MP3 decode
            {
                (uint32)(&Load$$MP3_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_CODE$$Length),

                (uint32)(&Load$$MP3_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_DATA$$RW$$Length),

                (uint32)(&Image$$MP3_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_DATA$$ZI$$Length),
            },

            //AAC
            {
                (uint32)(&Load$$AAC_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_CODE$$Length),

                (uint32)(&Load$$AAC_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_DATA$$RW$$Length),

                (uint32)(&Image$$AAC_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_DATA$$ZI$$Length),
            },

            //WAV
            {
                (uint32)(&Load$$WAV_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_CODE$$Length),

                (uint32)(&Load$$WAV_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_DATA$$RW$$Length),

                (uint32)(&Image$$WAV_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_DATA$$ZI$$Length),
            },

            //OGG
            {
                (uint32)(&Load$$OGG_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_CODE$$Length),

                (uint32)(&Load$$OGG_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_DATA$$RW$$Length),

                (uint32)(&Image$$OGG_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_DATA$$ZI$$Length),
            },

            //HIFI FLAC
            {
                (uint32)(&Load$$FLAC_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_CODE$$Length),

                (uint32)(&Load$$FLAC_HDECODE_BIN_DATA$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_DATA$$RW$$Length),

                (uint32)(&Image$$FLAC_HDECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_DATA$$ZI$$Length),
            },

            //HIFI ALAC
            {
                (uint32)(&Load$$ALAC_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_CODE$$Length),

                (uint32)(&Load$$ALAC_HDECODE_BIN_DATA$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_DATA$$RW$$Length),

                (uint32)(&Image$$ALAC_HDECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_DATA$$ZI$$Length),
            },

            //HIFI APE
            {
                (uint32)(&Load$$APE_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_CODE$$Length),

                (uint32)(&Load$$APE_HDECODE_BIN_DATA$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_DATA$$RW$$Length),

                (uint32)(&Image$$APE_HDECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_DATA$$ZI$$Length),
            },

            //DSD
            {
                (uint32)(&Load$$DSDIFF_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$DSDIFF_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$DSDIFF_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$DSDIFF_DECODE_BIN_DATA$$ZI$$Length),
            },

             //DSF
            {
                (uint32)(&Load$$DSF_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$DSF_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$DSF_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$DSF_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$DSF_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$DSF_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$DSF_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$DSF_DECODE_BIN_DATA$$ZI$$Length),
            },

            //BT Control
            {
                (uint32)(&Load$$BTCONTROL_CODE$$Base),
                (uint32)(&Image$$BTCONTROL_CODE$$Base),
                (uint32)(&Image$$BTCONTROL_CODE$$Length),

                (uint32)(&Load$$BTCONTROL_DATA$$Base),
                (uint32)(&Image$$BTCONTROL_DATA$$RW$$Base),
                (uint32)(&Image$$BTCONTROL_DATA$$RW$$Length),

                (uint32)(&Image$$BTCONTROL_DATA$$ZI$$Base),
                (uint32)(&Image$$BTCONTROL_DATA$$ZI$$Length),
            },

            #ifdef _A2DP_SOUCRE_
            //lwbt_uartif
            {
                (uint32)(&Load$$LWBT_UARTIF_CODE$$Base),
                (uint32)(&Image$$LWBT_UARTIF_CODE$$Base),
                (uint32)(&Image$$LWBT_UARTIF_CODE$$Length),

                (uint32)(&Load$$LWBT_UARTIF_DATA$$Base),
                (uint32)(&Image$$LWBT_UARTIF_DATA$$RW$$Base),
                (uint32)(&Image$$LWBT_UARTIF_DATA$$RW$$Length),

                (uint32)(&Image$$LWBT_UARTIF_DATA$$ZI$$Base),
                (uint32)(&Image$$LWBT_UARTIF_DATA$$ZI$$Length),
            },

            //lwbt_init
            {
                (uint32)(&Load$$LWBT_INIT_CODE$$Base),
                (uint32)(&Image$$LWBT_INIT_CODE$$Base),
                (uint32)(&Image$$LWBT_INIT_CODE$$Length),

                (uint32)(&Load$$LWBT_INIT_DATA$$Base),
                (uint32)(&Image$$LWBT_INIT_DATA$$RW$$Base),
                (uint32)(&Image$$LWBT_INIT_DATA$$RW$$Length),

                (uint32)(&Image$$LWBT_INIT_DATA$$ZI$$Base),
                (uint32)(&Image$$LWBT_INIT_DATA$$ZI$$Length),
            },
            #else
            {
                (uint32)0,
                (uint32)0,
                (uint32)0,

                (uint32)0,
                (uint32)0,
                (uint32)0,

                (uint32)0,
                (uint32)0,
            },
            {
                (uint32)0,
                (uint32)0,
                (uint32)0,

                (uint32)0,
                (uint32)0,
                (uint32)0,

                (uint32)0,
                (uint32)0,
            },

            #endif

            //lwbt
            {
                (uint32)(&Load$$LWBT_CODE$$Base),
                (uint32)(&Image$$LWBT_CODE$$Base),
                (uint32)(&Image$$LWBT_CODE$$Length),

                (uint32)(&Load$$LWBT_DATA$$Base),
                (uint32)(&Image$$LWBT_DATA$$RW$$Base),
                (uint32)(&Image$$LWBT_DATA$$RW$$Length),

                (uint32)(&Image$$LWBT_DATA$$ZI$$Base),
                (uint32)(&Image$$LWBT_DATA$$ZI$$Length),
            },

            //sbc encode
            {
                (uint32)(&Load$$SBC_ENCODE_CODE$$Base),
                (uint32)(&Image$$SBC_ENCODE_CODE$$Base),
                (uint32)(&Image$$SBC_ENCODE_CODE$$Length),

                (uint32)(&Load$$SBC_ENCODE_DATA$$Base),
                (uint32)(&Image$$SBC_ENCODE_DATA$$RW$$Base),
                (uint32)(&Image$$SBC_ENCODE_DATA$$RW$$Length),

                (uint32)(&Image$$SBC_ENCODE_DATA$$ZI$$Base),
                (uint32)(&Image$$SBC_ENCODE_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_CODE$$Base),
                (uint32)(&Image$$SRC_CODE$$Base),
                (uint32)(&Image$$SRC_CODE$$Length),

                (uint32)(&Load$$SRC_DATA$$Base),
                (uint32)(&Image$$SRC_DATA$$RW$$Base),
                (uint32)(&Image$$SRC_DATA$$RW$$Length),

                (uint32)(&Image$$SRC_DATA$$ZI$$Base),
                (uint32)(&Image$$SRC_DATA$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_TABLE_CODE_48_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_48_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_48_44$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_48_44$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_48_44$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_48_44$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_48_44$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_48_44$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_TABLE_CODE_32_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_32_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_32_44$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_32_44$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_32_44$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_32_44$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_32_44$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_32_44$$ZI$$Length),
            },


            {
                (uint32)(&Load$$SRC_TABLE_CODE_24_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_24_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_24_44$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_24_44$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_24_44$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_24_44$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_24_44$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_24_44$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_TABLE_CODE_22_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_22_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_22_44$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_22_44$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_22_44$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_22_44$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_22_44$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_22_44$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_TABLE_CODE_16_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_16_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_16_44$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_16_44$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_16_44$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_16_44$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_16_44$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_16_44$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_TABLE_CODE_12_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_12_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_12_44$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_12_44$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_12_44$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_12_44$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_12_44$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_12_44$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_TABLE_CODE_11_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_11_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_11_44$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_11_44$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_11_44$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_11_44$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_11_44$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_11_44$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_TABLE_CODE_8_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_8_44$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_8_44$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_8_44$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_8_44$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_8_44$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_8_44$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_8_44$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_TABLE_CODE_48_44120$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_48_44120$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_48_44120$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_48_44120$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_48_44120$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_48_44120$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_48_44120$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_48_44120$$ZI$$Length),
            },

            {
                (uint32)(&Load$$SRC_TABLE_CODE_44_44120$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_44_44120$$Base),
                (uint32)(&Image$$SRC_TABLE_CODE_44_44120$$Length),

                (uint32)(&Load$$SRC_TABLE_DATA_44_44120$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_44_44120$$RW$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_44_44120$$RW$$Length),

                (uint32)(&Image$$SRC_TABLE_DATA_44_44120$$ZI$$Base),
                (uint32)(&Image$$SRC_TABLE_DATA_44_44120$$ZI$$Length),
            },

            //BT init script
            {
                (uint32)(&Load$$BT_INIT_SCRIPT_CODE$$Base),
                (uint32)(&Image$$BT_INIT_SCRIPT_CODE$$Base),
                (uint32)(&Image$$BT_INIT_SCRIPT_CODE$$Length),

                (uint32)(0),
                (uint32)(0),
                (uint32)(0),

                (uint32)(0),
                (uint32)(0),
            },

        },
    },

    //系统默认参数
    {
        //系统参数
#ifdef _SDCARD_
        (uint32)1,      //UINT32 SDEnable;
#else
        (uint32)0,
#endif

#ifdef _RADIO_
        (uint32)1,      //UINT32 FMEnable;
#else
        (uint32)1,
#endif

        (uint32)KEY_NUM,//UINT32 KeyNum


        (uint32)2,      //UINT32 Langule;
        (uint32)13,     //UINT32 Volume;

        (uint32)1,      //UINT32 BLMode;
        (uint32)2,      //UINT32 BLevel;
        (uint32)1,      //UINT32 BLtime;

        (uint32)0,      //UINT32 SetPowerOffTime;
        (uint32)0,      //UINT32 IdlePowerOffTime;

        //Music参数
        (uint32)1,      //UINT32 MusicRepMode;
        (uint32)0,      //UINT32 MusicPlayOrder;
        (uint32)7,      //UINT32 MusicEqSel;

        //Video参数

        //Radio参数
        (uint32)0,      //UINT32 FMArea;
        (uint32)0,      //UINT32 FMStereo;
        (uint32)0,      //UINT32 FMScanSensitivity;

        //Record参数

        //Picture参数
        (uint32)2,      //UINT32 PicAutoPlayTime;

        //Text参数
        (uint32)2,      //UINT32 TextAutoPlayTime;

        //Image ID
        (uint32)0,

#ifdef _BLUETOOTH_
        //BT参数
        "RKNANOD_XX",   //local bt device name.
#endif
        //多国语言选择
        (uint32)TOTAL_MENU_ITEM,    //最大菜单项
        (uint32)TOTAL_LANAUAGE_NUM, //uint32 LanguageTotle, 实际最大多国语言个数
        //语言配置表                //最多可支持64国语言
        {
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //8
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //16
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //24
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //32
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //40
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //48
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //56
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //64
        },
    },

    //FM 参数及驱动程序列表
    {
        (uint32)1,      //FMDriverID;
        (uint32)FM_DRIVER_MAX,

        //FM Driver List
#ifdef _RADIO_
        {
            //FM5767
            {
                Qn8035_Tuner_SetInitArea,
                Qn8035_Tuner_SetFrequency,
                Qn8035_Tuner_SetStereo,
                Qn8035_Tuner_Vol_Set,

                Qn8035_Tuner_PowerOffDeinit,
                Qn8035_Tuner_SearchByHand,
                Qn8035_Tuner_PowerDown,
                Qn8035_Tuner_MuteControl,
                Qn8035_GetStereoStatus,
            },

            //FM5807
            {
                FM5807_Tuner_SetInitArea,
                FM5807_Tuner_SetFrequency,
                FM5807_Tuner_SetStereo,
                FM5807_Tuner_Vol_Set,

                FM5807_Tuner_PowerOffDeinit,
                FM5807_Tuner_SearchByHand,
                FM5807_Tuner_PowerDown,
                FM5807_Tuner_MuteControl,
                FM5807_GetStereoStatus,

            },
        },
#else
        {
            //FM5767
            {
                0,
                0,
                0,
                0,

                0,
                0,
                0,
                0,
                0,
            },

            //FM5807
            {
                0,
                0,
                0,
                0,

                0,
                0,
                0,
                0,
                0,

            },
        },
#endif
    },

    //LCD 参数及驱动程序列表
    {
        (uint32)1,      //LcdDriverID;

        (uint32)LCD_DRIVER_MAX,

        //LCD Driver List
        {
            {
                ST7735_WriteRAM_Prepare,
                ST7735_Init,
                ST7735_SendData,
                ST7735_SetWindow,
                ST7735_Clear,
                ST7735_DMATranfer,
                ST7735_Standby,
                ST7735_WakeUp,
                ST7735_MP4_Init,
                ST7735_MP4_DeInit,
                0,
                0,
                ST7735_ClrSrc,
                ST7735_ClrRect,
                0,
            },

            {
                ST7735S_WriteRAM_Prepare,
                ST7735S_Init,
                ST7735S_SendData,
                ST7735S_SetWindow,
                ST7735S_Clear,
                ST7735S_DMATranfer,
                ST7735S_Standby,
                ST7735S_WakeUp,
                ST7735S_MP4_Init,
                ST7735S_MP4_DeInit,
                0,
                0,
                ST7735S_ClrSrc,
                ST7735S_ClrRect,
                0,
            },
        },
    }
};

/*
--------------------------------------------------------------------------------
  Function name :
  Author        : ZHengYongzhi
  Description   : 模块信息表

  History:     <author>         <time>         <version>
             ZhengYongzhi     2008/07/21         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
__attribute__((section("START_CODE")))
void ScatterLoader(void)
{
    uint32 i,len;
    uint8  *pDest;

    //清除Bss段
    pDest = (uint8*)((uint32)(&Image$$SYS_DATA$$ZI$$Base));
    len = (uint32)((uint32)(&Image$$SYS_DATA$$ZI$$Length));
    for (i = 0; i < len; i++)
    {
        *pDest++ = 0;
    }
}
/*
********************************************************************************
*
*                         End of StartLoadTab.c
*
********************************************************************************
*/
