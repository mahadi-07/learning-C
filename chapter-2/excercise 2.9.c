#include<stdio.h>

int bitcount(unsigned n)
{
    int b=0;
    while(n){
        b++;
        n&=(n-1);
    }
    return b;
}

void print_binary(int n)
{
    for (int i = 10; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main()
{
    int n = 1;
    print_binary(n);
    print_binary(n&n-1);
    printf("%d\n", bitcount(n));

    return 0;
}