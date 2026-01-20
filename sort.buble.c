#include <stdio.h>
#include <stdlib.h>
int main (void){
	int n; //количество эл-в;
	int *arr=NULL;
	printf("Кол-во эл-в:");
	scanf("%d",&n);
	arr=malloc(n*sizeof(int));
	if (arr == NULL) {
    printf("Ошибка: не удалось выделить память!\n");
    return 1;  // Завершаем программу с ошибкой
}
	for (int i=0;i<n;i++){
		printf("Введите число %d:",i);
		scanf("%d",&arr[i]);
	}
	int swapped = 1;  // флаг обменов
	int temp;
while (swapped) {
    swapped = 0;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] >arr[i+1] ) {
			temp=arr[i+1];// обмен
			arr[i+1]=arr[i];
			arr[i]=temp;
            swapped = 1;
        }
    }
}
for (int i = 0; i < n; i++)printf(" %d",arr[i]);
	free(arr);
	return 0;}
