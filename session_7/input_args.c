#include<stdio.h>

int main(int argc, char const *argv[])
{
    printf("Got %d arguments");
    for (int i = 0; i < argc; i++){
        printf("Arg number %d has a value of %s \n", i, argv[i]);
    }
    return 0;
}
