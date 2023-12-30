#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    }

    //child process
    if (rc == 0) {
        printf("Hello\n");
    } else {
        wait(NULL); // ensure hello first
        printf("Goodbye\n");
    }

    return 0;
}