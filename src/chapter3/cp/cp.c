#include <apue.h>

#define BUFFERSIZE 4096

int main(int argc, char **argv) {
    int n;
    char buf[BUFFERSIZE];
    int fd_dest, fd_src;

    if (argc != 3) {
        err_quit("use ./cp a b");
    }
    
    fd_src = open(argv[1], O_RDONLY);
    fd_dest = open(argv[2], O_CREAT | O_WRONLY);

    while ((n = read(fd_src, buf, BUFFERSIZE)) != 0) {
        if (n == -1) {
            err_quit("read error");
        }

        if (write(fd_dest, buf, n) != n) {
            err_quit("write error");
        }
    }

    return 0;
}
