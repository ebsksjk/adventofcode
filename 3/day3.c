#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////

#define NOP 0

///////////////////////////////////////////////////////////////////////////////

int calcPriority(char x);

///////////////////////////////////////////////////////////////////////////////


int main(int argc, char* argv[]) {
  
  FILE* file = fopen("input.txt", "r");
  (file == NULL) ? exit(EXIT_FAILURE) : NOP;

  char* line = NULL;
  size_t buf_len = 0;
  ssize_t llen;

  int sum = 0;

  while ((llen = getline(&line, &buf_len, file)) != -1) {
    if(llen == 1) break;
    line[strcspn(line, "\n")] = '\0';
    llen -= 1;

    int mid = llen / 2;
    char half1[mid + 1];
    char half2[mid + 1];

    for(int i = 0; i < mid; i++) {
      half1[i] = line[i];
    }
    half1[llen / 2] = '\0';

    for(int i = mid, k = 0; i < strlen(line); i++, k++){
      half2[k] = line[i];
    }
    half2[llen / 2] = '\0';
    
    int found = 0;

    for(int x = 0; x <= mid; x++) {
      for(int i = 0; i <= mid; i++) {
        if(half1[i] == half2[x]) {
          printf("%s:%d; ", line, strlen(line));
          printf("half 1: %s, %d; ", half1, strlen(half1));
          printf("half 2: %s, %d; ", half2, strlen(half2));
          printf("Doppel: %c; ", half1[i]);
          printf("priority: %d\n", calcPriority(half1[i]));
          sum += calcPriority(half1[i]);
          found = 1;
          break;
        }
      }
      if(found) break;
    }
  }

  printf("Sum: %d\n", sum);

  free(file);
  exit(EXIT_SUCCESS);
}

///////////////////////////////////////////////////////////////////////////////

int calcPriority(char x) {
  if(x >= 'a' && x <= 'z'){
    return (x - 96);
  } else {
    switch(x) {
      case 'A':
        return 27;
      case 'B':
        return 28;
      case 'C':
        return 29;
      case 'D':
        return 30;
      case 'E':
        return 31;
      case 'F':
        return 32;
      case 'G':
        return 33;
      case 'H':
        return 34;
      case 'I':
        return 35;
      case 'J':
        return 36;
      case 'K':
        return 37;
      case 'L':
        return 38;
      case 'M':
        return 39;
      case 'N':
        return 40;
      case 'O':
        return 41;
      case 'P':
        return 42;
      case 'Q':
        return 43;
      case 'R':
        return 44;
      case 'S':
        return 45;
      case 'T':
        return 46;
      case 'U':
        return 47;
      case 'V':
        return 48;
      case 'W':
        return 49;
      case 'X':
        return 50;
      case 'Y':
        return 51;
      case 'Z':
        return 52;
    }
  }
}
