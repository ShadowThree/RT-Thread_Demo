/*
 * Copyright (c) 2006-2024, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-09-04     RT-Thread    first version
 */

#include <rtthread.h>
#include <dfs_fs.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

int clock_information(void);

int main(void)
{
    int count = 1;

    clock_information();

    rt_thread_mdelay(500);
    if(dfs_mount("sd0", "/", "elm", 0, 0) == 0) {
        LOG_D("SDcard mount OK");
    } else {
        LOG_E("SDcard mount err");
    }

    while (count++)
    {
        //LOG_D("Hello RT-Thread!");
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}
