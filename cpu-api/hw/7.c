#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const int pid = fork();    
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    }

    if (pid != 0) {
        return 0;
    }

    close(STDOUT_FILENO);
    printf("Test\n");

    return 0;
}