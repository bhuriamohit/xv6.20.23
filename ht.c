#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main(int argc, char *argv[]) {
    int x=2;
    
  
    char buff[128];
    
    int y=history(buff,x);
    
   
     printf(1, " status:%d     command: %s\n", y,buff);
     
     return x;
    
}

