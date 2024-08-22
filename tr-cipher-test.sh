#!/bin/sh

#this script encrypts any text file using the monoalphabetic cipher with tr software

if [ $# -eq 0 ]; then
    echo "Error! Please give an input .txt file"
    exit 1
fi

uppercase_original="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
uppercase_key="ZQ8WNBRLJCK4XY7TVSD2AH"

original="abcdefghijklmnopqrstuvwxyz"
key="pmzjtdhgrfycqvnbkwxlsu"

cat $1 | tr ${uppercase_original} $uppercase_key | tr ${original} ${key} > file_encrypted.txt

#cat ${FILE_NAME} | tr ${uppercase_original} ${uppercase_key} | tr ${original} ${key} > ${OUTPUT_FILE}

exit 0