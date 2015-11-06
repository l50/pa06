#!/bin/bash

generateTar()
{
    mkdir test
    tar -cvf output.tar test
    rm -rf test/
}

generateElf()
{
    gcc -Wall -g filetype.c -o filetype-bin
}

generateTar
generateElf
