## Exercises

### chapter1

#### 1.1
- ..代表上一级目录,  .代表级目录

#### 1.2 
- unix是多进程系统， 在此期间执行了两个进程， 无法判断是什么！

#### 1.3
- 可以看到perror传入的参数是const char *，因为如果传入char *代表有可能在这个函数里面改变参数的值。然而这个函数的本意是之都函数， 因此不符合。
- strerror传入的是一个int， 因为C是按值传递参数， 不存在修改其值。

#### 1.4 
- power(2, 31) / 60 / 60 / 24 / 365 + 1970 = 2038.096259766616 年
- 使用time_t(long long)

#### 1.5
- power(2, 31) / 100 / 60 / 60 / 24 = 248.55134814814812 天

### chapter2

#### 2.1 
- 采用宏来编写: 
```c
#ifndef xxx
#define xxx

// some define

#endif
```

#### 2.2
- clock_t       : unsigned long
- dev_t         : int
- fpos_t        : long long
- gid_t         : unsigned int
- ino_t         : unsigned long long
- mode_t        : unsigned short
- nlink_t       : unsigned short
- off_t         : long long
- pid_t         : int
- ptrdiff_t     : long int
- size_t        : long unsigned int
- ssize_t       : long
- time_t        : long
- wchar_t       : int

#### 2.3
- [code](./src/chapter2/open_max/open_max.c)

### chapter 3

#### 3.1 
- 是带缓冲机制的。 只是不在用户级别的缓冲而已。举个例子：write。会将相应磁盘块编号放进系统的写队列之中然后返回。唯独加上fsync会等待写磁盘结束在返回。可以参考电梯算法内核写数据是按照一定规律写的。不然会导致写效率慢。另外还有写log机制。这种跟文件系统关联极为密切。

#### 3.2 
- [code](./src/chapter3/dup2/dup2.c)

#### 3.3 
- F_SETFD: 只会影响fd1本身
- F_SETFL: 涉及文件状态标志的更改, 会影响指向相同文件描述表的文件描述符, 因此fd1, fd2均会被影响
- [code](./src/chapter3/fd_fl_test/fdfl.c)

#### 3.4
- 这段代码的目的是: 把程序的输入，输出，错误流都重定向到fd之上
- if (fd > 2) 才会关闭流。因为我们不想随便关闭0，1，2.

#### 3.5 
```
./a.out > outfile 2>&1
```
- 执行a.out, 把标准输出重定向到outfile对应fd`dup2(out_fd, stdout)`, 因此现在1就是out_fd, 然后重定向2到1, 因此现在错误流也会重定向到outfile。
```
./a.out 2>&1 > outfile 
```
- 执行a.out, 先把标准错误流重定向到标准输出`dup2(stdout, stderr)`, 然后再把标准输出重定向到outfile, 但是stderr原本的fd还是指向标准输出, 因此会把stdout的输出输入到文件中, 把原来stderr的输出以标准输出的形式输出到终端之上。
- [code](./src/chapter3/stdout_stderror/outanderror.c)

#### 3.6
- 答案是可以在任意位置读。但是只能在尾端写
- [code](./src/chapter3/test_lseek/lseek.c)

