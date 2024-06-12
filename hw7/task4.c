#include <stdio.h>
#include <string.h>

/*
Считать массив из 10 элементов и отсортировать его по последней цифре.
Данные на входе: 10 целых чисел через пробел
Этот же массив отсортированный по последней цифре
Пример №1
Данные на входе: 14 25 13 30 76 58 32 11 41 97
Данные на выходе: 30 11 41 32 13 14 25 76 97 58
Пример №2
Данные на входе: 109 118 100 51 62 73 1007 16 4 555
Данные на выходе: 100 51 62 73 4 555 16 1007 118 10
*/

int mod(int x){
    return x%10;
}

int main(void){
    int size = 10,m[size];
    printf("Ввод массива:   ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &m[i]);
    }
    
    while (1)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (mod(m[i]) > mod(m[i+1]) && i != size-1){
                int tmp = m[i];
                m[i] = m[i+1];
                m[i+1] = tmp;
                count++;
            }
        }
        if (count == 0){
            break;
        }
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