#include<stdio.h>

int htoi(int ch)
{
    if(ch >= '0' && ch <= '9') return ch-'0';
    else if(ch >= 'a' && ch <= 'z') return ch-'a'+10;
    else return ch-'A'+10;
}

int main()
{
    printf("%d\n", htoi('1'));
    printf("%d\n", htoi('a'));
    printf("%d\n", htoi('A'));

    return 0;
}