#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,  char* args[]) {
    const int fds = open("./fork_2.out", O_CREAT | O_TRUNC | O_WRONLY);
    if (fds < 0) {
        fprintf(stderr, "File cannot be open, filde descriptor: %d, PID: %d\n", fds, getpid());
        return 1;
    }

    const int rc = fork();
    const pid = getpid();
    printf("Started PID: %d\n",pid);


    const int len = 50;
    const char * text = malloc(len);
    snprintf(text, len, "Hello file PID: %d\n", pid);
    write(fds, text, strlen(text));

    free(text);
}