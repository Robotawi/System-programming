#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//show that the parent and child processes has initially the same address space (contents).\
but everyone has its own process address space / virtual memory

int main(int argc, char *argv[])
{
    printf("The parent process ID is %d\n\n",getpid());

    int x = 0;
    int y = 0;
    int z = 0;

    int ret_pid = fork();

    if(ret_pid > 0){
        while(1){
            printf("This is the (parent) with ID %d. My child's ID is %d\n", getpid(), ret_pid);
            printf("(x, y, z) = (%d, %d, %d)\n\n",++x, ++y, ++z);
            sleep(1);
        }
        
    }else if (ret_pid == 0)
    {   
        while(1){
            printf("This is the (child) with ID %d. My parent's ID is %d\n", getpid(), getppid());
            x++; x++;
            y++; y++;
            z++; z++;
            printf("(x, y, z) = (%d, %d, %d)\n\n",++x, ++y, ++z);
            sleep(1);
        }
        
    }else{
        printf("Fork failed!\n");
        exit(-1);
    }
    
    return 0;
}
