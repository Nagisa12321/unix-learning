#include <apue.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd; 

    if ((fd = open("./test.txt", O_APPEND | O_RDWR)) == 0) {
        err_quit("open error");
    }

    lseek(fd, 'k' - 'a', SEEK_SET);

    char k = 'K';
    write(fd, &k, 1);

    close(fd);
}