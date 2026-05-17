#include<stdio.h>

char* squeeze(char *s1, char *s2)
{
    int set[256] = {0};
    for(int i=0;s2[i]!='\0';i++) set[(int)s2[i]] = 1;
    
    int i, k;
    for( i=k=0 ; s1[i]!='\0'; i++) 
        if(!set[s1[i]]) s1[k++] = s1[i];

    s1[k] = '\0';
    return s1;
}

int main()
{
    char s1[] = "llhello";
    char s2[] = "llo";

    printf("%s\n", squeeze(s1, s2));

    return 0;
}