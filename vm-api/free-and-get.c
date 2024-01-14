#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int* arr = (int*) malloc(10 * sizeof(int));
    free(arr);
    
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    
    arr[0] = 11;
    
    return 0;
}