#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"

int x, *p;

void increment(int *p)
{
    *p = *p + 1;
}

int sumOfElements(int *arr, int sz)
{
    int i, sum = 0;
    for(i=0;i<sz;i++){
        sum += arr[i]; // arr[i] is *(arr+i)
    }
    return sum;
}

void print(char *C)
{
    while(*C != '\0') {
        printf("%c", *(C++));
    }
    printf("\n");
}

void Func1D(int *A) /* Arguments: 1-D array of integers */
{

}

// A[][3]
void Func2D(int (*A)[3]) /* Arguments: 2-D array of integers */
{

}

// A[][2][2
void Func3D(int (*A)[2][2])
{

}

int main()
{

        
    exit(0);






    /**
     * pointers and multi-dimensional arrays
     */
    int Carr[3][2][2] = {
        {
            {2, 5},
            {7, 9}
        },
        {
            {3, 4},
            {6, 1}
        },
        {
            {0, 8},
            {11, 13}
        }
    };


    // Aarr returns int *
    int Aarr[2] = {1, 2};
    
    // Barr returns int (*)[3];
    int Barr[2][3] = {
        {2, 4, 6},
        {5, 7, 8}
    };

    int Xarr[2][4];
    int Yarr[5][3]; // it's okay

    Func1D(Aarr);
    Func2D(Barr);
    Func2D(Yarr);
    // Func2D(Xarr); // error: incompatible pointer types passing 'int[2][4]' to parameter of type 'int (*)[3]
    Func3D(Carr);



    int (*pC)[2][2] = Carr;

    // int (*)[2] = pointer to one dimensional array of two integers
    // Carr -> int (*)[2][2];
    // *Carr -> int (*)[2];
    printf("%d %d %d %d\n", Carr, *Carr, Carr[0], &Carr[0][0]);

    // Carr[i][j][k] = *(Carr[i][j]+k)
    //               = *(*(Carr[i]+j)+k)
    //               = *(*(*(Carr+i)+j)+k)

    printf("%d %d\n", *(Carr[0][1]+1), Carr[0][1][1]);
    printf("%d %d\n", *(Carr[1]+1), Carr[1][1]);


    /**
     * pointers and multi-dimensional arrays
     */
    int arr1[] = {1,2,3,4,5};
    int *p1 = arr1;
    size_t sz = sizeof(arr1)/sizeof(arr1[0]);
    for(int i=0;i<sz;i++){
        // printf("%d %c", *(arr1+i), i == sz-1 ? '\n': ' ');
    }

    int arr2d[2][3] = {
        {2, 3, 6},
        {4, 5, 8}
    };
    // arr2d[0] = 1-D array of 3 integers
    // arr2d[1] = 1-D array of 3 integers
    int (*p2d)[3] = arr2d;

    // arr2d[i][j] = *(arr2d[i]+j)
    //             = *(*(arr2d+i)+j)

    // arr2d + i -> int (*p)[3];
    // *(arr2d + i) -> int * -> name of the array give the first address of the array
    // *(arr2d+i)+j -> j position of i'th row
    // *(*(arr2d+i)+j) -> value of position i,j

    printf("%d\n", arr2d[1][2]);
    printf("%d %d\n", *(arr2d[1]+2), *(*(arr2d+1)+2));
    

    printf("%d %d\n", arr2d, &arr2d[0]);
    printf("%d %d %d\n", *arr2d, arr2d[0], &arr2d[0][0]);
    printf("%d %d %d %d %d\n", arr2d+1, *(arr2d+1), &arr2d[1], arr2d[1], &arr2d[1][0]);
    printf("%d %d %d\n", *(arr2d+1)+2, arr2d[1]+2, &arr2d[1][2]);
    printf("%d\n", *(*arr2d+1));
    printf("\n");

    printf("%d %d\n", arr2d, &arr2d);
    printf("%d %d %d\n", p2d, *p2d, *(*p2d+2));
    printf("%d %d\n", *(p2d+1), **(p2d+1));





    /**
     * character arrays and pointers - part II
     */
    // char C4[20] = "hello"; // string gets stored in the space for array
    char *C4 = "Hello"; // string gets stored as compile time constant
    printf("%d\n", strlen(C4));
    print(C4);

    /**
     * character arrays and pointers - part I
     */

    // size of array >= no. of characters in string + 1
    // rule: a string in C has to be null terminated
    char C[] = "XYZA";
    printf("size in bytes: %d\n", sizeof(C)); // 5
    int len = strlen(C); // 4
    printf("%d %s\n", len, C);

    // array and pointers are different types that are used in similar manner
    char C1[6] = "Hello";
    char *C2 = C1;
    C2[0] = 'A'; // C2[i] is *(C2+i)
    printf("%s\n", C2);

    C2++;
    printf("%c\n", *C2);
    printf("%s\n", C2);

    // arrays are always passed to function by reference

    char C3[20] = "Hello";
    print(C3);






    




    /**
     * arrays as function arguments
     */
    int A[5] = {1,2,3,4,5};
    int total = sumOfElements(A, sizeof(A)/sizeof(A[0]));
    printf("sum of elements = %d\n", total);

    /**
     * pointers and arrays
     */
    int arr[5] = {1,2,300,4,5};
    for(int i=0;i<5;i++){
        printf("%d %d\n", arr+i, *(arr+i));
    }


    /**
     * pointer as function arguments - call by references
     */
    int a = 10;
    increment(&a);
    printf("a = %d\n", a);



    /**
     * pointer to pointer
     */
    x = 5;
    int *p = &x;
    int **q = &p;
    int ***r = &q;

    printf("x = %d\n", x);
    printf("&x = %d\n\n", &x);
    
    printf("p = %d\n", p);
    printf("&p = %d\n", &p);
    printf("p* = %d\n\n", *p);

    printf("q = %d\n", q);
    printf("&q = %d\n", &q);
    printf("q* = %d\n", *q);
    printf("q** = %d\n\n", **q);
    
    printf("r = %d\n", r);
    printf("&r = %d\n", &r);
    printf("r* = %d\n", *r);
    printf("r** = %d\n", **r);
    printf("r*** = %d\n\n", ***r);

    ***r = 10;
    printf("x = %d\n", x);

    **q = *p + 2;
    printf("x = %d\n", x);

    









    // int a = 1024 + (1 << 0);
    // int *p = &a;

    // printf("size of integer is %zu\n", sizeof(int));
    // printf("Address = %d, value = %d\n", p, *p);
    // printf("Address = %d, value %d\n", p+1, *(p+1));

    // char *p0;
    // p0 = (char *) p;

    // printf("size of char is %zu\n", sizeof(char));
    // printf("Address = %d, value = %d\n", p0, *p0);
    // printf("Address = %d, value %d\n", p0+1, *(p0+1));

    // /* void pointer - generic pointer */
    // void *p0 = p;
    // printf("Address = %d\n", p0);


    // printf("%-40s %p\n", "Address of p:", &p);
    // printf("%-40s %p\n", "Address that p points at:", p);
    // printf("%-40s %p\n", "Address of a:", &a);
    // printf("%-40s %d\n", "Value of a:", a);
    // printf("%-40s %d\n", "Value at the address p points at:", *p);

    // printf("%d\n", p+1);
    // printf("%d\n", *(p+1));
    return 0;
}

#pragma GCC diagnostic pop