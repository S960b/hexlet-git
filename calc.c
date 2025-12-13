#include <stdio.h>
int main (void) {
    double a,b;
    char op;
    scanf("%c%lf%lf",&op,&a,&b);
    
    switch (op){
        case '+': printf("%.2lf",a+b);break;
            case '-': printf("%.2lf",a-b);break;
            case '*': printf("%.2lf",a*b);break;
            case '/': printf("%.2lf",a/b);break;
        default:printf("ERROR!");break;
    }
    
}
