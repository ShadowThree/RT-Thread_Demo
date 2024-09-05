## 说明
1. 在`CubeMX`中使能时钟，`SDIO`，以及`USB_OTG_FS(Device_Only)`；
2. 在`RTT Settings`使能`SDIO`, `DFS`, `FATFS`；
3. 在`RTT Settings --> Components --> Device Drivers --> Using USB`中，使能`Using USB device`，在`Device type`中选择`MSC`，并将`msc class disk name`改为`sd0`；
4. 在`board.h`中使能`BSP_USING_SDIO`和`BSP_USING_USBDEVICE`宏定义；
5. 在`stm32f4xx_hal_conf_bak.h`中使能`HAL_SD_MODULE_ENABLED`和`HAL_PCD_MODULE_ENABLED`宏定义；
6. 在[main.c](./applications/main.c)中添加部分代码；
6. 然后编译，可能在`drv_usbd.c`文件中会出现`EP_MPS_64`未定义的错误；直接将`EP_MPS_64`改为`0`即可；
7. 编译下载运行，可以在`FinSH`中对`Udisk`进行操作；将开发板连上`PC`后，应该就可以看到`Udisk`的盘符了；