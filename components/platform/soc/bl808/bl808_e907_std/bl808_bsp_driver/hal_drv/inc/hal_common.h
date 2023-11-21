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
#ifndef __HAL_COMMON__H__
#define __HAL_COMMON__H__

#include "bl808_common.h"

typedef enum {
    HAL_REBOOT_AS_BOOTPIN,           /*!< reboot as bootpin level */
    HAL_REBOOT_FROM_INTERFACE,       /*!< reboot from interface, download mode */
    HAL_REBOOT_FROM_MEDIA,           /*!< reboot from media, running mode */
    HAL_REBOOT_MAX                   /*!< reboot max value */
} hal_reboot_cfg_t;

void cpu_global_irq_enable(void);
void cpu_global_irq_disable(void);
void hal_por_reset(void);
void hal_system_reset(void);
void hal_cpu_reset(void);
void hal_reboot_config(hal_reboot_cfg_t rbot);
void hal_get_chip_id(uint8_t chip_id[8]);
void hal_dcache_clean_all(void);
void hal_dcache_invalid_all(void);
void hal_dcache_clean_invalid_all(void);
void hal_dcache_clean_byaddr(uintptr_t addr, uint32_t len);
void hal_dcache_invalidate_byaddr(uintptr_t addr, uint32_t len);
void hal_dcache_clean_invalidate_byaddr(uintptr_t addr, uint32_t len);

#endif