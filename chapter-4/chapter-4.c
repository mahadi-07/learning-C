#include <stdio.h>
#include <string.h>

#define MAXLINE 100

double atof(char *s)
{
    double val,power;
    int i,sign;

    for(i=0; s[i]==' '||s[i]=='\n'||s[i]=='\t'; i++)
        ;
    sign=1;
    if(s[i]=='+' || s[i]=='-')
        sign = (s[i++]=='+') ? 1 : -1;
    for(val=0;s[i]>='0'&&s[i]<='9';i++)
        val=10*val+s[i]-'0';
    if(s[i]=='.')
        i++;
    for(power=1;s[i]>='0'&&s[i]<='9';i++,power*=10)
        val=10*val+s[i]-'0';
    return (sign*val/power);
}

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


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

extern void clear_();

double push(double f)
{
    if(sp<MAXVAL)
        return val[sp++]=f;
    else{
        printf("error: stack full\n");
        clear_();
        return 0;
    }
}

double pop()
{
    if(sp>0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        clear_();
        return 0;
    }
}

void clear_()
{
    sp=0;
}




#define MAXOP 20
#define NUMBER '0'
#define TOOBIG '9'


#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

char buf_sg;
int getch_single()
{
    int c;
    if(buf_sg != EOF) {
        c = buf_sg;
        buf_sg = EOF;
        return c;
    }
    else {
        return getchar();
    }
}

void ungetch_single(int c)
{
    if(buf_sg != EOF) {
        printf("ungetch_single: too many characters\n");
    }
    else {
        buf_sg = c;
    }
}

void ungetch(int c)
{
    if(bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char* s)
{
    int i;
    for(i=strlen(s); i>=0; i--)
        ungetch(s[i]);
}

int getop(char* s, int lim)
{
    int i,c;
    while( (c=getch())==' ' || c=='\t' || c=='\n')
        ;
    if(c != '.' && (c<'0'||c>'9'))
        return c;
    
    s[0]=c;
    for(i=1; (c=getchar()) >= '0' && c<='9'; i++)
        if(i<lim)
            s[i]=c;
    
    if(c=='.'){
        if(i<lim)
            s[i]=c;
        for(i++; (c=getchar())>='0' && c<='9'; i++)
            if(i<lim)
                s[i]=c;
    }
    if(i<lim){
        ungetch(c);
        s[i]='\0';
        return NUMBER;
    } else {
        while(c != '\n' && c != EOF)
            c = getchar();
        s[lim-1] = '\0';
        return TOOBIG;
    }
}

void reversePolish()
{
    int type;
    char s[MAXOP];
    double op2;

    while( (type = getop(s, MAXOP)) != EOF)
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("zero divisor popped\n");
            break;
        case '=':
            printf("\t%f\n", push(pop()));
            break;
        case 'c':
            clear_();
            break;
        case TOOBIG:
            printf("%.20s ... is too long\n", s);
            break;
        default:
            printf("unknown command %c\n", type);
            break;
        }
}

int main()
{
    // char line[MAXLINE];

    // while(get_line(line, MAXLINE) > 0) {
    //     printf("%10.2f\n", atof(line));
    // }
    
    return 0;
}