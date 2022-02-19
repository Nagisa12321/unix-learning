#include <apue.h>
#include <stddef.h>
#include <dirent.h>

int 
main(int argc, char **argv) {
    DIR             *dp;
    struct dirent   *dirp;

    if (argc != 2) {
        err_quit("usage: ls directory name", 1);
    }

    if ((dp = opendir(argv[1])) == NULL) {
        
    }
}
