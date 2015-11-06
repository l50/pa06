#!/bin/bash

reset
gcc -g filetype.c -o filetype
./filetype testFile
