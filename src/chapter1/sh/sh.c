#include <apue.h>
#include <sys/wait.h>

int main() {
    char buf[MAXLINE] = { 0 };
    pid_t pid;
    int status; 

    printf("jt%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0) {
            err_quit("fork error!");
        } else if (pid == 0) {
            execlp(buf, buf, (char *) 0);
            err_quit("couldn't execute: %s", buf);
        }

        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }

        printf("jt%% ");
    }

    return 0;
}
