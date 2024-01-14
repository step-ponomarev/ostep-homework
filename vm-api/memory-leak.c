#include <stdlib.h>
const static MAGIC_VALUE = 0x4c;

int main(int argc, char* argv[]) {
    int* arr = (int*) malloc(MAGIC_VALUE * sizeof(int));

//    free(arr); oops 
    return 0;
}