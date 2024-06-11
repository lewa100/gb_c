#include <stdio.h>
#include <string.h>

/*
Считать массив из 10 элементов и отобрать в другой массив все числа, у
которых вторая с конца цифра (число десятков) – ноль.
Данные на входе: 10 целых чисел через пробел.
Данные на выходе: Целые числа через пробел, у которых вторая с конца
цифра - ноль
Пример
Данные на входе: 40 105 203 1 14 1000 22 33 44 55
Данные на выходе: 105 203 1 1000
*/

int check(int x){
   return x%100; 
}


int main(void){
    int size = 10,m[size];
    printf("Ввод массива:   ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &m[i]);
    }
    
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if(check(m[i])<10){
            count++;
        }
    }
    
    if (count > 0){
        int n[count];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if(check(m[i])<10){
                n[j] = m[i];
                j++;
            }
        }
        printf("Результат:\t");
        for (int i = 0; i < count; i++)
        {
            printf("%d", n[i]);
            if (i < size-1){
                printf(" ");
            }
            
        }
        printf("\n");
        return 0;
    }
    printf("Не найдено!\n");
    return 0;   
}