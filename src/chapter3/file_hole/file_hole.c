#include <apue.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
char buf3[16394] = { 0 };

int main() {
    int fd;

    if ((fd = creat("file_hole.txt", FILE_MODE)) < 0) {
        err_quit("creat error");
    }

    if (write(fd, buf1, 10) != 10) {
        err_quit("buf1 write error");
    }

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_quit("lseek error");
    }

    // 
    // offset now 16384
    // 
    if (write(fd, buf2, 10) != 10) {
        err_quit("buf2 write error");
    }
    //
    // Offset now 16394
    //

    if ((fd = creat("file_nohole.txt", FILE_MODE)) < 0) {
        err_quit("creat error");
    }

    for (int i = 0; i < 16394; ++i) {
        buf3[i] = 'a';
    }
    if (write(fd, buf3, 16394) != 16394) {
        err_quit("buf3 write error");
    }

    return 0;
}
