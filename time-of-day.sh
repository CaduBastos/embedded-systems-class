#! /bin/bash

#this script ask the user if it is morning or afternoon and wishes him a good day or good afternoon

echo "It is morning? Please answer yes or no"
read answer

if [$answer = "yes"]; then
    echo "Good morning!"
else 
    echo "Good afternoon!"
fi

exit 0
