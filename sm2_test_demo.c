
#include "sm2_encrypt_and_decrypt_test.h"
#include "sm2_tools.h"
#include "sm2_encrypt_and_decrypt.h"

#define TEST_DATA "quantum6"

#define PUBLIC_KEY     "04583ad4bdb4eb73b32464fa9ed3ffb4b3fe3657f0d50850924e1738ef74481b00557824a33c6dcbc5a43a400aa3ab374fd062a24eb8e7c6810937ee06ca5d23db"
#define PRIVATE_KEY    "d43f13a21a7bfef6dd6d48ea9ad7acc03a6e35acd99e7411424b7ae746eec5b5"
#define ENCRYPTED_DATA "a540c9a2473c106b4725f4a2ed059adbee70905b98259f73415c84feb4ad3a990dce5a813c34e2f52c877917a319fac21a74a79568996778b678053079bf1512419f7ce3373870df79d5a084f5a43c530bd820413b3e64769f1a19d0d51581dc754924e1db6ed6df6297b64fb9bee9"

static void sm2_encrypt_test(SM2_KEY_PAIR* key_pair)
{
    sm2_data_buffer    plainBuffer  = {0};
    sm2_encrypt_buffer encryptBuffer = {0};

    plainBuffer.size = strlen(TEST_DATA);
    plainBuffer.data = (uchar_t*)malloc(plainBuffer.size);    
    strcpy(plainBuffer.data, TEST_DATA);

    // encrypt data
    encryptBuffer.mode = DATA_MODE_C1C3C2;
    sm2_encrypt_data(key_pair, &plainBuffer,   &encryptBuffer);
    sm2_dump_to_hex("encrypt data:\n", encryptBuffer.data, encryptBuffer.size);
}

static void sm2_decrypt_test(SM2_KEY_PAIR* key_pair)
{
    sm2_data_buffer    plainBuffer  = {0};
    sm2_encrypt_buffer encryptBuffer = {0};

    encryptBuffer.size = strlen(ENCRYPTED_DATA)/2;
    encryptBuffer.data = (uchar_t*)malloc(encryptBuffer.size);
    sm2_chars_to_hex(ENCRYPTED_DATA, encryptBuffer.data);

    encryptBuffer.mode = DATA_MODE_C1C3C2;

    sm2_decrypt_data(key_pair, &encryptBuffer, &plainBuffer);
    printf("decrypted=%s\n", plainBuffer.data);
}

int main(void)
{
    sm2_encrypt_and_decrypt_test(TEST_DATA);

    SM2_KEY_PAIR key_pair = {0};
    sm2_chars_to_hex(PUBLIC_KEY, key_pair.pub_key);
    sm2_chars_to_hex(PRIVATE_KEY, key_pair.pri_key);

    sm2_encrypt_test(&key_pair);
    sm2_decrypt_test(&key_pair);

    return 0;
}
