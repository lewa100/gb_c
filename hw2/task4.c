#include <stdio.h>

int main(void){
    int x, x1,x2,x3,x4, sum;
    scanf("%d", &x);
    x1 = x%10;
    x2 = x/10%10;
    x3 = x/100%10;
    x4 = x/1000;
    sum = x1 + x2 + x3 + x4;
    printf("%.2f\n",sum/4.); 

    return 0;
}