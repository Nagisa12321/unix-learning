#ifndef _APUE_H_
#define _APUE_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STRING_MAX_MENGTH 512
#define MAXLINE 512

void err_sys(const char *s, ...);
void err_quit(const char *s, ...);

#endif
