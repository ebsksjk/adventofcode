#include <err.h>

typedef struct cstack {
	char* contents[100];
	int pointer;
} cstack;

void cstckpsh(cstack* stack, char* element) {

	stack->pointer += 1;
	stack->contents[stack->pointer] = element;
}

void cstckpsha(cstack* stack, char* elements[], int length){
	for(int i = 0; i < length; i++) {
		cstckpsh(stack, elements[i]);
	}
}

char* cstckpp(cstack* stack) {
	(stack->pointer == -1) ? errx(69, "Stack underflow!") : 0;
	
	stack->pointer -= 1;
	return stack->contents[stack->pointer + 1]; 
}

char* cstckpk(cstack* stack) {
	return stack->contents[stack->pointer];
}
