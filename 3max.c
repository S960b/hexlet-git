#include <stdio.h>

int main(void){
        char rf[100];
        printf("Какой файл читать?");
        scanf("%s",rf);
        int num;
        int arrall[10000];
        int i=0,max=0,temp;
FILE *file1 = fopen(rf,"r");
while(fscanf(file1,"%d",&num)==1){
        arrall[i]=num;
        i=i+1;
        }
        fclose(file1);

FILE *file2 = fopen("output.txt","w");
        for(int z=0;z<3;z++){
            max = arrall[0];  // Сбрасываем max!
			temp = 0;         // Сбрасываем temp!
        for(int j=0;j<i;j++){
                if(arrall[j]>max){max=arrall[j];temp=j;}
                                }
                fprintf(file2,"%d\n",max);
                arrall[temp]=arrall[i-1]; i=i-1;

                            }
    fclose(file2);
        return 0;

}

