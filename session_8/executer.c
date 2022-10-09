#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *newargv[] = {NULL};
    char *newenvp[] = {NULL};

    if (argc != 2)
    {
        printf("Error: wrong number of arguments\n");
        printf("Usage: executer /bin/ls\n");
        exit(-1);
    }

    int exec_status = execve(argv[1], newargv, newenvp);
    
    printf("Program %s execution failed!\n",argv[1]);

    return 0;
}