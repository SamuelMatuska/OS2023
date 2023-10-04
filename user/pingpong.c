#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
     int p[2], p2[2],pid;
     char buf;
    
     pipe(p);
     pipe(p2);
     pid=fork();

     if(pid==0){
      read(p[0], &buf, 1);
      printf("%d: received ping\n", getpid());
      write(p2[1], "p", 1); 
     }
     else{
        write(p[1], "p", 1);
        read(p2[0], &buf, 1);
        printf("%d: received pong\n", getpid());
     }

     exit(0);
}