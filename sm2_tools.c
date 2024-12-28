#include <stdio.h>
#include <string.h>

#include "sm2_tools.h"

static uchar_t sm2_char_to_hex(uchar_t ch)
{
    if ('0' <= ch && ch <= '9')
    {
        return (ch-'0');
    }
    else if ('A' <= ch && ch <= 'F')
    {
        return (ch-'A'+10);
    }
    else if ('a' <= ch && ch <= 'f')
    {
        return (ch-'a'+10);
    }
    return 0;
}

static uchar_t sm2_char2_to_hex(uchar_t ch1, uchar_t ch2)
{
    uchar_t high = sm2_char_to_hex(ch1);
    return ((high<<4) | sm2_char_to_hex(ch2));
}

void sm2_chars_to_hex(uchar_t* chars, uchar_t* hex)
{
    int size = strlen((const char*)chars)/2;
    for (int i=0; i<size; i++)
    {
        hex[i]=sm2_char2_to_hex(chars[i*2], chars[i*2+1]);
    }
}

void sm2_dump_to_hex(char* title, uchar_t* data, int len)
{
    printf("len=%d, %s=", len, title);
    for (int i=0; i<len; i++)
    {
        printf("%02x", data[i]);
    }
    printf("\n");
}
