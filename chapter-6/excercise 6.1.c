#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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

FILE* infile = NULL;

int getch() 
{ 
    return bufp > 0 ? buf[--bufp] : getc(infile); 
}

void ungetch(int c) { if(bufp >= BUFSIZE) printf("ungetch: too many characters\n"); else buf[bufp++] = c; }

int type(int c)
{
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return LETTER;
    else if(c >= '0' && c <= '9')
        return DIGIT;
    else
        return c;
}

int type_with_lib(int c)
{
    if(isalpha((unsigned char) c)) 
        return LETTER;
    else if(isdigit((unsigned char) c))
        return DIGIT;
    else 
        return c;
}

int getword(char *w, int lim, int typeFunc(int))
{
    int c, t;
    if(typeFunc(c = *w++ = getch()) != LETTER) {
        *w = '\0';
        return c;
    }

    while(--lim > 0) {
        t = typeFunc(c = *w++ = getch());
        if(t != LETTER && t != DIGIT) {
            ungetch(c);
            break;;
        }
    }
    *(w-1) = '\0';
    return LETTER;
}

void run(const char *filename, int typeFunc(int))
{
    int n, t;
    char word[MAXWORD];

    clock_t start = clock();

    infile = fopen(filename, "r");
    if (infile == NULL) {
        perror(filename);
        return;
    }

    while ((t = getword(word, MAXWORD, typeFunc)) != EOF) {
        if (t == LETTER) {
            if ((n = binary(word, keytab, NKEYS)) >= 0)
                keytab[n].keycount++;
        }
    }

    fclose(infile);

    clock_t end = clock();

    printf("Time: %f sec\n",
           (double)(end - start) / CLOCKS_PER_SEC);
}

int main()
{
    run("example_word.txt", type);
    run("example_word.txt", type_with_lib);

    return 0;
}