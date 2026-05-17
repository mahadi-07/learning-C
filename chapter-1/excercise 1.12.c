#include <stdio.h>
#include <string.h>

#define MAXLENGTH 10

int main()
{
    
    int c, wl[MAXLENGTH] = {}, cn;
    cn = 0;

    while((c = getchar()) != EOF) {

        if(c == ' ' || c == '\t' || c == '\n') {
            if(cn < MAXLENGTH)
                wl[cn]++;
            cn = 0;
        }
        else cn++;
    }

    /* horizontal histogram */
    for(int i = 0; i < MAXLENGTH; i++) {
        printf("%d:", i);
        for(int j = 0; j < wl[i]; j++)
            printf(" *");
        printf("\n");
    }

    for(int i = 0; i < 3; i++)
        printf("\n");

    /* vertical histogram */
    int mxVal = 0;
    for(int i = 0; i < MAXLENGTH; i++)
        if(wl[i] > mxVal) mxVal = wl[i];

    int vh[mxVal + 1][MAXLENGTH];
    memset(vh, 0, sizeof(vh));

    while(1) {
        int mxPos = 0;
        for(int j = 0; j < MAXLENGTH; j++) 
            if(wl[j] > wl[mxPos]) mxPos = j;
        
        if(wl[mxPos] <= 0) break;

        vh[mxVal - wl[mxPos] + 1][mxPos]++;
        wl[mxPos]--;
    }

    for(int i = 1; i <= mxVal; i++) {
        for(int j = 0; j < MAXLENGTH; j++) {
            if(vh[i][j] == 0) printf("%4s", " ");
            else printf("%4s", "*");
        }
        printf("\n");
    }

    for(int i = 0; i < MAXLENGTH; i++)
        printf("%4d", i);
    
    return 0;
}