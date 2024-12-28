#ifndef __SM2_ENCRYPT_AND_DECRYPT_TEST_H__
#define __SM2_ENCRYPT_AND_DECRYPT_TEST_H__

#include "sm2_create_key_pair.h"

#ifdef  __cplusplus
  extern "C" {
#endif

/**************************************************
* Name: sm2_encrypt_and_decrypt_test
* Function: test SM2 encrypt data and decrypt ciphertext
* Return value:
    0:                test executes successfully
    any other value:  an error occurs
**************************************************/
int sm2_encrypt_and_decrypt_test(uchar_t* plainText);

#ifdef  __cplusplus
  }
#endif

#endif  /* end of __SM2_ENCRYPT_AND_DECRYPT_TEST_H__ */
