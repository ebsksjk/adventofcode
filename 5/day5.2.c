#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/stdlib.h>
#include "stack.h"

int main() {

	cstack* stack1 = &(cstack) {.pointer = -1};
	cstack* stack2 = &(cstack) {.pointer = -1};
	cstack* stack3 = &(cstack) {.pointer = -1};
	cstack* stack4 = &(cstack) {.pointer = -1};
	cstack* stack5 = &(cstack) {.pointer = -1};
	cstack* stack6 = &(cstack) {.pointer = -1};
	cstack* stack7 = &(cstack) {.pointer = -1};
	cstack* stack8 = &(cstack) {.pointer = -1};
	cstack* stack9 = &(cstack) {.pointer = -1};

	cstckpsha(stack1, (char* []){ "H", "T", "Z", "D" }, 										4);
	cstckpsha(stack2, (char* []){ "Q", "R", "W", "T", "G", "C", "S"}, 			7);
	cstckpsha(stack3, (char* []){ "P", "B", "F", "Q", "N", "R", "C", "H" }, 8);
	cstckpsha(stack4, (char* []){ "L", "C", "N", "F", "H", "Z" }, 					6);
	cstckpsha(stack5, (char* []){ "G", "L", "F", "Q", "S" }, 								5);
	cstckpsha(stack6, (char* []){ "V", "P", "W", "Z", "B", "R", "C", "S" }, 8);
	cstckpsha(stack7, (char* []){ "Z", "F", "J" }, 													3);
	cstckpsha(stack8, (char* []){ "D", "L", "V", "Z", "R", "H", "Q" }, 			7);
	cstckpsha(stack9, (char* []){ "B", "H", "G", "N", "F", "Z", "L", "D" }, 8);
	
	//printf("p1: %d, p2: %d, p7: %d, p8: %d, p9: %d\n", stack1->pointer, stack2->pointer, stack7->pointer, stack8->pointer, stack9->pointer);

	FILE* file = fopen("input.txt", "r");
	(file == NULL) ? exit(EXIT_FAILURE): 0;
	
	char* line;
	size_t buflen = 0;
	ssize_t linelen;

	const char* errstring;

	while((linelen = getline(&line, &buflen, file)) != -1) {
		if(linelen <= 1) continue;

		line[strcspn(line, "\n")] = '\0';

		//printf("%s\n", line);
		
		char* trash = strtok(line, " ");
		char* ccunt = strtok(NULL, " ");
					trash = strtok(NULL, " ");
		char* csrc	= strtok(NULL, " ");
					trash = strtok(NULL, " ");
		char* cdest	= strtok(NULL, " ");

		//printf("count: %s\nfrom: %s\nto: %s\n", ccunt, csrc, cdest);

		int count = strtonum(ccunt, 0, 1000, &errstring);
		int src	  = strtonum(csrc, 0, 1000, &errstring);
		int dest  = strtonum(cdest, 0, 1000, &errstring);
		
		cstack* crates = &(cstack){.pointer = -1};		
	
		for(int i=0; i < count; i++){

			switch(src) {
				case 1:
					cstckpsh(crates, cstckpp(stack1));
					break;
				case 2:
					cstckpsh(crates, cstckpp(stack2));
					break;
				case 3:
					cstckpsh(crates, cstckpp(stack3));
					break;
				case 4:
					cstckpsh(crates, cstckpp(stack4));
					break;
				case 5:
					cstckpsh(crates, cstckpp(stack5));
					break;
				case 6:
					cstckpsh(crates, cstckpp(stack6));
					break;
				case 7:
					cstckpsh(crates, cstckpp(stack7));
					break;
				case 8:
					cstckpsh(crates, cstckpp(stack8));
					break;
				case 9:
					cstckpsh(crates, cstckpp(stack9));
					break;
			}
		}

		for(int i=0; i < count; i++) {
			switch(dest) {
				case 1:
					cstckpsh(stack1, cstckpp(crates));
					break;
				case 2:
					cstckpsh(stack2, cstckpp(crates));
					break;
				case 3:
					cstckpsh(stack3, cstckpp(crates));
					break;
				case 4:
					cstckpsh(stack4, cstckpp(crates));
					break;
				case 5:
					cstckpsh(stack5, cstckpp(crates));
					break;
				case 6:
					cstckpsh(stack6, cstckpp(crates));
					break;
				case 7:
					cstckpsh(stack7, cstckpp(crates));
					break;
				case 8:
					cstckpsh(stack8, cstckpp(crates));
					break;
				case 9:
					cstckpsh(stack9, cstckpp(crates));
					break;
			}
		}

			//printf("%s\n", crate);
	}
	
	printf("stack1: %s\n", cstckpk(stack1));
	printf("stack2: %s\n", cstckpk(stack2));
	printf("stack3: %s\n", cstckpk(stack3));
	printf("stack4: %s\n", cstckpk(stack4));
	printf("stack5: %s\n", cstckpk(stack5));
	printf("stack6: %s\n", cstckpk(stack6));
	printf("stack7: %s\n", cstckpk(stack7));
	printf("stack8: %s\n", cstckpk(stack8));
	printf("stack9: %s\n", cstckpk(stack9));

	exit(EXIT_SUCCESS);
}
