## ˵��
1. ��`CubeMx`������ʱ�ӣ��Լ����ⲿ`Flash`оƬ���ӵ�`SPI3`�ӿڣ�
2. ��`RTT Settings`��ʹ��`SFUD`, `SPI`, `Ulog`, `DFS`, `FATFS`��
3. ��`RTT Settings --> Components --> DFS:device virtual file system --> Using device virtual file system --> Enable elm-chan fatfs --> elm-chan's FatFs,Generic FAT Filesystem Module`�е�`Maximum sector size to be handled`����Ϊ`4096`��
4. ��`board.h`��ʹ��`BSP_USING_SPI3`�궨�壻
5. ���[`main.c`](./applications/main.c)�еĴ��룻
6. �����������У�