#!/bin/bash
# -----------------------------------------------------------------------------
# 3c.sh
#
# Run code for problem 3c of pa06.
#
# Usage: bash 3c.sh
#
# Jayson Grace, jayson.e.grace@gmail.com, 11/10/2015
#
# Last update 11/10/2015 by Jayson Grace, jayson.e.grace@gmail.com
# ----------------------------------------------------------------------------

python gen_abc.py > abc

debugfs -w Jayson-Grace_Dominic-Salas_437disk -f 3cCommands 

rm abc

#sudo mkdir /media/mount

#sudo mount -t ext2 Jayson-Grace_Dominic-Salas_437disk /media/mount

#cp ./abc /media/mount
