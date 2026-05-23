#include<stdio.h>

char* expand(char* s, char* t)
{
    int j=0;
    for(int i=0;s[i]!='\0';i++){
        switch (s[i]) {
        case '\n':
            t[j++]='\\';
            t[j++]='n';
            break;
        case '\t':
            t[j++]='\\';
            t[j++]='t';
            break;
        
        default:
            t[j++]=s[i];
            break;
        }
    }
    return t;
}

int main()
{
    char s[1000], t[1000];

    int c,i=0;
    while((c = getchar()) != EOF) s[i++]=c;
    s[i]='\0';

    expand(s,t);
    
    for(int i=0;t[i]!='\0';i++)
        printf("%c",t[i]);
    
    return 0;
}