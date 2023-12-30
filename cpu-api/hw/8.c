#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    //Init pipe
    const int p1[2];
    pipe(p1);    

    //Create two child process
    const int pid1 = fork();

    int pid2;
    if (pid1 != 0) {
        pid2 = fork();
    }
    
    if ((pid1 > 0) && (pid2 > 0)) {
        return 0;
    }

    const int pid = getpid();
    const char helloFromOneToAnother [] = "This is the original string";
    if (pid1 == 0) {
        write(p1[1], helloFromOneToAnother, strlen(helloFromOneToAnother));
        printf("Send str \"%s\", PID: %d\n", helloFromOneToAnother, pid);
        
        return 0;
    }

    if (pid2 == 0) {
        char buf[strlen(helloFromOneToAnother)];
        read(p1[0], buf, sizeof(buf));
        printf("Got stirng: \"%s\", PID: %d\n", buf, pid);

        return 0;
    }

    return 0;
}
