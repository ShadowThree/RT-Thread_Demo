/*
 * Copyright (c) 2006-2024, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-09-03     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#include "drv_spi.h"
#include "spi_flash_sfud.h"
#include <dfs_fs.h>

int clock_information(void);

int main(void)
{
    int count = 1;
    sfud_flash_t sf;
    uint8_t data[10];

    clock_information();

    // access the extFlash by SPI directly
    sf = rt_sfud_flash_find("spi3_0");
    if(sf == NULL) {
        LOG_E("find SPI3_0 dev err");
    } else {
        sfud_read(sf, 0, 10, (uint8_t*)data);
        LOG_HEX("test", 16, data, 10);
    }

    // access the extFlash by FatFS
    dfs_mkfs("elm", "extFlash");
    if(0 == dfs_mount("extFlash", "/", "elm", 0, 0)) {
        LOG_D("extFlash mount OK");
    } else {
        LOG_E("extFlash mount err");
    }

    while (count++)
    {
        //LOG_D("Hello RT-Thread!");
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}

static int rt_hw_spi_flash_init(void)
{
    rt_hw_spi_device_attach("spi3", "spi3_0", GPIOD, GPIO_PIN_13);

    if(RT_NULL == rt_sfud_flash_probe("extFlash", "spi3_0")) {
        return -RT_ERROR;
    }
    return RT_EOK;
}
INIT_COMPONENT_EXPORT(rt_hw_spi_flash_init);
