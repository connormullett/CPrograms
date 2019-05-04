
#include <stdio.h>

int findSize(char* file);

int main(int argc, char** argv){

    int out;

    if(argc == 1){
        printf("usage: %s filename", argv[0]);
    } else {
        out = findSize(argv[1]);
        if(out == -1){
            printf("file not found");
        } else {
            printf("%d bytes\n", out);
        }
    }
        
    return 0;
}

int findSize(char* file){
    FILE *fp = fopen(file, "r");

    if(fp == NULL || fp == 0){
        return -1;
    }

    int i, size;
    while((i = fgetc(fp)) != EOF){
        ++size;
    }

    fclose(fp);
    return size;
}

