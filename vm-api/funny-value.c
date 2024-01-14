#include <stdlib.h>

int main(int argc, char* argv[]) {
    int* arr = (int*) malloc(10 * sizeof(int));
    free(&arr[4]);
    
    return 0;
}