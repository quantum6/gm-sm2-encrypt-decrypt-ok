#ifndef __SM2_ENCRYPT_AND_DECRYPT_H__
#define __SM2_ENCRYPT_AND_DECRYPT_H__

#ifdef  __cplusplus
  extern "C" {
#endif

#include "sm2_create_key_pair.h"

#define SM2_C1_SIZE 64
#define SM2_C3_SIZE 32

typedef enum
{
    DATA_MODE_C1C3C2,
    DATA_MODE_C1C2C3
} enum_data_mode;

typedef struct
{
    uchar_t* data;
    uint_t   size;
} sm2_data_buffer;

typedef struct
{
    enum_data_mode mode;
    uchar_t*       data;
    uint_t         size;
} sm2_encrypt_buffer;


/**************************************************
* Name: sm2_encrypt_data
* Function: compute SM2 encryption
* Parameters:
    message[in]      input message
    message_len[in]  input message length, size in bytes
    pub_key[in]      SM2 public key
    c1[out]          the first segment of ciphertext
    c3[out]          the middle segment of ciphertext
    c2[out]          the last segment of ciphertext
* Return value:
    0:                function executes successfully
    any other value:  an error occurs
* Notes:
1. pub_key is a octet string of 65 byte length. It 
   is a concatenation of 04 || X || Y. X and Y both are 
   SM2 public key coordinates of 32 byte length.
2. SM2 ciphertext is defined as a concatenation of 
   c1 || c3 || c2 in GM/T 0003.4-2012.
3. c1 is a octet string of 65 byte length. It is a 
   point on the elliptic curve. It is a concatenation 
   of 04 || X || Y. X and Y both are coordinates of 
   32 byte length.
4. c3 is a octet string of 32 byte length. It is a 
   SM3 digest value.
5. c2 is a octet string. Its length equals the length 
   of input message.
**************************************************/
int sm2_encrypt(const unsigned char *message,
                const int message_len,
        const unsigned char *pub_key,
        unsigned char *c1,
        unsigned char *c3,
        unsigned char *c2);

int sm2_encrypt_data(SM2_KEY_PAIR* key_pair,
    sm2_data_buffer*    pInBuffer,
    sm2_encrypt_buffer* pEnBuffer);

/**************************************************
* Name: sm2_decrypt
* Function: decrypt SM2 ciphertext
* Parameters:
    c1[in]            the first segment of ciphertext
    c3[in]            the middle segment of ciphertext
    c2[in]            the last segment of ciphertext
    c2_len[in]        c2 length, size in bytes
    pri_key[in]       SM2 private key
    plaintext[out]    decrypted result
* Return value:
    0:                function executes successfully
    any other value:  an error occurs
* Notes:
1. SM2 ciphertext is defined as a concatenation of 
   c1 || c3 || c2 in GM/T 0003.4-2012.
2. c1 is a octet string of 65 byte length. It is a 
   point on the elliptic curve. It is a concatenation 
   of 04 || X || Y. X and Y both are coordinates of 
   32 byte length.
3. c3 is a octet string of 32 byte length. It is a 
   SM3 digest value.
4. c2 is a octet string. The length of plaintext is 
   equal to c2_len.
5. pri_key is a octet string of 32 byte length.
**************************************************/
int sm2_decrypt(const uchar_t *c1,
                const uchar_t *c3,
        const uchar_t *c2,
        const int c2_len,
        const uchar_t *pri_key,
        uchar_t *plaintext);

int sm2_decrypt_data(SM2_KEY_PAIR* key_pair,
    sm2_encrypt_buffer* pEnBuffer,
    sm2_data_buffer*    pDeBuffer);


#ifdef  __cplusplus
  }
#endif

#endif  /* end of __SM2_ENCRYPT_AND_DECRYPT_H__ */
