#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const int rc = fork();
    
    if (rc == 0) {
        char *lsArgs[3];
        lsArgs[0] = "ls";
        lsArgs[1] = ".";
        lsArgs[2] = NULL;
        execvp(lsArgs[0], lsArgs);
    }

    // Only parant process
    printf("Here\n");

    return 0;
}