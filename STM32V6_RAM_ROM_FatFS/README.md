## 说明
1. 在`CubeMX`中配置时钟；
2. 在`RTT Settings`中使能`DFS`, `FATFS`；
3. 在`RTT Settings --> Components --> DFS:device virtual file system --> Using device virtual file system`中使能`Enable ReadOnly file system on flash`和`Enable RAM file system`；
4. 在`dfs_romfs.c`中的`_root_dirent`中添加一个`ramfs`的文件夹；
5. 添加[`main.c`](./applications/main.c)中的代码；
6. 编译下载运行；

## 注意
1. `ROM`文件系统是只读(`read-only`)的，不能写文件；（通过在`dfs_romfs.c`的`_root_dirent`可以设置初始化内容）
2. `RAM`文件系统中不能创建文件夹，只能创建并编辑文件；但是`RAM`的内容是掉电不保存的；
3. 在文件系统挂载时，只能挂载在当前已经存在的路径上；

