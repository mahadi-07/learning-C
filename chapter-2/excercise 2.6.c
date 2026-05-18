#include<stdio.h>

int main()
{

    int n = 7;

    int i=0;
    for( ; n>0; i++) n>>=1;
    
    printf("%d\n", i);
    
    return 0;
}