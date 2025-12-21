#include <stdio.h>
int main(void)
{
int F0=0,F1=1,F2,N;
    scanf("%d",&N);
    for (int i=3;i<=N;i++){
      
        F2=F0+F1;
        F0=F1;
        F1=F2;}
     printf("%d",F0+F1);  
   
    return 0;
}
     
