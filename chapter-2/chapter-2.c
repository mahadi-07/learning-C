#include<stdio.h>

int hexToInt(char *hex) {
    // printf("%s\n", *hex++);
    int val = 0;
    while (*hex) {
        // Get the value of the current hex digit
        char byte = *hex;
        hex++;

        // char byte = *hex++;
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <= 'f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <= 'F') byte = byte - 'A' + 10;
        
        // Shift existing value and add current digit
        // printf("%d\b", 0xF);
        // printf("%d %d %d %d\n", val, (val << 4), byte, (byte & 0xF));
        val = (val << 4) | (byte & ((1<<4)-1));
    }
    return val;
}

int main()
{
    printf("%d\n", hexToInt("1FA"));

    return 0;
}