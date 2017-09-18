#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void clearScreen(){
	for(int i=0;i<50;i++){
		printf("\n");
	}
}

int main(int argc, char** argv){
	
	clearScreen();
	printf("We will start with an int x.  Its value is 0.\n");
	printf("We will also declare an int* y.  We will set its value to the address of x.\n\n");
	int x = 0;
	int* y = &x;
	printf("x = %d.\t\ty = %p.\n\n", x, y);
	getchar();
	printf("Now, we are going to use the * operator on y.  This will allow us to access\n");
	printf("or change the data that y points to.  Right now y points to the data x holds.\n");
	*y = 100;
	printf("We issue the statement: \n");
	printf("*y = 100;\n\n  Now:\n");
	printf("x = %d.\t\ty = %p.\n\n", x, y);
	getchar();	
	printf("Notice that the value of y didn't change.  y was (and still is) the address of x.\n\n");	
	printf("Now let's try something more advanced.\n");
	getchar();
	clearScreen();
	printf("Let's assume we need a block of memory.  It doesn't matter what we are going to\n");
	printf("do with it, but let's assume we are going to use it for an array of chars.\n");
	char* buffer;
	printf("\nchar* buffer;\n\n");
	printf("At this point buffer is stored at address %p.\n", &buffer);
	printf("And holds the value %p.\n", buffer);
	getchar();
	printf("Now, let's allocate some memory for this pointer to point to.\n");
	printf("We can use the stdlib.h malloc command to do this.\n\n");
	buffer = malloc(500 * sizeof(char));
	printf("At this point buffer is stored at address %p.\n", &buffer);
	printf("And holds the value %p.\n", buffer);
	printf("We can access the memory as a char array as such:\n\n");
	buffer[0] = 'h';
	printf("buffer[0] = '%c'\n\n", buffer[0]);
	getchar();	
	clearScreen();
	printf("Pointers become VERY useful when we want to pass parameters to\n");
	printf("functions.  Anything passed in C is passed by value.  This means\n");
	printf("that an object is never passed as a parameter - a COPY of the\n");
	printf("object is.  If we pass a variable int x = 2; to a function, the \n");
	printf("function will get its own local copy of x.  Any changes to x\n");
	printf("are on the local function's copy - not on the original object.");
	getchar();
	printf("\n\nSo, we have int x = 0;  We are going to pass it to a function\n");
	printf("addToX(int x).  This function will add 1024 to x.");
	printf("\n\nBefore the function: x = %d\n", x);	
	getchar();
	addToX(x);
	printf("\n\nAfter the function call: x = %d\n", x);
	printf("Notice x didn't change!\n\n");
	getchar();
	clearScreen();
	printf("Now... we have a problem.  If we want to (for instance) have\n");
	printf("a function declare our memory for us how would we do it?\n");
	printf("If we pass our pointer to the function and then call malloc\n");
	printf("in the function then an address will be returned from malloc\n");
	printf("that will point to our new memory area.  This new address will\n");
	printf("be stored in the pointer we passed in.  But, because C passes\n");
	printf("only by value then the value that gets overwritten is the local\n");
	printf("copy of the pointer.  When the function returns this new\n");
	printf("memory address will be lost.\n\n");
	printf("char* buffer;\n");
	printf("Value of buffer is %p.\n", buffer);
	getchar();
	allocateMemory(buffer);
	printf("Now value of buffer is %p.\n", buffer);
	printf("DIDN'T CHANGE!\n\n");
	getchar();
	clearScreen();
	printf("So what do we do?  We must instead pass a pointer to a pointer.\n");
	printf("If we pass a pointer to a pointer we have an outer reference to\n");
	printf("a pointer.  This reference will not change.  Inside the function\n");
	printf("we will malloc and store the value of our new memory on the inner\n");
	printf("pointer.  When the function returns we still have our access\n");
	printf("to the outer pointer.  If we look at the data the outer pointer\n");
	printf("points to we see that it will have changed to point to our\n");
	printf("new memory area.\n\n");
	printf("char * buffer;\nallocateMemory2(&buffer);	//We passed the address of the pointer.  This is a pointer to a pointer!\n");
	printf("\nAddress of buffer = %p.\n", &buffer);
	printf("Value of buffer = %p.\n", buffer);
	getchar();
	allocateMemory2(&buffer);
	printf("allocateMemory2(&buffer)\n\n");
	printf("Address of buffer = %p.\n", &buffer);
	printf("Value of buffer = %p.\n", buffer);
	getchar();
		
}
