#include <stdio.h>
int main(void)
{
    int a,b,c,d;
scanf("%d",&a);
    b=a/100;
    c=a%100/10;
    d=a%10;
    printf("%d",b+c+d);
    return 0;
}
