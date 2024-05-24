#include <stdio.h>

int main(void){
    int d;
    printf("Число месяца: ");
    scanf("%d", &d);
    
    switch (d)
    {
    case 3 ... 5:
        printf("Spring\n");
        break;
    case 6 ... 8:
        printf("Summer\n");
        break;
    case 9 ... 11:
        printf("Autumn\n");
        break;
    case 12:
    case 1 ... 2:
        printf("Winter\n");
        break;
    default:
        printf("Is not month\n");
        break;
    }
    return 0;
}