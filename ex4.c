#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int min(size_t* a,size_t* b){
	if (*a > *b){
		return *b;
	}
	return *a;
}
void* my_realloc(void* ptr, size_t size){
	if(ptr == NULL){
		return ptr = malloc(size);
	}
	if(size == 0){
		free(ptr);
		return ptr;
	}
	size_t minsize;
	minsize = malloc_usable_size(ptr);
	minsize = min(&minsize, &size);
	void* nptr;
	nptr = malloc(size);
	nptr = memcpy(nptr, ptr, minsize);
	free(ptr);

	return nptr;
}
int main(){
	int* arr = (int*)calloc(5,sizeof(int));
	for (int i = 0; i < 5; i++){
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	arr = (int*)my_realloc(arr, 8*sizeof(int));
	for (int i = 0; i < 8; i++){
		printf("%d ", arr[i]);
	}

}
