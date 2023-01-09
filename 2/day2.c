#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------------------------------

#define NOP 0

#define WIN  6
#define DRAW 3
#define LOSE 0

#define ROCK     1
#define PAPER    2
#define SCISSORS 3

//------------------------------------------------------

int main() {
  FILE *file = fopen("input.txt", "r");
  (file == NULL) ? exit(EXIT_FAILURE) : NOP;
  
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  
  char split[] = " ";
  char* str;
  
  int score = 0;

  while((read = getline(&line, &len, file)) != -1) {
    str = strtok(line, split);
  
    char* opponent = str;
    str = strtok(NULL, split);
    int o;

    char* me = str;
    str = strtok(NULL, split);
    me[strcspn(me, "\n")] = 0;
    int m;

    if(!strcmp(opponent, "A")) { 
      o = ROCK;
    } else {  
      if(!strcmp(opponent, "B")) {
        o = PAPER;
      } else {
        if(!strcmp(opponent, "C")) {
          o = SCISSORS;
        }
      }
    }

    //loose the game
    if(!strcmp(me, "X")) {
      printf("I need to loose!\n");
      switch(o) {
        case ROCK:
          m = SCISSORS;
          score += m;
          break;
        case PAPER:
          m = ROCK;
          score += m;
          break;
        case SCISSORS:
          m = PAPER;
          score += m;
          break;
      }
    } else {
      //draw the game
      if(!strcmp(me, "Y")) {
        printf("I need to draw!\n");
        m = o;
        score += o;
      } else {
        //win the game
        if(!strcmp(me, "Z")) {
          printf("I need to win!\n");
          switch(o) {
            case ROCK:
              m = PAPER;
              score += m;
              break;
            case PAPER:
              m = SCISSORS;
              score += m;
              break;
            case SCISSORS:
              m = ROCK;
              score += m;
              break;
          }
        }
      }
    }

    printf("opponent: %d\n", o);
    printf("me: %d\n", m);

    if(o == m){
      printf("Draw!\n");
      score += DRAW;
      continue;
    }
    if(m == 1 && o == 3){
      printf("WIN!\n");
      score += WIN;
      continue;
    }
    if(m == 2 && o == 1){
      printf("WIN!\n");
      score += WIN;
      continue;
    }
    if(m == 3 && o == 2) {
      printf("WIN!\n");
      score += WIN;
      continue;
    }

    printf("LOSE!\n");
  
  }

  printf("Score: %d\n", score);
  
  free(str);
  free(file);
  return(EXIT_SUCCESS);
}
