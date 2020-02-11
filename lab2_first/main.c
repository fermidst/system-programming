#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeOfMemInByte = 1048576;
    int sizeOfInt = sizeof(int);
    int *pointer = (int *) malloc(sizeOfMemInByte);

    printf("Pointer address: %p\n", pointer);
    printf("end of pointer: %p", (pointer + sizeOfMemInByte / sizeOfInt));

    free(pointer);
    return 0;
}


