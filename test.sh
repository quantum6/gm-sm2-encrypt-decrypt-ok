
EXE_FILE=sm2-test
rm ${EXE_FILE}

gcc \
    -Wno-deprecated-declarations \
    -o ${EXE_FILE} \
    sm2_test_demo.c \
    sm2_tools.c \
    sm2_create_key_pair.c \
    sm2_encrypt_and_decrypt.c \
    sm2_encrypt_and_decrypt_test.c \
    -I../include \
    -L/lib/x86_64-linux-gnu -lcrypto
    
./${EXE_FILE}

