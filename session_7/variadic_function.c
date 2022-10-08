#include <stdio.h>
#include <stdarg.h>

//Ref: https://www.geeksforgeeks.org/variadic-functions-in-c

int sum(int n, ...)
{
    int sum = 0;

    va_list args_ptr; //declare a pointer to the args list
    va_start(args_ptr, n); //init the arguments pointer with the number of args

    for (int i = 0; i < n; i++)
    {
        sum += va_arg(args_ptr, int); //access current value, then point to the next one
    }

    va_end(args_ptr);

    return sum;
}

int main(int argc, char const *argv[])
{
    printf("Variadic functions\n");
    printf("3 + 5 = %d\n", sum(2, 3, 5));
    printf("3 + 5 + 9 = %d\n", sum(3, 3, 5, 9));
    
    return 0;
}
