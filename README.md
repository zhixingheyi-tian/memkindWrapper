# memkindWrapper


## 编译
gcc -fPIC -shared -o libmemkind.so.0 nvmem_wrapper.c  -lnvmem -ljemalloc -L .

## 安装说明
1、 libmemkind.so.0 安放到系统可以感知到的搜索路径， 例如 /lib 或 /usr/lib 或 /lib64，因OS而定。 如过系统共享库搜索路径下存在社区版的libmemkind. 需替换。
2、 libnvmem.so libjemalloc.so.2, 这两个baidu 提供的库，如事先并未安装，可以放入libmemkind.so.0 的相同目录。
3、 运行命令 "ldconfig" 


