#include <stdio.h>
int main(void)
{
    int N,flag=1;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<N;i++){
        
        if (arr[N-1]>arr[i]){printf("%d ",arr[i]);flag=0;}
                        }
   if(flag)printf("0");
    return 0;
}
