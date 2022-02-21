#include <apue.h>
#include <dirent.h>

#define MAX_FILE_NAME 1024

void helper(int deep, const char *filename) {
    DIR             *dp = 0;
    struct dirent   *dirp = 0;
    int             i = 0;
    char            tmp_file_name[MAX_FILE_NAME] = { 0 };
    

    if ((dp = opendir(filename)) == NULL) {
        return;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, "..") != 0 && strcmp(dirp->d_name, ".") != 0) {
            for (i = 0; i < deep; ++i) {
                printf("-");
            }
            printf("%s\n", dirp->d_name);
            memset(tmp_file_name, 0, MAX_FILE_NAME);
            strcpy(tmp_file_name, filename);
            strcat(tmp_file_name, "/");
            strcat(tmp_file_name, dirp->d_name);
            helper(deep + 1, tmp_file_name);
        }
    }

    closedir(dp);
}

int
main(int argc, char **argv) {
    DIR             *dp;
    struct dirent   *dirp;

    if (argc != 2) {
        err_quit("usage: tree directory name", 1);
    }

    helper(0, argv[1]);
}
