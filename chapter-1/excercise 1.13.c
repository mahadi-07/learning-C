#include <stdio.h>
#include <ctype.h>

char lower(char c) {
    return isalpha(c) ? tolower(c) : c;
}

int main()
{
    int c;
    while((c = getchar()) != EOF)
        printf("%c", lower(c));

    return 0;
}

