## ˵��
1. ��`CubeMX`������ʱ�ӣ�
2. ��`RTT Settings`��ʹ��`DFS`, `FATFS`��
3. ��`RTT Settings --> Components --> DFS:device virtual file system --> Using device virtual file system`��ʹ��`Enable ReadOnly file system on flash`��`Enable RAM file system`��
4. ��`dfs_romfs.c`�е�`_root_dirent`�����һ��`ramfs`���ļ��У�
5. ���[`main.c`](./applications/main.c)�еĴ��룻
6. �����������У�

## ע��
1. `ROM`�ļ�ϵͳ��ֻ��(`read-only`)�ģ�����д�ļ�����ͨ����`dfs_romfs.c`��`_root_dirent`�������ó�ʼ�����ݣ�
2. `RAM`�ļ�ϵͳ�в��ܴ����ļ��У�ֻ�ܴ������༭�ļ�������`RAM`�������ǵ��粻����ģ�
3. ���ļ�ϵͳ����ʱ��ֻ�ܹ����ڵ�ǰ�Ѿ����ڵ�·���ϣ�

