#!/bin/sh

#this script execute a test with binclock software. This software provides a binary clock

while(true) do 
    clear; 
    date +"%H:%M:%S";
    binclock -t;
    binclock;
    sleep 1; 
done