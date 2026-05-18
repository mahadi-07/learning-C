#include<stdio.h>

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
    int x = 45;
    print_binary(x);

    int p = 5; // 1-index
    int n = 4;
    
    int bits = sizeof(x) * 8;
    int a = (~0 << bits) << (p-n);
    int b = ~((~0 << bits) << p);
    print_binary(x^(a&b));


    return 0;
}