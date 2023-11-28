#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "defs.h"
#include "x86.h"
void printProcessDetails(int x, uproc piro);
int story(char *buff, int id);



int sys_getprocinfo(void) {
    int num;
    uproc piro;  // Declare a single uproc structure, not a pointer

    if (argint(0, &num) < 0 || argptr(1, (void*)&piro, sizeof(uproc)) < 0) {
        return -1;
    }

    // Verify the 'num' argument or handle the error
    if (num < 0) {
        return -1;
    }

    // Call the function to print process details
    printProcessDetails(num, piro); // Pass the uproc structure, not a pointer

    return 0;
}
int sys_history(void) {
    char *buff; // Define a pointer variable
    int id;

    // Use a temporary variable to hold the pointer to the buffer
    char *temp_buff;

    if (argptr(0, (void*)&temp_buff, sizeof(char *)) < 0 || argint(1, &id) < 0) {
        return -1;
    }

    // Assign the buffer pointer from temp_buff to buff
    buff = temp_buff;

    return story(buff, id);
}


int 

sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
