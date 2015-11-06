#!/bin/bash

generateTar()
{
    mkdir test
    tar -cvf output.tar test
    rm -rf test/
}

runElf()
{
    ./filetype /bin/ls    
}

generateTar
runElf
