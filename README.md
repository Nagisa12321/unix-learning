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
#### difference between dup and open? 
- dup只是复制文件描述符， 没有复制文件表项， 因此两个文件描述符的文件表项是同一个，所以他们的文件打开标志是相同的， 文件偏移量也是相同的。 因此当你使用lseek的时候， 两个文件描述符指向的文件都会偏移一段距离。open会创建新的文件表项， 因此效果完全不一样。
