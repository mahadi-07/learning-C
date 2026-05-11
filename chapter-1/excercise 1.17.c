#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim)
{
    int c, i;
    for(i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char line[], int len)
{
    int i = 0;
    len--;
    while(i <= len) {
        char temp = line[i];
        line[i] = line[len];
        line[len] = temp;
        i++;
        len--;
    }
}

int main()
{
    int len;
    int max;
    char line[MAXLINE];

    max = 0;
    while((len = get_line(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s\n", line);
    }

    return 0;
}

