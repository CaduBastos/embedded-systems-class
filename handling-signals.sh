#!/bin/sh

#this script execute a task and print something when an interrupt (ctrl+c) occurs

trap 'echo pessoal' SIGINT

while : ; do
    echo oi
    sleep 1
done
