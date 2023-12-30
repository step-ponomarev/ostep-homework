#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int x = 100;
    const int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    }

    //child process
    if (rc == 0) {
        x = 181;
    }

    printf("X variable: %d, pid: %d\n", x, getpid());

    return 0;
}