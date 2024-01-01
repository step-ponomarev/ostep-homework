#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

const static char TEXT [] = "This is the original string";

int main(int argc, char *argv[]) {
    const key_t memorySegmentKey = 1234;

    
    int shm_id = shmget(memorySegmentKey, strlen(TEXT), IPC_CREAT | IPC_R | IPC_W);
    char *str = (char*) shmat(shm_id, NULL, 0);

    const int pid1 = fork();
    int pid2;
    if (pid1 != 0) {
        pid2 = fork();
    }

    const int pid = getpid();
    if (pid1 == 0) {
        snprintf(str, strlen(TEXT), TEXT);
        return 0;
    }

    if (pid2 == 0) {
        // waiting writing by child process 1
        waitpid(pid1, NULL, 0);
        printf("%s\n", str);

        return 0;
    }

    if ((pid1 > 0) && (pid2 > 0)) {
        //waiting for child processes
        wait(NULL);
        
        //Close memory segment
        shmdt(str);
        return 0;
    }

    return 0;
}
