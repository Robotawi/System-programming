#include <stdio.h>
#include <unistd.h>

// man getcwd

int main(int argc, char const *argv[])
{
    int buf_size = 50;
    char buf[buf_size];

    char *wdir = getcwd(buf, buf_size);

    while (wdir == NULL)
    {
        buf_size += 50;
        char extra_buf[buf_size];
        wdir = getcwd(buf, buf_size);
    }

    printf("current directory is: %s\n", wdir);

    return 0;
}
