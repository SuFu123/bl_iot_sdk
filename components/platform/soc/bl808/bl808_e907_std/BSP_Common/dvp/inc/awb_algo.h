/*
 * Copyright (c) 2016-2023 Bouffalolab.
 *
 * This file is part of
 *     *** Bouffalolab Software Dev Kit ***
 *      (see www.bouffalolab.com).
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of Bouffalo Lab nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __AWB_ALGO_H__
#define __AWB_ALGO_H__

#include <bl808_isp.h>
#include "bl_comm_sns.h"
#include "bl_comm_aaa.h"

#define COLOR_TEMP_D75      ((BL_COLOR_TEMP)7500)
#define COLOR_TEMP_D65      ((BL_COLOR_TEMP)6500)
#define COLOR_TEMP_D50      ((BL_COLOR_TEMP)5000)
#define COLOR_TEMP_CWF      ((BL_COLOR_TEMP)4150)
#define COLOR_TEMP_TL84     ((BL_COLOR_TEMP)4000)
#define COLOR_TEMP_A        ((BL_COLOR_TEMP)2856)
#define COLOR_TEMP_H        ((BL_COLOR_TEMP)2300)

#define AWB_UPDATE_BIT_MODE             (1 << 0)
#define AWB_UPDATE_BIT_COLOR_TEMP       (1 << 1)

typedef enum {
    AWB_MODE_AUTO = 0,
    AWB_MODE_LOCK,
    AWB_MODE_NUM,
} AWB_MODE;

typedef enum {
    AWB_ALGO_GREY_WORLD = 0,
    AWB_ALGO_1, // sw white world
    AWB_ALGO_2, // hw white world, freddy
    AWB_ALGO_NUM
} AWB_ALGO;

typedef struct {
    aaa_stats_cfg_t stats_cfg;
} awb_config_t;

typedef struct {
    AWB_MODE          awb_mode;
    uint32_t          rb_gain_update;
    uint32_t          ct_update;
    ISP_RB_Gain_Type  rb_gain;
    ISP_RB_Gain_Type  rb_bias;
    BL_COLOR_TEMP     color_temp;
}awb_info_t;

typedef struct {
    int (*config)(awb_config_t *config, bool is_virtual_sensor);
    int (*control)(void);
    int (*get_info)(awb_info_t **awb_info);
    int (*set_mode)(AWB_MODE mode);
    int (*get_mode)(AWB_MODE *mode);
    int (*set_gain)(ISP_RGB_Gain_Type *rgb_gain);
    int (*get_gain)(ISP_RGB_Gain_Type *rgb_gain);
    int (*set_color_temp)(BL_COLOR_TEMP color_temp);
    int (*get_color_temp)(BL_COLOR_TEMP *color_temp);
} awb_func_t;

int awb_init(AWB_ALGO algo);
int awb_config(awb_config_t *config, bool is_virtual_sensor);
int awb_control(void);
int awb_get_info(awb_info_t **awb_info);

int awb_set_mode(AWB_MODE mode);
int awb_get_mode(AWB_MODE *mode);

int awb_set_gain(ISP_RGB_Gain_Type *rgb_gain);
int awb_get_gain(ISP_RGB_Gain_Type *rgb_gain);

/* for debug purpose only */
int awb_set_color_temp(BL_COLOR_TEMP color_temp);
int awb_get_color_temp(BL_COLOR_TEMP *color_temp);


#endif  //__AWB_ALGO_H__
