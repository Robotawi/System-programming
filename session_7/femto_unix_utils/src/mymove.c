#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("Error: not enough arguments\n");
        printf("Usage: mymv source_file destination_file\n");
        exit(-1);
    }

    int src_fd = open(argv[1], O_RDONLY);
    int dst_fd = open(argv[2], O_CREAT | O_WRONLY, 0644);

    int buf_size = 100;
    char buf[buf_size];

    ssize_t read_bytes;
    ssize_t write_status = 0;

    while (read_bytes = read(src_fd, buf, buf_size))
    {
        write_status = write(dst_fd, buf, read_bytes);

        if (write_status == -1)
        {
            printf("Error: can not write on the specified destination\n");
            close(src_fd);
            close(dst_fd);
            exit(-1);
        }
    }

    close(src_fd);

    int remove_status = remove(argv[1]);
    if (remove_status == -1)
    {
        printf("Error: source file can not be removed.\n");
        close(dst_fd);
        exit(-1);
    }

    close(dst_fd);

    return 0;
}
