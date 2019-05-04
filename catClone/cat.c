
#include <stdio.h>

int main(int argc, char** argv){
    
    FILE *file = fopen(argv[1], "r");

    if(file == 0){
        printf("could not open file\n");
    } else {
        int x;
        while((x = fgetc(file)) != EOF){
            printf("%c", x);
        }
        fclose(file);
    }

    return 0;
}

