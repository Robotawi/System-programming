#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// make a fork (child process) and execve inside it a user-provided command.
// The execvp command replaces the child in memory by the provided command.
// & provides evironment variables to the child process though the environ variable

int main(int argc, char *argv[])
{
    // printf("The parent process ID is %d\n\n", getpid());
    char input_buf[100];

    while (1)
    {
        printf("simple-shell > ");
        fgets(input_buf, 100, stdin);
        int input_size = strlen(input_buf);
        input_buf[input_size - 1] = 0;

        if (strlen(input_buf) == 0)
            continue;

        // if exit command is given, then exit the simple-shell
        //strcmp is good not to hassle with the null-terminated string! 

        int cmp_res = strcmp(input_buf, "exit");
        int parent_status;

        if (cmp_res == 0)
        {
            _exit(parent_status);
        }
        
        // if not exit, continue to execute the given command 
        int ret_pid = fork();

        if (ret_pid > 0)
        {

            int status = 0;
            wait(&status); // wait blocks till a child changes status

            // printf("%s exit status is %d\n", input_buf, WEXITSTATUS(status));
        }
        else if (ret_pid == 0)
        {
            char *newargv[] = {input_buf, NULL};
            char *newenvp[] = {NULL};

            int status = execvp(input_buf, newargv);

            if (status == -1)//check errno?
            { // must exit on failure not to keep the child running!
                printf("Execution of the program %s failed\n", input_buf);
                exit(-1);
            }
        }
        else
        {
            printf("Fork failed!\n"); //check errno? 
            exit(-1);
        }
    }

    return 0;
}
