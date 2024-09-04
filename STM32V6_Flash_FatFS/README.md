## 说明
1. 在`CubeMx`中配置时钟，以及和外部`Flash`芯片连接的`SPI3`接口；
2. 在`RTT Settings`中使能`SFUD`, `SPI`, `Ulog`, `DFS`, `FATFS`；
3. 将`RTT Settings --> Components --> DFS:device virtual file system --> Using device virtual file system --> Enable elm-chan fatfs --> elm-chan's FatFs,Generic FAT Filesystem Module`中的`Maximum sector size to be handled`设置为`4096`；
4. 在`board.h`中使能`BSP_USING_SPI3`宏定义；
5. 添加[`main.c`](./applications/main.c)中的代码；
6. 编译下载运行；