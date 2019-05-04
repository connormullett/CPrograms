#include <stdio.h> 
#include <stdlib.h>

int factorial(int num);

int main(int argc, char** argv){
    
    int input;

    if(argc > 1){
        input = atoi(argv[1]);
    } else {
        scanf("%d", &input);
    }

    int out = factorial(input);
    printf("%d\n", out);

    return 0;
}

int factorial(int num){
    
    int out = 1;
    int i = 1;

    while(i <= num){
        out *= i;
        i++;
    }

    return out;
}

