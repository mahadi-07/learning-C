#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 20
#define LETTER 'a'
#define DIGIT '0'

struct key {
    char *keyword;
    int keycount;
};

struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"return", 0},
    {"short", 0},
    {"signed", 0},
    {"sizeof", 0},
    {"static", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0}
};

#define NKEYS (sizeof(keytab) / sizeof(struct key))




#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch() 
{ 
    return bufp > 0 ? buf[--bufp] : getchar(); 
}

void ungetch(int c) {
    if(bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n"); 
    else
        buf[bufp++] = c; 
}


int type_check(int c)
{
    if(isalpha((unsigned char) c)) 
        return LETTER;
    else if(isdigit((unsigned char) c))
        return DIGIT;
    else 
        return c;
}


int getword(char *w, int lim)
{
    static int in_quote = 0;

    int c;
    
    while((c = getch()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t') continue;
        if(c == '"') { in_quote ^= 1; continue; }
        if(in_quote) continue;
        break;
    }

    if(c == EOF) return EOF;

    *w++ = c;
    while(--lim > 0) {
        c = getch();
        if(c == EOF) return EOF;

        if(c == '"') {
            in_quote ^= 1;
            break;
        }

        int t = type_check(c);
        if(t != LETTER && t != DIGIT) {
            ungetch(c);
            break;
        }

        *w++ = c;
    }
    *w = '\0';
    return LETTER;
}


struct key *binary(char *word, struct key tab[], int n)
{
    int cond;

    struct key *low = &tab[0];
    struct key *high = &tab[n-1];
    struct key *mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->keyword)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}

int main()
{

    int t;
    char word[MAXWORD];

    struct key 
        *binary(char *word, struct key tab[], int n), 
        *p;

    while ((t = getword(word, MAXWORD)) != EOF)
        if (t == LETTER)
            if ((p=binary(word, keytab, NKEYS)) != NULL)
                p->keycount++;
    
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->keycount > 0)
            printf("%4d %s\n", p->keycount, p->keyword);

    return 0;
}