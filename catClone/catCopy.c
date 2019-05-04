
#include <stdio.h>
#include <string.h>


void copy(char* inFile, char* outFile);
void cat(char* str);
int tokens(char** str);


// both need to open files
int main(int argc, char** argv){

    if(argc == 1){
        printf("usage: %s copy inputFile outputFile\n"
                "usage: %s cat file\n", argv[0], argv[0]);
        return 0;
    }

    else if(strcmp(argv[1], "t") == 0){
        int t = tokens(&argv[2]);

        if(t == 0){
            printf("error");
        } else {
            printf("%d\n", t);
        }

    } else if(argc == 2){  // copy
        cat(argv[1]);

    } else if(argc == 3){  // cat
        copy(argv[1], argv[2]);

    }

    return 0;
}

// returns 0 if error
int tokens(char** str){
    FILE *inf = fopen(*str, "r");
    int tokens;

    if(inf == 0){
        return 0;
    } else {
        int i;
        while((i = fgetc(inf)) != EOF){
            char c = i + '0';
            char* pt = &c;
            if(strcmp(pt, " ") || strcmp(pt, "\n") || strcmp(pt, "\r")){
                ++tokens;
            }
        }
    }
    return tokens;
}

void copy(char* inFile, char* outFile){
    FILE *inf = fopen(inFile, "r");
    FILE *outf = fopen(outFile, "w");

    if(inf == 0 || outf == 0){
        printf("error\n");
    } else {
        int i;
        while((i = fgetc(inf)) != EOF){
            fputc(i, outf);
        }
    }

    fclose(inf);
    fclose(outf);
}

void cat(char* str){
    FILE *file = fopen(str, "r");

    if(file == 0){
        printf("could not open file\n");
    } else {
        int x;
        while((x = fgetc(file)) != EOF){
            printf("%c", x);
        }
        fclose(file);
    }

}

