#include <stdio.h>
/*
Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a
до b.
Данные на входе: Два целых числа по модулю не больше 100
Данные на выходе: Сумма квадратов от первого введенного числа до
второго
Пример №1
Данные на входе: 4 10
Данные на выходе: 371
Пример №2
Данные на входе: 1 5
Данные на выходе: 55
*/


int main(void){
    int a, b, res = 0;
    printf("Значение А: ");
    scanf("%d", &a);
    printf("Значение B: ");
    scanf("%d", &b);
    if(a > b){
        res = a;
    }else{
        for (int i = a; i <= b; i++)
        {
            res += i * i;
        }
    }
    printf("\nРезультат: %d\n", res); 
    return 0;
}