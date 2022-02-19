#include "apue.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void err_sys(const char *s, ...) {
    va_list argptr;
    va_start(argptr, s);
    char tmp[STRING_MAX_MENGTH] = { 0 };
    strcat(tmp, s);
    strcat(tmp, "\n");
    printf(tmp, argptr);
    va_end(argptr);
}

void err_quit(const char *s, ...) {
    va_list argptr;
    va_start(argptr, s);
    err_sys(s, argptr);
    va_end(argptr);
    exit(-1);
}

