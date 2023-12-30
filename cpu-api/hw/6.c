#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const int pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    }

    //child process
    if (pid == 0) {
        printf("Hello\n");
    } else {
        waitpid(pid, NULL, 0); // ensure hello first
        printf("Goodbye\n");
    }

    return 0;
}