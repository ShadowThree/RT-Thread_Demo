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

#include <drv_common.h>

#define PIN_D5  GET_PIN(D, 5)
#define PIN_G0  GET_PIN(G, 0)
#define PIN_G1  GET_PIN(G, 1)
#define PIN_G9  GET_PIN(G, 9)

#define LED1 GET_PIN(E, 11)
#define LED2 GET_PIN(E, 12)
#define LED3 GET_PIN(E, 13)
#define LED4 GET_PIN(E, 14)

#define KEY1 GET_PIN(I, 8)
#define KEY2 GET_PIN(C, 13)
#define KEY3 GET_PIN(H, 4)

uint32_t HAL_RCC_GetSysClockFreq(void);
int clock_information(void);

int main(void)
{
    int count = 1;

    clock_information();

    rt_pin_mode(PIN_D5, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_G0, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_G1, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_G9, PIN_MODE_OUTPUT);
    rt_pin_mode(LED1, PIN_MODE_OUTPUT);
    rt_pin_mode(LED2, PIN_MODE_OUTPUT);
    rt_pin_mode(LED3, PIN_MODE_OUTPUT);
    rt_pin_mode(LED4, PIN_MODE_OUTPUT);
    rt_pin_mode(KEY1, PIN_MODE_INPUT);
    rt_pin_mode(KEY2, PIN_MODE_INPUT);
    rt_pin_mode(KEY3, PIN_MODE_INPUT);

    rt_pin_write(PIN_D5, PIN_LOW);
    rt_pin_write(PIN_G0, PIN_HIGH);
    rt_pin_write(PIN_G1, PIN_LOW);
    rt_pin_write(PIN_G9, PIN_LOW);

    while (count++)
    {
        //LOG_D("Hello RT-Thread! tick[%d]", count);
        rt_pin_write(LED1, PIN_HIGH);
        rt_pin_write(LED2, PIN_HIGH);
        rt_pin_write(LED3, PIN_HIGH);
        rt_pin_write(LED4, PIN_HIGH);
        rt_pin_write(PIN_D5, PIN_HIGH);
        rt_pin_write(PIN_D5, PIN_LOW);
        rt_thread_mdelay(500);
        LOG_D("key1[%d] key2[%d] key3[%d]", rt_pin_read(KEY1), rt_pin_read(KEY2), rt_pin_read(KEY3));

        rt_pin_write(LED1, PIN_LOW);
        rt_pin_write(LED2, PIN_LOW);
        rt_pin_write(LED3, PIN_LOW);
        rt_pin_write(LED4, PIN_LOW);
        rt_pin_write(PIN_D5, PIN_HIGH);
        rt_pin_write(PIN_D5, PIN_LOW);
        rt_thread_mdelay(500);
        LOG_D("key1[%d] key2[%d] key3[%d]", rt_pin_read(KEY1), rt_pin_read(KEY2), rt_pin_read(KEY3));
    }

    return RT_EOK;
}
