
#include <stdio.h>

int main(){
    
    int *ptr, q; 
    q = 50;

    ptr = &q;
    printf("variables --\n");
    printf("value    :: %d\n", q);
    printf("location :: %p\n", &q);
    printf("pointers  -- \n");
    printf("value at :: %d\n", *ptr);
    printf("pointer  :: %p\n", ptr);
    // * - get value of the variable the the pointer is pointing to
    // & - get memory address of variable

    return 0;
}

