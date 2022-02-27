#include <apue.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    int val;

    if (argc != 2) {
        err_quit("usage: a.out <descriptor#>");
    }

    // return the file state
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) == -1) {
        err_quit("fcntl err for fd %d", atoi(argv[1]));
    }

    switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read and write");
            break;
        default:
            err_quit("unknown access mode");
    }

    if (val & O_APPEND) {
        printf(", append");
    }
    if (val & O_NONBLOCK) {
        printf(", noblocking");
    }
    if (val & O_SYNC) {
        printf(", synchronous writes");
    }

    putchar('\n');
    return 0;
}
