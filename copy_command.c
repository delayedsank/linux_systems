#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#include<unistd.h> //read & write sys call
#include<sys/stat.h>

int main(int argc, char *argv[])
{

    //printf("-->%c\n", *(argv[1] + 1));

    char opt,track = 0;
    char ret = 0;
    char buff[50];
    struct stat sb;
    

    int fd_source_open,fd_dest_open;

    if(argc <= 2 || argc > 4  ) // total 3 arg 
    {
        printf("Insufficient arguments\nUsage:-./my_copy [option] [source] [destination]\n");
        return 0;
    }
    else if(argc == 4 && *argv[1] == '-' && *(argv[1]+1) == 'p' ) //-p option total - 4arg
    {
    
    fd_source_open = open(argv[2],O_RDONLY); //source file open
    fstat(fd_source_open, &sb);    
    close(fd_source_open);

    fd_source_open = open(argv[2],O_RDONLY); //source file open
   
    fd_dest_open = open(argv[3],O_CREAT | O_EXCL | O_WRONLY);

    //fchmod(fd_dest_open, sb.st_mode);
    if(fd_dest_open == -1)
    {
    track = 1;
    }
    else
    fchmod(fd_dest_open, sb.st_mode);
    
    printf("Permissions will be copied\n");
    } 
    else if(argc == 3 ) //total 3 arg 
    {
    fd_source_open = open(argv[1],O_RDONLY,0666); //source file open
   
    fd_dest_open = open(argv[2],O_CREAT | O_EXCL | O_WRONLY, 0666);

//    fchmod(fd_dest_open, sb.st_mode);
    }
    else
    {

        printf("Insufficient arguments\nUsage:-./my_copy [option] [source] [destination]\n");
        return 0;
    }
    if(fd_source_open == -1) //source file not found
    {
        printf("Source File Not Found\n");
        return 0;
    }
    else if(errno == EEXIST)
     {
        
    // fd_dest_open = open(argv[2],O_CREAT | O_EXCL | O_WRONLY, 0666);
         printf("./my_copy [option] source.txt dest.txt File  already exists.\n Do you want to overwrite (Y/N) \n");
         scanf("%c",&opt);
         if(opt == 'y' || opt == 'Y')
         {
              //printf("Track bit -> %d\n",track);
              //truncate and copy
             if(track)
             {
             fd_dest_open = open(argv[3], O_TRUNC | O_WRONLY);
             fchmod(fd_dest_open, sb.st_mode);
             }
             else
             fd_dest_open = open(argv[2], O_TRUNC | O_WRONLY);
    
              do{

                     memset(buff,0,sizeof(buff));
                     ret = read(fd_source_open, buff, 50);
                     write(fd_dest_open,buff,50);


                  }while(ret != 0);

              track = 0;

         }
         else 
         {
             return 0;
         }



     }
     else //anyways destination is created here 
     {
         
       
              do{

                     memset(buff,0,sizeof(buff));
                     ret = read(fd_source_open, buff, 50);
                     write(fd_dest_open,buff,50);


                  }while(ret != 0);

     }





    return 0;

}
