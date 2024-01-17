#include"unistd.h"
#include"stdlib.h"
#include"stdio.h"
#define A_MEGABYTE (1024 * 1024) // 1Mb bo nho

int main(){
	char *some_memory;
	int megabyte = A_MEGABYTE;
	int exit_code = EXIT_FAILURE; // ket thuc ko thanh cong  
	some_memory = (char*)malloc(megabyte);
	if(some_memory != NULL){
		sprintf(some_memory, "Hello World\n");
		printf("%s", some_memory);
		free(some_memory);
		exit_code = EXIT_SUCCESS; // ket thuc thanh cong  
	}
	exit(exit_code); // ket thuc chuong trinh voi ma thoat exit_code  
}

