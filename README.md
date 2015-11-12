# Programming assignment 6 for OS

[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)

The sixth and final programming assignment for operating systems class at UNM (CS-481) by Jayson Grace (jayson.e.grace@gmail.com) and Dominic Salas (dominic.salas@gmail.com).

## Contributing
Please fork and do a pull request when you've created a feature that you want to be added.

### To-Do
#### Problem 1: Create program filetype - Takes param which is name of file. Should be able to identify file type using the magic number (file signature)
- [x] filetype identifies pdf - 1a
- [x] filetype identifies jpg - 1a
- [x] filetype identifies ELF - 1a
- [x] filetype identifies tar - 1a
- [x] filetype identifies sh file - 1a
- [x] Output source code into report - 1a
- [x] Outline how to identify a text file in a report - 1b

#### Problem 2: Create program sizewatch that runs as a daemon. It monitors w/ stat() and records alterations in the size of a text file over 3 minutes every ten seconds.
- [x] Produces log file showing size of file before and after modification over a time period
- [x] Has been tested by editing a text file frequently in the foreground
- [x] Runs as a daemon
- [x] Exits after 3 minutes
- [x] Report has source code and running examples
##### Sample output:
[10-11-2015 11:32:53] Monitoring File: ./test.txt
[10-11-2015 11:32:53] Initial Size: 12
[10-11-2015 11:33:13] Size Changed: Old = 12, New = 36
[10-11-2015 11:33:23] Size Changed: Old = 36, New = 51
[10-11-2015 11:33:43] Size Changed: Old = 51, New = 93
[10-11-2015 11:35:53] Monitoring File terminated, BYE. 
- [x] Matches sample output

#### Problem 3: Create Linux ext2 system disk image w/ blocks of 1024 bytes, 16 inodes, 1 group, volume name as YourFirstName_YourLastName_437disk.
- [x] Display file system spec & disk layout including block bitmap, inode bitmap, inode table, volume name
- [] Show root directory location from inode to 1st block and its content
- [] Create a text file containing 800 of “A”, 800 of “B” and 800 of “C”. Copy it into your disk image as a file named as “abc” (use debugfs’s write). Show where is this newly created file block (from root dir, to inode, to 1st,2nd,3rd blocks) and show the 2nd block of content by dumping segment of disk image specified by 2nd block’s address (use xxd –s)
- [x] Create several new directories and files to reach the system limit. Describe how 16 inodes are consumed.
- [x] Write a utility program ‘catfilev’ to find and print out the content of a file specified in this mini file system by its inode. The utility takes two parameters: inode # and the name of the disk image. Show the steps to make your file system image, and answer questions of 3.a) to d)
- [x] Report has code and running examples

#### Problem 4: Update jdshell
- [] Allow standard in or out file to be redirected using < and > symbols
- [] Add pipe in. Only needs to work with a single pipe.

