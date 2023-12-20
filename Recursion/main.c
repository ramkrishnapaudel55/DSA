#include <stdio.h>
#include "fibonacci.h"

int main()
{
    unsigned int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d\t%n", fibonacci_recursive(i));
    }
    return 0;
}