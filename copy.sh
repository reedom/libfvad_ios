#!/bin/bash

for dir in include src; do
    for file in $(find libfvad/$dir -name '*.h' -o -name '*.c'); do
        dst=${file/libfvad/libfvad_ios\/Classes/libfad}
        mkdir -p $(dirname $dst)
        echo "copy $file -> $dst"
        cp -p $file $dst
    done
done

