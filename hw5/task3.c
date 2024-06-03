#include <stdio.h>

/*
Составить логическую функцию, которая определяет, верно ли, что в заданном
числе сумма цифр равна произведению.
int is_happy_number(int n)
Данные на входе: Целое не отрицательное число
Данные на выходе: YES или NO
Пример №1
Данные на входе: 123
Данные на выходе: YES
Пример №2
Данные на входе: 528
Данные на выходе: NO
*/

int is_happy_number(int n){
    int sum = 0, multi = 1;
    if (n <= 0){
        return 0;
    }

    while ( n > 0){
        int step = n%10;
        multi *= step;
        sum += step; 
        n /= 10;
    }  

    if (sum == multi){
        return 1;
    }

    return 0;
}

int main(void){
    int n;
    printf("Ввод числа: ");
    scanf("%d", &n);
    
    if (is_happy_number(n)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}