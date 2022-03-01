#include <apue.h>
#include <limits.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void show_mode(mode_t mode) {
    if (mode & S_IRGRP) printf("r");
    else printf("-");
    if (mode & S_IWGRP) printf("w");
    else printf("-");
    if (mode & S_IXGRP) printf("x");
    else printf("-");

    if (mode & S_IROTH) printf("r");
    else printf("-");
    if (mode & S_IWOTH) printf("w");
    else printf("-");
    if (mode & S_IXOTH) printf("x");
    else printf("-");

}

int main() {
    //     
    // Get current path
    //     
    char current_path[PATH_MAX] = { 0 };
    if (getcwd(current_path, PATH_MAX) != NULL) {
        printf("current path is %s\n", current_path);
    }

    DIR *dp;
    struct dirent *dirp;
    if ((dp = opendir(current_path)) == NULL) {
        err_quit("can not open %s", current_path);
    }

    // 
    // Get every file in current path 
    // 
    while ((dirp = readdir(dp)) != NULL) {
        const char *file_name = dirp->d_name;
        struct stat *file_stat;
        
        char file_path[PATH_MAX] = { 0 };
        strcpy(file_path, current_path);
        strcat(file_path, file_name);

        // get teh file state
        stat(file_path, file_stat);

        // deal with the file mode
        show_mode(file_stat->st_mode);

        putchar(' ');
        printf("%s", file_name);
        putchar('\n');
    }

    return 0;    
}