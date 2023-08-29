#!/bin/bash

function submodule_update(){
    git submodule update
}

function build(){
    echo "Building..."
    docker run --rm -v "$PWD":/src fabiosoaza/sgdk:v1.90 clean
    docker run --rm -v "$PWD":/src fabiosoaza/sgdk:v1.90
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
        "submodule-update")
            submodule_update
            ;;    
  esac
