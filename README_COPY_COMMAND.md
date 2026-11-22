[OLD & SUB PAR QUALITY CODE, MOVE ON NEXT]
USES BASIC SYSTEM CALLS TO IMPLIMENT COPY FEAUTURE BETWEEN TEXT FILES 
open() , read(), write(),close(), fstat() and more



USAGE :

1) When no arguments are passed
   Insufficient arguments
   Usage:-./my_copy [option] [source] [destination]

2) When destination file is not exists 
   ./my_copy source.txt dest.txt . 
   New dest.txt file is created and source.txt file will be copied to dest.txt file

3)When destination file exists 
  ./my_copy source.txt dest.txt File “dest.txt” is already exists. 
  Do you want to overwrite (Y/n)

4)When –p option passed 
  ./my_copy –p source.txt dest.txt 
  Permissions also copied from source file to destination.
