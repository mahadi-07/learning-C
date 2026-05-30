#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"

void printHelloWorld()
{
    printf("Hello World\n");
}

int* add(int *a, int *b)
{
    int *c = (int*) malloc(sizeof(int));
    *c = *a + *b;
    return c;
}

int main()
{
    int a = 2, b = 4;
    printf("Addres of a in main = %d\n", &a);

    int* ptr = add(&a, &b);

    printHelloWorld();

    printf("%d\n", *ptr);
    
    free(ptr);
    ptr = NULL;

    return 0;
}