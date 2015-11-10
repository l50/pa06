#!/bin/bash

dd if=/dev/zero of=./Jayson-Grace_Dominic-Salas_437disk bs=1k count=100
mkfs -t ext2 -N 16 -F Jayson-Grace_Dominic-Salas_437disk
