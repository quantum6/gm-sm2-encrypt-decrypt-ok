#ifndef __SM2_TOOLS_H__
#define __SM2_TOOLS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef  __cplusplus
  extern "C" {
#endif

typedef unsigned char uchar_t;
typedef unsigned int  uint_t;

void sm2_dump_to_hex(char* title, uchar_t* data, int len);
void sm2_chars_to_hex(uchar_t* chars, uchar_t* hex);

#ifdef  __cplusplus
  }
#endif

#endif //__SM2_TOOLS_H__
