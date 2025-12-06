#include <stdio.h>
#include <math.h>
int main(void)
{
float a,b,ygol;
    scanf("%f%f%f", &a,&b,&ygol);
    printf("%.2f",a*b*sin(ygol*3.141593/180)/2);
    return 0;
}
