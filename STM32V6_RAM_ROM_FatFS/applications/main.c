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
#include <dfs_ramfs.h>
#include <dfs_romfs.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

static char ramfs_buf[10*1024];
int clock_information(void);

int main(void)
{
    int count = 1;

    clock_information();

    if(0 == dfs_mount(RT_NULL, "/", "rom", 0, &(romfs_root))) {
        LOG_D("ROM mount OK");
    } else {
        LOG_E("ROM mount err");
    }

    if(0 == dfs_mount(RT_NULL, "/ramfs", "ram", 0, dfs_ramfs_create((uint8_t*)ramfs_buf, sizeof(ramfs_buf)))) {
        LOG_D("RAM mount OK");
    } else {
        LOG_E("RAM mount err");
    }

    while (count++)
    {
        //LOG_D("Hello RT-Thread!");
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}
