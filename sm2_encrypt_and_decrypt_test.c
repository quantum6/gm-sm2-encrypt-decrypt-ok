
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sm2_cipher_error_codes.h"
#include "sm2_create_key_pair.h"
#include "sm2_encrypt_and_decrypt.h"
#include "sm2_encrypt_and_decrypt_test.h"

int sm2_encrypt_and_decrypt_test(uchar_t* plainText)
{
    int error_code = 0;

    //create key pair
    SM2_KEY_PAIR key_pair = {0};
    if ( error_code = sm2_create_key_pair(&key_pair) )
    {
        printf("Create SM2 key pair failed!\n");
        return (-1);
    }
    sm2_dump_to_hex("private key:\n", key_pair.pri_key, sizeof(key_pair.pri_key));
    sm2_dump_to_hex("public key:\n", key_pair.pub_key, sizeof(key_pair.pub_key));

    sm2_data_buffer    plainBuffer  = {0};
    sm2_encrypt_buffer encryptBuffer = {0};

    plainBuffer.size = strlen(plainText);
    plainBuffer.data = (uchar_t*)malloc(plainBuffer.size);    
    strcpy(plainBuffer.data, plainText);

    // encrypt data
    encryptBuffer.mode = DATA_MODE_C1C3C2;
    error_code = sm2_encrypt_data(&key_pair, &plainBuffer,   &encryptBuffer);
    sm2_dump_to_hex("encrypt data:\n", encryptBuffer.data, encryptBuffer.size);

    // decrypt data
    sm2_data_buffer decryptBuffer = {0};
    error_code = sm2_decrypt_data(&key_pair, &encryptBuffer, &decryptBuffer);

    // check result
    printf("|||%s||| ? |||%s|||\n",
        plainBuffer.data,
        decryptBuffer.data);
}
