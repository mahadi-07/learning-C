#include<stdio.h>
#include<string.h>

void print_binary(int n)
{
    // int bits=0;
    // unsigned int t=n;
    // printf("%d\n", t);
    // while(t>0){
    //     bits++;
    //     t>>=1;
    // }
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

char* reverse(char* s)
{
    int c,i,j;
    for(i=0,j=(size_t)strlen(s)-1; i<j;i++,j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

char* itoa(int n, char s[])
{
    int i, sign;
    if((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    s = reverse(s);
    return s;
}

int main()
{

    int n = -2147483648;
    printf("n = %18d\n", n);

    char result[100];
    itoa(n, result);

    for(int i=0;result[i]!='\0';i++) {
        printf("%c ", result[i]);
    }
    printf("\n");




    // printf("%d\n", n);
    // print_binary(n);

    // printf("%d\n", ~n+1);
    // print_binary(~n+1);
    return 0;
}