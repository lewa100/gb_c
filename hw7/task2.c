#include <stdio.h>
#include <string.h>

/*
Ввести с клавиатуры массив из 5 элементов, найти минимальный из них.
Данные на входе: 5 целых чисел через пробел
Данные на выходе: Одно единственное целое число
Пример №1
Данные на входе: 4 15 3 10 14
Данные на выходе: 3
Пример №2
Данные на входе: 1 2 3 4 -5
Данные на выходе: -5
*/

int main(void){
    int m[5];
    printf("Ввод массива: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &m[i]);
    }
    
    int min = m[0];
    for (int i = 1; i < 5; i++)
    {
        if (min > m[i]){
            min = m[i];
        }
    }
    

    printf("Результат: %d\n", min);
    return 0;
}