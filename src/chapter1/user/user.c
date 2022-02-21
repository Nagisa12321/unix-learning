#include <apue.h>

void exit_hook() {
    printf("exit. \n");
}

int main() {
    printf("uid = %d, qid = %d\n", getuid(), getgid());
    atexit(exit_hook);
    exit(0);
}
