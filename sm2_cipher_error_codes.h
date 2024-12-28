#ifndef __SM2_CIPHER_ERROR_CODES_H__
#define __SM2_CIPHER_ERROR_CODES_H__

#ifdef __cplusplus
extern "C" {
#endif

#define INVALID_NULL_VALUE_INPUT     0x1000
#define INVALID_INPUT_LENGTH         0x1001
#define CREATE_SM2_KEY_PAIR_FAIL     0x1002
#define COMPUTE_SM3_DIGEST_FAIL      0x1003
#define ALLOCATION_MEMORY_FAIL       0x1004
#define COMPUTE_SM2_SIGNATURE_FAIL   0x1005
#define INVALID_SM2_SIGNATURE        0x1006
#define VERIFY_SM2_SIGNATURE_FAIL    0x1007
#define EC_POINT_IS_AT_INFINITY      0x1008
#define COMPUTE_SM2_CIPHERTEXT_FAIL  0x1009
#define COMPUTE_SM2_KDF_FAIL         0x100a
#define INVALID_SM2_CIPHERTEXT       0x100b
#define SM2_DECRYPT_FAIL             0x100c

#ifdef __cplusplus
}
#endif

#endif  /* end of __SM2_CIPHER_ERROR_CODES_H__ */
