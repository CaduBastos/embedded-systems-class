#!/bin/sh

#this script download the webpages in sequence from 1 to 9 with wget

for i in $(seq 1 9)
do
    wget http://overthewire.org/wargames/bandit/bandit$i.html
    echo "Downloading from http://overthewire.org/wargames/bandit/bandit$i.html"
done

exit 0