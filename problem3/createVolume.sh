#!/bin/bash
# -----------------------------------------------------------------------------
# createVolume.sh
#
# Create a disk volume for problem 3 of pa06.
#
# Usage: bash createVolume.sh
#
# Jayson Grace, jayson.e.grace@gmail.com, 11/10/2015
#
# Last update 11/10/2015 by Jayson Grace, jayson.e.grace@gmail.com
# ----------------------------------------------------------------------------

dd if=/dev/zero of=./Jayson-Grace_Dominic-Salas_437disk bs=1k count=100
mkfs -t ext2 -N 16 -F Jayson-Grace_Dominic-Salas_437disk
