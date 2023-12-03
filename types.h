typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;

typedef struct uproc {
      char name[16];         // Process name (debugging)
    int pid;               // Process ID
    int parent_pid;        // Parent process ID
    uint size;             // Size of process memory (bytes)
   char state[20] ; // Process state
    int waiting;   // If non-zero, process is waiting on a channel
    int killed;            // If non-zero, process has been killed
} uproc;

