#include <stdio.h>
#include <stdlib.h>

// func that takes func that takes memory address and value to store

void* first(__uint32_t* address, __uint32_t value){
    *address = value;
    return address;
}

void* second(void* (*pointer)(__uint32_t*, __uint32_t), __uint32_t* address, __uint32_t value){
    return pointer(address, value);
}

int main()
{
    __uint32_t* test = second(first, malloc(sizeof(__uint32_t)), 65537);
    printf("%d", *test);
    return 0;
}
