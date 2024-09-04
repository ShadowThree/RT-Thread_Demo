# 基于`RT-Thread Studio`的`RT-Thread`例程

## 说明
1. 如果通过`RTT Studio`新建工程后编译出错，可以在`RTT settings --> Components`中使能`Surport legacy version for compatibility`试试；
2. 如果没有特殊说明，这些例程大都是基于安富莱的`STM32V6`开发板；
3. 如果没有特殊说明，这些工程都是`Base On MCU`，而不是`Base On Board`;
4. 可以在`main.c`开始时调用`clock_information()`输出时钟配置信息，以确认时钟配置是否正确；（`drv_clk.c`文件中的`DBG_LVL`宏需要改为`DBG_LOG`）
5. 将例程导入`RTT Studio`即可正常编译下载运行；

## 例程
1. [STM32V6_LED_Blinky](./STM32V6_LED_Blinky/)
2. [STM32V6_Flash_FatFS](./STM32V6_Flash_FatFS/)
3. [STM32V6_SDcard_FatFS](./STM32V6_SDcard_FatFS/)
4. [STM32V6_RAM_ROM_FatFS](./STM32V6_RAM_ROM_FatFS/)