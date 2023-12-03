#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main(int argc, char *argv[]) {
    
    
    uproc details;
    int p,x;
    
    
    for(p=0;p<NPROC;p++)
    {
    x = getprocinfo(p, &details);//syscall getproc info calling for every process in ptable

    if (x != -1  && strcmp(details.state,"UNUSED")!=0) {//if process exist and fetched succesfully
        printf(1, "\nID: %d\n", details.pid);
        printf(1, "PPID: %d\n", details.parent_pid);
        printf(1, "Name: %s\n", details.name);
        printf(1, "State: %s\n", details.state);
        printf(1, "Size: %d bytes\n", details.size);
        printf(1, "Waiting: %d\n", details.waiting);
        printf(1, "Killed: %d\n", details.killed);
    } 
    else if(x==-1){//error in fetching by syscall
        printf(1, "Error: Unable to retrieve process information.\n");
    }
    
    
    }

    return x;
}

