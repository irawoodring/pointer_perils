#include <stdio.h>
#include <stdlib.h>

/*
 * Regarding the (void *):
 * Please note that casting changes nothing value-wise
 * but is simply included to make the compiler happy
 * about printing the memory address.
 */ 

int allocateMemory2( char** arr){
	printf("==================== INSIDE OF FUNCTION! ====================\n\n");
	printf("Inside of allocateMemory2( char** arr) arr has a value of the  address %p.\n", (void *)arr);
	printf("This pointer points to *arr which holds the memory address (%p).\n", (void *)*arr);
	*arr = malloc(50 * sizeof(char));
	printf("AFTER MALLOC!\n");
	printf("This pointer now points to *arr which olds the memory address (%p).\n\n", (void *)*arr);
	printf("==================== RETURN FROM FUNCTION ====================\n\n");
	
	return 0;
}

int allocateMemory( char* arr){
	printf("==================== INSIDE OF FUNCTION! ====================\n\n");
	printf("Inside of allocateMemory( char* arr) arr has a value of the  address %p.\n", (void *)arr);
	arr = malloc(50 * sizeof(char));
	printf("AFTER MALLOC!\n");
	printf("This pointer now holds the memory address (%p).\n\n", (void *)arr);
	printf("==================== RETURN FROM FUNCTION ====================\n\n");
	
	return 0;
}

void addToX(int x){
	x = x + 1024;
	printf("\n\nFunction addToX has x = %d!\n",x);
}
