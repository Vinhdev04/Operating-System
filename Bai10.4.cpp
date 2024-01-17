#include"unistd.h"
#include"stdlib.h"
#define ONE_K (1024)

int main(){
	char *some_memory;
	char *scan_ptr;
	some_memory = (char*)malloc(ONE_K);
	if(some_memory == NULL)
		exit(EXIT_FAILURE);
	scan_ptr = some_memory;
	while(scan_ptr < some_memory + ONE_K){
		*scan_ptr = '\0';
		scan_ptr++;
	}	
	free(some_memory);
	exit(EXIT_SUCCESS);
}

