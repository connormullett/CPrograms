
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int main(){
    
    bst* b = create();

    insert(b, 2);
    insert(b, 4);
    insert(b, 1);
    insert(b, 3);
    insert(b, 5);

    Node* searchedTerm = search(b, 3);

    return 0;
}

