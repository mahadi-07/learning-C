#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define NAMESIZE 100
#define ADRSIZE 100

struct date {
    int day;
    int month;
    int year;
    int yearday;
    char mon_name[4];
};

struct date d;

struct person {
    char name[NAMESIZE];
    char address[ADRSIZE];
    long zipcode;
    long ss_number;
    double salary;
    struct date birthdate;
    struct date hiredate;
};

struct key {
    char *keyword;
    int keycount;
};

struct key keytab[] = {
    "break", 0,
    "case", 0,
    "char", 0,
    "continue", 0,
    "default", 0,

    /* ... */

    "unsigned", 0,
    "while", 0
};

#define NKEYS (sizeof(keytab) / sizeof(struct key))

#define MAXWORD 20
#define LETTER 'a'
#define DIGIT '0'

int binary(char *word, struct key tab[], int n)
{
    int low, high, mid, cond;

    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if((cond = strcmp(word, tab[mid].keyword)) < 0)
            high = mid - 1;
        else if(cond > 0)
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch() { return bufp > 0 ? buf[--bufp] : getchar(); }

void ungetch(int c) { if(bufp > BUFSIZE) printf("ungetch: too many characters\n"); else buf[bufp++] = c; }

int type(int c)
{
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return LETTER;
    else if(c >= '0' && c <= '9')
        return DIGIT;
    else
        return c;
}

int getword(char *w, int lim)
{
    int c, t;
    if(type(c = *w++ = getch()) != LETTER) {
        *w = '\0';
        return c;
    }

    while(--lim > 0) {
        t = type(c = *w++ = getch());
        if(t != LETTER && t != DIGIT) {
            ungetch(c);
            break;;
        }
    }
    *(w-1) = '\0';
    return LETTER;
}

void solve()
{
    int n, t;
    char word[MAXWORD];

    while((t = getword(word, MAXWORD)) != EOF) {
        printf("word = %s\n", word);
        if(t == LETTER)
            if((n = binary(word, keytab, NKEYS)) >= 0) {
                keytab[n].keycount++;
            }
    }
             

    for(n = 0; n < NKEYS; n++)
        if(keytab[n].keycount > 0)
            printf("%4d %s\n", keytab[n].keycount, keytab[n].keyword);
}

int main() 
{
    solve();
    return 0;
}