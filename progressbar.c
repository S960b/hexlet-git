#include <stdio.h>
int main(void)
{
int p;
    scanf("%d",&p);
    printf("%3d% [",p);
   for(int i=1;i<=p/2;i++) printf("#");
    if (p%2)printf(":");
    for(int i=1;i<=50-p/2-p%2;i++) printf(".");
    printf("]");
    return 0;
}
