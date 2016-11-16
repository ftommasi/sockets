#include <sys/types.h>          
#include <sys/socket.h>
#include <stdio.h>
int main( int argc, char** argv){
 
  int s =  socket(AF_LOCAL, SOCK_STREAM, 0);


  return 0;
}
