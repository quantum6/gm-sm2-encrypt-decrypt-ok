#ifndef __SM2_CREATE_KEY_PAIR_H__
#define __SM2_CREATE_KEY_PAIR_H__

#include "sm2_tools.h"


#ifdef  __cplusplus
  extern "C" {
#endif

typedef struct sm2_key_pair_structure {
/* Private key is a octet string of 32-byte length. */
    uchar_t pri_key[32];
/* Public key is a octet string of 65 byte length. It is a 
   concatenation of 04 || X || Y. X and Y both are SM2 public 
   key coordinates of 32-byte length. */
    uchar_t pub_key[65]; 
} SM2_KEY_PAIR;


/**************************************************
* Name: sm2_create_key_pair
* Function: create SM2 key pair, including private key
    and public key
* Parameters:
    key_pair[in]  SM2 key pair
* Return value:
    0:                function executes successfully
    any other value:  an error occurs
**************************************************/
int sm2_create_key_pair(SM2_KEY_PAIR *key_pair);

#ifdef  __cplusplus
  }
#endif

#endif  /* end of __SM2_CREATE_KEY_PAIR_H__ */
