#include <stdio.h>
int main(void)
{
    int age, height, weight;
    double bmr;
    char sex;

    
    scanf("%c%d%d%d",&sex, &age, &height, &weight); 

    switch (sex){
        case 'm':
                bmr = 10*weight + 6.25*height - 5*age + 5;  
            printf("|  BMR  |\n");
            printf("|%7.2f|\n", bmr);break;
        case 'f':    
                bmr = 10*weight + 6.25*height - 5*age - 161;
            printf("|  BMR  |\n");
            printf("|%7.2f|\n", bmr);break;
        default: printf("ERROR!");break;
            
            }
    return 0;
}
