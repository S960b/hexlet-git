#include <stdio.h>

int main(void){
	FILE *file =fopen("/uploads/res.txt","r");
	int num;
	while (fscanf(file, "%d", &num) == 1) {
        printf("Прочитано: %d", num);
    }
	fclose(file);
return 0;}
