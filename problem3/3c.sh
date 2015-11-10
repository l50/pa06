#!/bin/bash

python py.py > abc

debugfs -w Jayson-Grace_Dominic-Salas_437disk 
write abc abc
imap ./
bd -f abc 1

#sudo mkdir /media/mount

#sudo mount -t ext2 Jayson-Grace_Dominic-Salas_437disk /media/mount

#cp ./abc /media/mount
