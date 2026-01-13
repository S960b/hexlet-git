#include <stdio.h>
int main (void){
	FILE *file=fopen("res.txt","r");
	int arr[6];
	int value;
	for(int i=0;i<=5;i++){
	fscanf(file,"%d\n",&value);
	printf("Прочитано:%d\n",value);
	arr[i]=value;
	}
	fclose(file);
	return 0;
}
