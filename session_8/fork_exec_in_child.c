#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//make a fork (child process) and execve inside it a command The execve command replaces the child in memory.

int main(int argc, char *argv[])
{
    printf("The parent process ID is %d\n\n", getpid());

    int ret_pid = fork();

    if (ret_pid > 0)
    {
        while (1)
        {
            printf("This is the (parent) with ID %d. My child's ID is %d\n", getpid(), ret_pid);
            sleep(1);
        }
    }
    else if (ret_pid == 0)
    {
        while (1)
        {   
            //on success, the /bin/ls replaces the child process in memory and finishes. The child is no more! 
            //on failure, the child keeps printing as they while loop keep going 
            printf("This is the (child) with ID %d. My parent's ID is %d\n", getpid(), getppid());
            
            char* newargv[] = {"/bin/ls", NULL};
            char* const newenvp[] = {NULL};

            execve("/bin/ls", newargv, newenvp); //to try the failure case, give a wrong command like /bin/lsssss

            sleep(1);
        }
    }
    else
    {
        printf("Fork failed!\n");
        exit(-1);
    }

    return 0;
}
