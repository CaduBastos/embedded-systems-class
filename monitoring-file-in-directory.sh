#!/bin/sh

#this script remains in loop until to detect algo.txt file in the directory 

while[ -e "$algo.txt" ]; do 
    echo "We're waiting, "
    sleep 1
done