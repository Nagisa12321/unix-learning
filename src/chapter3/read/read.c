#include <apue.h>

int main(int argc, char **argv) {
    int fd;
    char buffer[64] = { 0 };
    int bytes_read;

    if (argc != 2) {
        err_quit("use ./read filename");
    }

    fd = open(argv[1], O_RDONLY);
    
    while ((bytes_read = read(fd, buffer, 64)) != 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }
}
