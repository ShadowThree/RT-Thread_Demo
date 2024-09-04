# 说明
1. 通过`CubeMX`配置时钟，并使能`SDIO`；
2. 在`RTT Settings`中使能`SDIO`, `DFS`, `FATFS`；
3. 在`board.h`中使能`BSP_USING_SDIO`宏定义；
4. 在`drivers --> stm32f4xx_hal_conf_bak.h`中使能`HAL_SD_MODULE_ENABLED`宏定义；
5. 添加[`main.c`](./applications/main.c)中的代码；
6. 编译下载运行；
