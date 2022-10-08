#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Error: not enough arguments\n");
        printf("Usage: myecho message to print\n");
        exit(-1);
    }

    int input_size = strlen(argv[1]);
    
    if (argc > 2)
    {
        for (int i = 2; i < argc; ++i)
        {
            input_size++; // for one space size
            input_size += strlen(argv[2]); // for the next argv element size
        }
    }

    char total_str[input_size];
    total_str[0] = '\0';

    strcat(total_str, argv[1]);

    if (argc > 2)
    {
        for (int i = 2; i < argc; ++i)
        {
            strcat(total_str, " "); // add a space
            strcat(total_str, argv[i]); // add the next argv element
        }
    }

    printf("%s\n", total_str);

    return 0;
}
