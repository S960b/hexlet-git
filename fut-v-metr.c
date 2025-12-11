#include <stdio.h>
int main(void)
{
double f,d;
    scanf("%lf%lf",&f,&d);
    printf("%.0lf'%.0lf\" = %.2lf m",f,d,f*0.3048+d*0.0254);
    return 0;
}
