#!/bin/sh

#this script encrypts any text file using the monoalphabetic cipher with tr software

if [ $# -eq 0 ]; then
    echo "Error! Please give an input .txt file"
    exit 1
fi

cat $0

#cat ${FILE_NAME} | tr ${uppercase_original} ${uppercase_key} | tr ${original} ${key} > ${OUTPUT_FILE}

exit 0