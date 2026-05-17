#include<stdio.h>
#include<ctype.h>

#define YES 1
#define NO 0

int main()
{
    int c, nl, nw, nc, inword;

    inword = NO;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n') {
            printf("%d\n", nw);
            nw = 0;
        }

        if(!isalpha(c)) continue;

        while((c = getchar()) != EOF) {
            if(isalpha(c) || isdigit(c) || c == '\'') continue;
            if(c == ' ' || c == '\t') {
                nw++;
                break;
            }
            if(c == '\n') {
                printf("%d\n", nw);
                nw = 0;
            }
            break;
        }

    }

    return 0;
}