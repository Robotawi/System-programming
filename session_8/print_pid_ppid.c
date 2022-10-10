#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{   
    getchar(); //stop to see this process and the parent process IDs in another terminal
    printf("This process ID is %d, and parent process IS is %d\n",getpid(), getppid());
    return 0;
}
