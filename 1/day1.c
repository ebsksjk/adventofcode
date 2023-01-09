#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <bsd/stdlib.h>
#include <err.h>
#include <string.h>

#define NOP 0

int main() {
  FILE *fp = fopen("input.txt", "r");
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  (fp == NULL) ? exit(EXIT_FAILURE) : NOP;

  int CEC = 0; //current elf calories
  int HEC = 0; //highest elf calories
  int SEC = 0; //second highest elf calories
  int TEC = 0; //third highest elf calories
  const char *errstr;

  while ((read = getline(&line, &len, fp)) != -1) {
    if(read == 1) {
      if(CEC > TEC) {
        if(CEC > SEC) {
          if(CEC > HEC) {
            TEC = SEC; SEC = HEC; HEC = CEC;
          } else {
            TEC = SEC; SEC = CEC;
          }
        } else {
          TEC = CEC;
        }
      }
      CEC = 0;
    } else {
      len = strlen(line);
      (line[len-1] == '\n') ? line[len-1] = 0 : NOP;
      int calories = strtonum(line, 1, 1000000, &errstr);
      (errstr) ? errx(1,"error! %s: %s", errstr, line) : NOP;
      CEC += calories;
    }
  }

  printf("highest calories: %d \n", HEC);
  printf("2nd highest: %d \n", SEC);
  printf("3rd highest: %d \n", TEC);
  printf("total of top 3: %d \n", HEC + SEC + TEC);

  free(line);
  free(fp);
  free(errstr);
  exit(EXIT_SUCCESS);
}
