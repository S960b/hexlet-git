#include <stdio.h>

int main(void){
	FILE *file =fopen("res.txt","r");
	char arr[50];
	while (fgets(line, sizeof(line), file) != NULL) {
        printf("Прочитано: %s", line);
    }
	fclose(file);
return 0;}
