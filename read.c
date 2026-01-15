#include <stdio.h>

int main(void){
	char rf[100];
	printf("Какой файл читать?");
	scanf("%s",rf);
	int num;
FILE *file = fopen(rf,"r");
while(fscanf(file,"%d",&num)==1){
	printf("Число:%d\n",num);}
	fclose(file);
	return 0;

}
