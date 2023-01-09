#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/stdlib.h>

#define NOP 0

int main() {
  FILE* file = fopen("input.txt", "r");
  (file == NULL) ? exit(EXIT_FAILURE) : NOP;

  char* line;
  size_t bufLen = 0;
  ssize_t lineLen;

  const char* errstring;

  int includecounter = 0;
  int overlapcounter = 0;

  while((lineLen = getline(&line, &bufLen, file)) != -1) {
    line[strcspn(line, "\n")] = '\0';

    char tmpline[64];
    strcpy(tmpline, line);
    
    char* temp1 = strtok(line, ",");
    char* temp2 = strtok(NULL, ",");

    char* startRange1 = strtok(temp1, "-");
    char* endRange1   = strtok(NULL, "-");

    char* startRange2 = strtok(temp2, "-");
    char* endRange2   = strtok(NULL, "-");
    
    int sR1 = strtonum(startRange1, 1, 10000, &errstring);
    int eR1 = strtonum(endRange1, 1, 10000, &errstring);
    int sR2 = strtonum(startRange2, 1, 10000, &errstring);
    int eR2 = strtonum(endRange2, 1, 10000, &errstring);
  
    if(sR2 >= sR1 && eR2 <= eR1) {
      //printf("range 1 contains range 2! \n");
      includecounter++;
      overlapcounter++;
    } else if(sR1 >= sR2 && eR1 <= eR2) {
      //printf("range 2 contains range 1! \n");
      includecounter++;
      overlapcounter++;
    } else if(sR2 >= sR1 && !(sR2 > eR1) || eR2 <= eR1 && !(eR2 < sR1)){
      //printf("ranges overlap!\n");
      overlapcounter++;
    } else if(sR1 >= sR2 && !(sR1 > eR2) || eR1 <= eR2 && !(eR1 < sR2)) {
      //printf("ranges overlap!\n");
      overlapcounter++;
    } else {
      //printf("%s\n", tmpline);
      asm("nop");
    }
  }
  

  printf("includes: %d\n", includecounter);
  printf("overlaps: %d\n", overlapcounter);
  free(line);
  free(file);
  exit(EXIT_SUCCESS);
}
