#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"

int main()
{
    int m = 10, n, o;
    int *z = &m;

    printf("z stores the address of m = %p\n", z);
    printf("*z stores the value of m = %d\n", *z);

    return 0;
}