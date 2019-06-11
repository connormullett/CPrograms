
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"


int main(){
    
    bst* b = create();

    for(int i = 0; i < 4; ++i){
        unsigned short int x = rand();
        insert(b, x);
    }

    insert(b, 10);

    print(b);
    Node* searchedNode = search(b, 10);
    printf("seached node  :: %d\n", searchedNode->data);

    pop(b, 10);
    print(b);

    return 0;
}

