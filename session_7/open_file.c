#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char buf[100] = "Hello files";
    int fd = open("./hello.txt\n", O_CREAT | O_WRONLY, 0644);

    int size = strlen(buf);

    ssize_t ret = write(fd, buf, size);

    printf("Wrote %d",(int)ret); 

    close(fd);

    return 0;
}