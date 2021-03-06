/*
********************************************************************************************
*
*				  Copyright (C),2004-2015, Fuzhou Rockchip Electronics Co.,Ltd.
*							   All rights reserved.
*
* FileName: Cpu\NanoC\lib\hw_yuv2rgb.h
* Owner: WJR
* Date: 2014.11.12
* Time: 10:55:28
* Desc:
* History:
*    <author>	 <date> 	  <time>	 <version>	   <Desc>
*    WJR     2014.11.12     10:55:28   1.0
********************************************************************************************
*/

#ifndef __CPU_NANOC_LIB_HW_YUV2RGB_H__
#define __CPU_NANOC_LIB_HW_YUV2RGB_H__

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/
//#include "SysInclude.h"
//#ifdef __CPU_NANOC_LIB_HW_YUV2RGB_C__

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/
//#include "LcdInterface.h"
//#include "vop.h"
//#include "yuv2rgb.h"
//#include "Hw_vop.h"
//#include "dma.h"

#define DMA_TRAN
/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/

#define YUV_VERSION_0   1
#define YUV_VERSION_1   2
#define YUV_VERSION_2   3

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   global variable declare
*
*---------------------------------------------------------------------------------------------------------------------
*/
#if(LCD_WIDTH == 160 ||(LCD_WIDTH == 128))
#define VOP_HEIGNT 128
#define VOP_WIDTH  160
#else
#define VOP_HEIGNT 240//128
#define VOP_WIDTH  320//160
#endif 


/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API Declare
*
*---------------------------------------------------------------------------------------------------------------------
*/
extern rk_err_t Rgb565Write(uint32  VopId,uint32 Addr, uint32 width, uint32 Height);
extern rk_err_t  RgbWrite(uint32  VopId,uint32 Addr, uint32 width, uint32 Height);
extern void send_UVY_data(uint32 *src);
extern void send_Y_UV_data(uint32 *pst_y,uint32 *pst_uv);
extern void send_rgb_data(uint16 *src);
extern rk_err_t YuvSetMode(uint32 RawFormat, uint32 Version);
extern rk_err_t YuvWrite(uint32  VopId,uint32 Addr,uint32 width, uint32 Height);
extern rk_err_t YuvLlpWrite(uint32  VopId,uint32  Yaddr,uint32 UvAddr, uint32 width, uint32 Height);
extern rk_err_t hw_yuv2rgb_shell(void);


#endif

