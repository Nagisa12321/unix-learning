#include <apue.h>
#include <fcntl.h>

void set_fl(int fd, int flag) {
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) == -1) {
        err_quit("fcntl F_GETFL error");
    }

    val |= flag;

    if (fcntl(fd, F_SETFL, val) == -1) {
        err_quit("fcntl F_SETFL error");
    }
}

int main() {
    return 0; 
}
