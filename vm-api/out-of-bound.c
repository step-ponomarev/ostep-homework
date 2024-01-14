#include <stdlib.h>

int main(int argc, char* argv[]) {
    const int amount = 100;
    int* arr = (int*) malloc(amount * sizeof(int));

    arr[100] = 1;

    free(arr);

    return 0;
}