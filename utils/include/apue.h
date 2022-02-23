#ifndef _APUE_H_
#define _APUE_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define STRING_MAX_MENGTH 512

#define MAXLINE 4096 /* max line length */

/*
* Default file access permissions for new files.
*/
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*
* Default permissions for new directories.
*/
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

void err_sys(const char *s, ...);
void err_quit(const char *s, ...);

#endif
