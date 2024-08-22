#!/bin/sh

#this script encrypts any text file using the monoalphabetic cipher with tr software

#check if a file was given as a parameter
if [ $# -eq 0 ]; then
    echo "Error! Please give an input .txt file"
    exit 1
fi

#uppercase characters and their key
uppercase_original="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
uppercase_key="ZQ8WNBRLJCK4XY7TVSD2AH"

#lowercase characters and their key
original="abcdefghijklmnopqrstuvwxyz"
key="pmzjtdhgrfycqvnbkwxlsu"

#catch the file given as parameter and swap characters with their key one by one 
cat $1 | tr ${uppercase_original} $uppercase_key | tr ${original} ${key} > file_encrypted.txt

exit 0