#!/bin/bash

function build(){
    echo "Building..."
    docker run --rm -v "$PWD":/src fabiosoaza/sgdk:v1.80 clean
    docker run --rm -v "$PWD":/src fabiosoaza/sgdk:v1.80
}    

function debug(){
    echo "Debugging in blastem..."
    blastem -m gen -d -e out/rom.bin
}

 case $1 in
        "debug")
            debug
            ;;
        "build")
            build
            ;;
  esac
