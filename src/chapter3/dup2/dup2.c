#include <apue.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/file.h>

// 
// Close fd2
// copy fd1 with it. 
//
int my_dup2(int fd1, int fd2) { 
    int max_open[FOPEN_MAX] = { 0 };
    int idx = 0, fd;
    if (fd2 == fd1) return fd1;

    // 
    // If it is open. 
    // Close it... 
    // 
    close(fd2);

    while ((fd = dup(fd1)) != fd2) {
        ++idx;
    }
    
    for (int i = 0; i < idx - 1; ++i) {
        close(fd2 - i - 1);
    }

    return fd2;
}

int main() {
    int new_std_out = 100;

    if (my_dup2(STDOUT_FILENO, new_std_out) == -1) {
        err_quit("my dup2 error");
    }

    write(new_std_out, "hello world\n", 12);

    return 0;
}
