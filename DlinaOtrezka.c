#include <stdio.h>
#include <math.h>
\\На вход программы поступают четыре числа координаты двух точек на плоскости Sample Input:64.52 41.97 -77.86 -58.37
int main() {
   float x1,y1,x2,y2;
    scanf("%f.%f %f.%f", &x1,&x2,&y1,&y2);
    printf("%.2f",sqrt(pow((x2-x1),2)+(pow((y2-y1),2))));
    return 0;
}
