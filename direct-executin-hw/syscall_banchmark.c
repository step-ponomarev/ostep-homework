#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>

const char FILE_NAME[] = "./fork_2.out";

int main(int argc, char *argv[]) {
    //Init pipe
    const int fds = open(FILE_NAME, O_CREAT | O_TRUNC | O_RDONLY);
    if (fds < 0) {
        fprintf(stderr, "File cannot be open, filde descriptor: %d, PID: %d\n", fds, getpid());
        return 1;
    }


    char buf[0];
    struct timeval before;
    gettimeofday(&before, NULL);
    long long beforeMs = before.tv_sec * 1000LL + before.tv_usec / 1000;
    for (int i = 0; i < 20000000; i++) {
        read(fds, buf, 0);
    }

    struct timeval after;
    gettimeofday(&after, NULL);
    long long afterMs = after.tv_sec * 1000LL + after.tv_usec / 1000;
    printf("%f\n", ((float)(afterMs - beforeMs)) / 20000000);


    close(fds);
    remove(FILE_NAME);
    
    return 0;
}
