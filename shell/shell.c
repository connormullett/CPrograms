
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


void displayPrompt();

int main() {

  char *buffer;
  size_t bufsize = 32;
  size_t characters;

  buffer = (char*)malloc(bufsize * sizeof(char));
  if(buffer == NULL) {
    // catch if bufsize is too small
    printf("unable to allocate buffer\n");
    exit(1);
  }

  // display prompt
  displayPrompt();

  // set the buffer
  buffer = (char*)malloc(bufsize * sizeof(char));
  // getline from stdin
  characters = getline(&buffer, &bufsize, stdin);

  // characters is not the characters
  printf("%s\n", buffer);
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

