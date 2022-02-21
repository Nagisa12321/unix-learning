#include <apue.h>

int
main() {
    // pid type is a S32 type so 
    // it is int
    printf("hello world from process ID %d\n", getpid());
    return 0;
}
