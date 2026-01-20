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
	int min_index,temp;
	for (int i = 0; i < n-1; i++) {  // n-1, а не n-2
    min_index = i;
    for (int j = i+1; j < n; j++) {  // j начинается с i+1
        if (arr[j] < arr[min_index]) {
            min_index = j;
        }
    }
    // Обмен ПОСЛЕ поиска минимума
    if (min_index != i) {  // необязательно, но эффективно
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}



for (int i = 0; i < n; i++)printf(" %d",arr[i]);
	free(arr);
	return 0;}
