#include <stdio.h>
#include <stdlib.h>
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


#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))
#define NWORDS 10

int main(void)
{
    FILE *fp;
    int i;

    srand((unsigned)time(NULL));

    fp = fopen("example_word.txt", "w");
    if (fp == NULL) {
        perror("example_word.txt");
        return 1;
    }

    for (i = 0; i < NWORDS; i++) {
        fprintf(fp, "%s\n", keytab[rand() % NKEYS].keyword);
    }

    fclose(fp);

    return 0;
}