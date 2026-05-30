#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"

int total;

int Square(int x)
{
    return x*x;
}

int SquareOfSum(int x, int y)
{
    int z = Square(x+y);
    return z;
}

int main()
{
    // int a = 4, b = 8;
    // total = SquareOfSum(a,b);
    // printf("output = %d\n", total);

    /**
     * Dynamic memory
     */
    // c
        // malloc
        // calloc
        // realloc
        // free

    // c++
        // new
        // delete


    
    int a; // goes on stack

    int *p;
    p = (int *) malloc(sizeof(int));
    *p = 10;
    // printf("%d\n", *p);
    free(p);

    p = (int *) malloc(20 * sizeof(int));
    *(p+1) = 20;
    // printf("%d\n", *p);

    int *ptr_malloc = (int*) malloc(3 * sizeof(int));
    *ptr_malloc = 5;
    ptr_malloc[1] = 10;
    // printf("%d\n", *(ptr_malloc+1));

    int *ptr_calloc = (int*) calloc(4, sizeof(int));
    // printf("%d\n", *(ptr_calloc));


    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    
    // int *A = (int*) malloc(n * sizeof(int));
    int *A = (int*) calloc(n, sizeof(int));

    for(int i=0;i<n;i++) *(A+i) = i+1;
    
    // free(A);
    // A = NULL;

    A = (int*) realloc(A, 2*n*sizeof(int));
            // (int*) relloc(NULL, n*sizeof(int)) -> malloc
            // (int*) realloc(A, 0) -> free(A)


    for(int i=0;i<2*n;i++) printf("%d ", *(A+i));
    
    /**
     * malloc, calloc, realloc, free
     */
    // void -? malloc (size_t size)


    return 0;
}