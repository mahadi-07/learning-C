#include <stdio.h>

int strlen(char *s)
{
    int n;
    for(n=0; *s != '\0'; s++)
        n++;
    return n;
}

int main()
{
    int a[10];
    a[0] = 15;
    a[5] = 100;

    int *pa = &a[0];
    printf("%d\n", *pa);
    printf("%d\n", *(a+5));

    int (*ptr)[10] = &a;

    return 0;
}