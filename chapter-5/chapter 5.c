#include <stdio.h>
#include <math.h>
#include <assert.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int get_int(int *pn)
{
    int c, sign;
    while((c = getch()) == ' ' || c == '\n' || c == '\t')
    ;
    sign = 1;
    if(c == '+' || c == '-') {
        sign = (c == '+') ? 1 : -1;
        c = getch();
    }
    for(*pn = 0; c>='0' && c<='9'; c = getch())
        *pn = 10 * *pn + c - '0';
    
    *pn *= sign;

    if(c != EOF)
        ungetch(c);
    
    return c;
}

int getfloat(double *ptr)
{
    int c, sign;
    double val, power;
    while((c = getch()) == ' ' || c == '\n' || c == '\t')
    ;
    sign = 1;
    if(c == '+' || c == '-') {
        sign = (c == '+') ? 1 : -1;
        getch();
    }

    for(*ptr=0; c>='0' && c<='9'; c=getch())
        *ptr = *ptr * 10 + c - '0';
    if(c == '.') c = getch();
    for(power=1; c>='0' && c<='9'; c=getch(), power *= 10)
        *ptr = *ptr * 10 + c - '0';

    *ptr *= sign;
    *ptr /= power;

    if(c != EOF) ungetch(c);

    return c;
}

int main()
{
    double val;
    getfloat(&val);
    printf("val = %f\n", val);

    // int SIZE = 5;
    // int n, v, arr[SIZE];
    // for(n=0; n<SIZE && get_int(&v) != EOF; n++)   
    //     arr[n] = v;

    // for(int i=0;i<SIZE;i++){
    //     printf("%d ", arr[i]);
    // }
    return 0;
}