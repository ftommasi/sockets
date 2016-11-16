#include <sys/types.h>          
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/un.h>

/*
 *struct sockaddr_un {
    sa_family_t sun_family;                AF_UNIX 
    char        sun_path[UNIX_PATH_MAX];   pathname 
};
*/


int main( int argc, char** argv){
 
  int sockfd =  socket(AF_LOCAL, SOCK_STREAM, 0);
  if(sockfd == -1){
    perror("error creating socket");
    return -1;
  }
  
  struct sockaddr_un mysockaddr;
  mysockaddr.sun_family = AF_UNIX;
  mysockaddr.sun_path = "./sockdescript";
  
  socklen_t socksize =(socklen_t) sizeof(struct sockaddr_un);

  int b= bind(sockfd,  &mysockaddr, socksize);

  if(b==-1){
    perror("error binding socket");
    return -1;
  }
  int l = listen(sockfd,10);
  
  if(l==-1){
    perror("error listening to  socket");
    return -1;
  }

  int a = accept(sockfd,mysockaddr,&socksize);

  return 0;
}
