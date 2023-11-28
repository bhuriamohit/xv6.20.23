#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main(int argc, char *argv[]) {
    uproc details;
    int p = getpid();
    int x = getprocinfo(p, &details);

    if (x != -1) {
        printf(1, "\nID: %d\n", details.pid);
        printf(1, "PPID: %d\n", details.parent_pid);
        printf(1, "Name: %s\n", details.name);
        printf(1, "State: %s\n", details.state);
        printf(1, "Size: %d bytes\n", details.size);
        printf(1, "Waiting: %d\n", details.waiting_on_chan);
        printf(1, "Killed: %d\n", details.killed);
    } else {
        printf(1, "Error: Unable to retrieve process information.\n");
    }

    return x;
}

