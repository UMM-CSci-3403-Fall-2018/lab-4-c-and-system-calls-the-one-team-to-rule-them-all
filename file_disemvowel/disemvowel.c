#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "disemvowel.h"

#define BUF_SIZE 1024

bool is_vowel(char c)
{
  switch(c) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      return true;
    default:
      return false;
  }
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
  int non_vowels = 0;
  for(int i = 0; i < num_chars; i++){
    //copy non vowels to the out buffer
    if(!is_vowel(in_buf[i])) {
      out_buf[non_vowels] = in_buf[i];
      non_vowels++;
    }
  }

  return non_vowels;
}


void disemvowel(FILE* inputFile, FILE* outputFile) {
  // create the buffers
  char in_buf[BUF_SIZE];
  char out_buf[BUF_SIZE];
  int num_chars = BUF_SIZE;

  while(num_chars != 0) {
    // read from the FILE
    num_chars = fread(in_buf, 1, BUF_SIZEtest, inputFile);
    // disemvowel the in_buf, put the result in out_buf
    int out_chars = copy_non_vowels(num_chars, in_buf, out_buf);
    // write the out_buf to the output file
    fwrite(out_buf, 1, out_chars, outputFile);
  }



}

int main(int argc, char *argv[]) {
  FILE *inputFile;
  FILE *outputFile;

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.
    switch (argc)
    {
      case 1:
        inputFile = stdin;
        outputFile = stdout;
        break;

      case 2:
        // only an input file was given
        inputFile = fopen(argv[1], "r");
        outputFile = stdout;
        break;

      case 3:
        // input and output files given
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
        break;

      default:
        printf("Too many parameters\n");
        return 1;

    }

    disemvowel(inputFile, outputFile);

    return 0;
}
