#include <stdio.h>

int main(void){
	FILE *file =fopen("res.txt","w");
	fprintf(file,"Результат");
	fclose(file);
	return 0;}
