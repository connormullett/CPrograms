
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int convertBin(long long n);
void convertDec(int n);

int main(int argc, char** argv){

    int choice;
    printf("1. bin >> dec\n2. dec >> bin\n> ");
    scanf("%d", &choice);
    printf("> ");

    if(choice == 1){
        // bin >> dec
        long long n;
        scanf("%lld", &n);
        printf("%d\n", convertBin(n));

    } else if(choice == 2){
        // dec >> bin
        int n;
        scanf("%d", &n);
        convertDec(n);
    }
    
    return 0;
}

void convertDec(int n){
    int c, k;
    for(c = 31; c >= 0; --c){
        k = n >> c;
        if(k & 1) printf("1");
        else printf("0");
    }
    printf("\n");
}

int convertBin(long long n){
    int dec = 0, i = 0, rem;
    while(n != 0){
        rem = n % 10;  // last digit
        n /= 10;  // rest of the digits
        dec += rem*pow(2, i);
        ++i;
    }
    return dec;
}

