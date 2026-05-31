#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SDS_TYPE_5  0
#define SDS_TYPE_8  1
#define SDS_TYPE_16 2
#define SDS_TYPE_32 3
#define SDS_TYPE_64 4
#define SDS_TYPE_MASK 7
#define SDS_TYPE_BITS 3
#define SDS_HDR_VAR(T,s) struct sdshdr##T *sh = (void*)((s)-(sizeof(struct sdshdr##T)));
#define SDS_HDR(T,s) ((struct sdshdr##T *)((s)-(sizeof(struct sdshdr##T))))
#define SDS_TYPE_5_LEN(f) ((f)>>SDS_TYPE_BITS)

struct __attribute__ ((__packed__)) sdshdr64 {
    uint64_t len;
    uint64_t alloc;
    unsigned char flags;
    char buf[];
};

char* newlen(const void *init, size_t initlen)
{
    printf("%s %zu\n", (const char *) init, initlen);
    void *sh;
    char *s;
    
    char type = SDS_TYPE_64;
    int hdrlen = sizeof(struct sdshdr64);
    unsigned char *fp;

    sh = malloc(hdrlen+initlen+1);
    if(sh == NULL) return NULL;
    
    memset(sh, 0, hdrlen+initlen+1);

    s = (char *)sh+hdrlen;
    fp = ((unsigned char*) s)-1;
    // fp = &(((struct sdshdr64 *)sh)->flags);

    // printf("after memset: %s\n", (char *) sh);
    // printf("s: %p\n", sh);
    // printf("s: %p\n", s);
    // printf("s: %p\n", fp);

    switch(type) {
        case SDS_TYPE_64: {

        }
        default: exit(0);
    }

    return (char *) init;
}

int main()
{
    char *str = "hello world!";
    newlen(str, strlen(str));
    
    return 0;
}






// gcc opensource_test.c sds/sds.c -o main && ./main && rm main