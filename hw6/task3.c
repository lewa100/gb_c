#include <stdio.h>
#include <string.h>

/*
Дано натуральное число N. Посчитать количество «1» в двоичной записи
числа.
Данные на входе: Натуральное число
Данные на выходе: Целое число - количество единиц в двоичной записи
числа.
Пример №1
Данные на входе: 5
Данные на выходе: 2
Пример №2
Данные на входе: 255
Данные на выходе: 8
*/

int twice_counter(int a){
    int count = 0;

    if (a > 0){
        if (a%2 == 0){
            a/=2;
        } else{
            count++;
            a &= a - 1;
        }
        count += twice_counter(a);
    }

    return count;
}

int main(void){
    int a,b;
    printf("Ввод числа A: ");
    scanf("%d", &a);
    
    printf("Результат: %d",twice_counter(a));
    return 0;
}