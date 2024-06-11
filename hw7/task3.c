#include <stdio.h>
#include <string.h>

/*
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4
элемента.
Данные на входе: 12 целых чисел через пробел
Данные на выходе: 12 целых чисел через пробел
Пример №1
Данные на входе: 4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе: 1 0 5 7 4 -5 3 10 -4 -6 8 -10
Пример №2
Данные на входе: 1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе: 9 10 11 12 1 2 3 4 5 6 7 8
*/

int main(void){
    int size = 12,m[size];
    printf("Ввод массива:   ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &m[i]);
    }
    
    int step = 4;

    while (step > 0)
    {
        int prev = 0, last = m[size-1];
        for (int i = size-1; i >= 0; i--)
        {
            if (i == 0){
                m[i] = last;
                continue;
            }
            prev = m[i];
            m[i] = m[i-1];
        }   
        step--;
    }

    printf("Результат:\t");
    for (int i = 0; i < size; i++)
    {
        printf("%d", m[i]);
        if (i < 11){
            printf(" ");
        }
        
    }
    printf("\n");

    return 0;
}