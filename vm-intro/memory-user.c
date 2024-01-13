#include <stdlib.h>

int main(int argc, char* argv[]) {
    int amount = atoi(argv[1]);
    int* arr = (int*) malloc(amount * sizeof(int));

    while (1) {
        for (int i = 0; i < amount; i++) {
            arr[i] = i;
        }
    }

    free(arr);
    return 0;
}