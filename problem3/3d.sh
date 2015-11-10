has 11 used when created. Each time we create a file, we use an inode. So when we created abc, it used 12/16 inodes. Then we are able to create 4 additional directories using:

debugfs -w Jayson....
mkdir dir1
mkdir dir2
mkdir dir3
mkdir dir4
# it breaks here
mkdir dir5
