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
