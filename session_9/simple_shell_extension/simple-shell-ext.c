#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char input_buf[100];

    // env variables live though the prog life cycle
    int envvar_count = 0;
    char *envvar_keys[20];
    char *envvar_values[20];

    while (1)
    {
        printf("simple-shell > ");
        fgets(input_buf, 100, stdin);
        int input_size = strlen(input_buf);
        input_buf[input_size - 1] = 0;

        if (strlen(input_buf) == 0)
            continue;

        // if exit command is given, exit
        int cmp_res = strcmp(input_buf, "exit");
        int parent_status;

        if (cmp_res == 0)
        {
            _exit(parent_status);
        }

        // split the input on spaces
        char delim[] = " ";
        char *token = strtok(input_buf, delim);

        char *newargv[10];
        int newargc = 0;

        while (token)
        {
            newargv[newargc] = token;
            token = strtok(NULL, delim);
            newargc++;
        }
        newargv[newargc] = NULL;

        char command[50];
        strcpy(command, newargv[0]);

        // check if a built-in command is given
        char *eq_pos = strchr(command, '=');
        int cmd_set = strcmp(command, "set");
        int cmd_exp = strcmp(command, "export");

        if (eq_pos != NULL)
        {
            int idx = eq_pos - command;
            envvar_keys[envvar_count] = (char *)malloc(sizeof(idx + 1));
            strncpy(envvar_keys[envvar_count], command, idx);
            envvar_keys[envvar_count][idx] = '\0';

            envvar_values[envvar_count] = (char *)malloc(sizeof(strlen(command) - idx - 1));
            strncpy(envvar_values[envvar_count], command + idx + 1, strlen(command));
            
            envvar_count++;
        }
        else if (cmd_set == 0)
        {
            for (int i = 0; i < envvar_count; ++i)
            {
                printf("%s=%s\n", envvar_keys[i], envvar_values[i]);
            }
        }
        else if (cmd_exp == 0)
        {
            int envvar_cmp = -1;

            if (envvar_count == 0)
            {
                printf("Error: no environment variables are set\n");
                continue;
            }

            if (newargc == 1)
            {
                printf("Error: no environment variable is provided\n");
                printf("Usage: export var_name\n");
                continue;
            }

            int envvar_found = 0;
            for (int i = 0; i < envvar_count; i++)
            {
                if (strcmp(newargv[1], envvar_keys[i]) == 0)
                {
                    envvar_found = 1;
                    // set the environment variable
                    int setenv_status = setenv(envvar_keys[i], envvar_values[i], 1);
                    if (setenv_status == 0)
                    {
                        // success
                        break;
                    }
                    else
                    {
                        printf("export failed\n");
                        break;
                    }
                }
            }
            if (envvar_found == 0)
            {
                printf("Error: no variable with the name %s is available\n", newargv[1]);
                continue;
            }
        }
        // if the given is not a built-in command, fork and execvp
        else
        {
            int ret_pid = fork();

            if (ret_pid > 0)
            {

                int status = 0;
                wait(&status); // wait blocks till a child changes status
                // printf("%s exit status is %d\n", input_buf, WEXITSTATUS(status));
            }
            else if (ret_pid == 0)
            {
                // exec the given command
                int status = execvp(command, newargv); // utilize the environ

                if (status == -1) // check errno?
                {                 // must exit on failure not to keep the child running!
                    printf("Execution of the program %s failed\n", input_buf);
                    exit(-1);
                }
            }
            else
            {
                printf("Fork failed!\n"); // check errno?
                exit(-1);
            }
        }
    }

    for (int i = 0; i < envvar_count; ++i)
    {
        free(envvar_keys[i]);
        free(envvar_values[i]);
    }

    return 0;
}
