#!/bin/bash
# -----------------------------------------------------------------------------
# runTests.sh
#
# Run test for problem 1 of pa06
#
# Usage: bash runTests.sh
#
# Jayson Grace, jayson.e.grace@gmail.com, 11/8/2015
#
# Last update 11/8/2015 by Jayson Grace, jayson.e.grace@gmail.com
# ----------------------------------------------------------------------------

compile()
{
  reset
  gcc -g filetype.c -o filetype
}

pdfTest()
{
  wget http://help.adobe.com/en_US/reader/using/reader_X_help.pdf
  ./filetype reader_X_help.pdf
  mv reader_X_help.pdf reader_X_help
  ./filetype reader_X_help
  rm reader_X_help
}

jpgTest()
{
  wget https://upload.wikimedia.org/wikipedia/en/1/12/Never-Let-Me-Down.jpg
  ./filetype Never-Let-Me-Down.jpg
  mv Never-Let-Me-Down.jpg Never-Let-Me-Down
  ./filetype Never-Let-Me-Down
  rm Never-Let-Me-Down
}

tarTest()
{
  wget http://ftp.gnu.org/gnu/tar/tar-1.28.tar.gz
  ./filetype tar-1.28.tar.gz
  mv tar-1.28.tar.gz tar-1.28
  ./filetype tar-1.28
  rm tar-1.28
}

shTest()
{
  ./filetype runTests.sh
  cp runTests.sh runTests
  ./filetype runTests
  rm runTests
}

elfTest()
{
  ./filetype /bin/ls    
}

compile
pdfTest
jpgTest
tarTest
shTest
elfTest
