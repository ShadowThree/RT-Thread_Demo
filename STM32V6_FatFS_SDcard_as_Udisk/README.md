## ˵��
1. ��`CubeMX`��ʹ��ʱ�ӣ�`SDIO`���Լ�`USB_OTG_FS(Device_Only)`��
2. ��`RTT Settings`ʹ��`SDIO`, `DFS`, `FATFS`��
3. ��`RTT Settings --> Components --> Device Drivers --> Using USB`�У�ʹ��`Using USB device`����`Device type`��ѡ��`MSC`������`msc class disk name`��Ϊ`sd0`��
4. ��`board.h`��ʹ��`BSP_USING_SDIO`��`BSP_USING_USBDEVICE`�궨�壻
5. ��`stm32f4xx_hal_conf_bak.h`��ʹ��`HAL_SD_MODULE_ENABLED`��`HAL_PCD_MODULE_ENABLED`�궨�壻
6. ��[main.c](./applications/main.c)����Ӳ��ִ��룻
6. Ȼ����룬������`drv_usbd.c`�ļ��л����`EP_MPS_64`δ����Ĵ���ֱ�ӽ�`EP_MPS_64`��Ϊ`0`���ɣ�
7. �����������У�������`FinSH`�ж�`Udisk`���в�����������������`PC`��Ӧ�þͿ��Կ���`Udisk`���̷��ˣ�