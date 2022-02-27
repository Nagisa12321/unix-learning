#include <apue.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/file.h>

// 
// Close fd2
// copy fd1 with it. 
//
int my_dup2(int fd1, int fd2) { 
}

int main() {
    int new_std_out = 3;

    if (my_dup2(STDOUT_FILENO, new_std_out) == -1) {
        err_quit("my dup2 error");
    }

    write(new_std_out, "hello world\n", 12);

    return 0;
}
