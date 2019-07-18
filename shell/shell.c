
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

#define MAX_LEN 1024
#define TOKEN_SEP " \t\n\r"

typedef struct {
  // name of program
  char *programName;

  // io redirections, -1 means no redirect
  int redirect[2];

  // args must be null terminated
  char *args[];
} cmd_struct;


void displayPrompt();
cmd_struct *parseCommand(char *str);
char *nextNonEmpty(char **line);

int main(int argc, char* argv[]) {

  char *buffer;
  size_t bufsize = 32;
  size_t characters;

  printf("%d\n", argc);

  buffer = (char*)malloc(bufsize * sizeof(char));
  if(buffer == NULL) {
    // catch if bufsize is too small
    printf("unable to allocate buffer\n");
    exit(1);
  }

  while(1){

    // display prompt
    displayPrompt();

    // set the buffer
    buffer = (char*)malloc(bufsize * sizeof(char));
    // getline from stdin
    characters = getline(&buffer, &bufsize, stdin);

    // parse the command into different chunks
    cmd_struct command = *parseCommand(buffer);

    if(strcmp(command.programName, "exit") == 0) {
      exit(0);
    }

    execvp(command.programName, command.args);

  } 
}


cmd_struct *parseCommand(char *str) {
  // copy input line, save it for later??
  char *copy = strndup(str, MAX_LEN);
  char *token;
  int i = 0;

  cmd_struct *ret = calloc(sizeof(cmd_struct) + MAX_LEN * sizeof(char*), 1);

  while (token = nextNonEmpty(&copy)) {
    ret->args[i++] = token;
  }

  ret->programName = ret->args[0];
  ret->redirect[0] = ret->redirect[1] = -1;
  return ret;
}


char *nextNonEmpty(char **line){
  char *tok;

  // consume empty tokens
  while((tok = strsep(line, TOKEN_SEP)) && !*tok);

  return tok;
}


void displayPrompt(){
  // get username 
  char *name = getenv("USER");

  // get hostname
  char hostname[HOST_NAME_MAX + 1];
  hostname[HOST_NAME_MAX] = 0;

  gethostname(hostname, HOST_NAME_MAX);

  // get priv status and display prompt
  int a = getuid();
  if(a==0) {
    printf("%s@%s# ", name, hostname);
  } else {
    printf("%s@%s$ ", name, hostname);
  }

}

