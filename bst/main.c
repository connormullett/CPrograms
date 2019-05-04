
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int main(){
    
    bst* b = create();
    printf("bst  :: %lu\n", sizeof(b));
    printf("root :: %lu\n", sizeof(b->root));

    return 0;
}

