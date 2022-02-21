#include <apue.h>

#define BUFFSIZE 4096

int 
main() {
    int n;
    char buff[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buff, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buff, n) != n) {
            err_quit("write error!");
        }
    }

    if (n < 0) {
        err_quit("read error!");
    }

    return 0;
}
