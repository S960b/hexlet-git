#include <stdio.h>

int main(void){
	char rf[100];
	printf("Какой файл читать?");
	scanf("%s",rf);
	int num;
	int arrall[10000],arrmax[3];
	int i=0,max=0;
FILE *file = fopen(rf,"r");
while(fscanf(file,"%d",&num)==1){
	arrall[i]=num;
	i=i+1;
	//printf("Число:%d\n",num);
	}
	fclose(file);
	for(int k=0;k<=3;k++){
	for(int j=0;j<=i;j++){
		if(arrall[j]>max){max=arrall[j];arrmax[k]=arrall[j];
		arrall[j] = arrall[i - 1];i=i-1;
		}
	}
	}
	for(int k=0;k<=3;k++){ 
	printf("Число:%d\n",arrmax[k]);
	}
	return 0;

}
