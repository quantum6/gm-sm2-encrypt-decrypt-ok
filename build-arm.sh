
SO_FILE=libgmsm2.so
rm ${SO_FILE}


export CROSS_NAME=aarch64-mix210-linux
export PATH=${PATH}:/opt/linux/x86-arm/${CROSS_NAME}/bin

OPENSSL_PATH=${HOME}/d861t/ctrler-3.0/dep-opensource/openssl

A_GCC=${CROSS_NAME}-g++
${A_GCC} \
    -Wno-deprecated-declarations \
    -shared \
    -o ${SO_FILE} \
    sm2_create_key_pair.c \
    sm2_encrypt_and_decrypt.c \
    sm2_tools.c \
    -I${OPENSSL_PATH}/include \
    -L${OPENSSL_PATH}/lib -lcrypto

file ${SO_FILE}

