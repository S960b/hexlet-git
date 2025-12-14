#include <stdio.h>
int main(void)
{
    int k,X,m=1;
    scanf("%d%d",&k,&X);
    switch (k){
        case 4:m=X/1000;
        case 3:m=m*((X%1000)/100);
        case 2:m=m*((X%100)/10);
        case 1:m=m*(X%10);printf("%d",m);break;
    }

    return 0;
}
