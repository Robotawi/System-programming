#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("The parent process ID is %d\n\n",getpid());

    int ret_pid = fork();

    if(ret_pid > 0){
        printf("This is the (parent) with ID %d. My child's ID is %d\n", getpid(), ret_pid);
    }else if (ret_pid == 0)
    {
        printf("This is the (child) with ID %d. My parent's ID is %d\n", getpid(), getppid());
    }else{
        printf("Fork failed!\n");
        exit(-1);
    }
    
    return 0;
}
