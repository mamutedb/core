#include <stdio.h>
#include <stdlib.h>
// if compiling on Windows compile these functions
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char* readLine(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

void getLine(char* unused) {}

// otherwise include the editline headers
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

// free allocated memory
void close_input_buffer(char* prompt) {
  free(prompt);
}
// end free allocated memory

int main(int argc, char** argv) {

  puts("Mamute DB v0.0.1");
  puts("\nType ':exit' To Exit\n");

  while (1) {
    char* input = readLine("mamute> ");
    getLine(input);

    if (strcmp(input, ":exit") == 0) {
      close_input_buffer(input);
      exit(EXIT_SUCCESS);
    } else {
      printf("comando desconhecido: '%s'.\n", input);
    }
  }
  return 0;
}