#include <stdio.h>
#include <string.h>

/*
Определить количество положительных элементов квадратной матрицы,
превышающих по величине среднее арифметическое всех элементов главной
диагонали. Реализовать функцию среднее арифметическое главной
диагонали.
Данные на входе: 5 строк по 5 целых чисел через пробел
Данные на выходе: Одно целое число
Пример
Данные на входе: 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
Данные на выходе: 10
*/

void print(int *m, int size){
    for (int i = 0; i < size; i++){
        printf("%d", m[i]);
        if (i < size-1){
            printf(" ");
        }
        
    }
    printf("\n");
}


int count_num_with_avg(int size, int a[]){
    printf("Массив:\n");
    print(a, size);
    int (*p)[5] = a;
    float avg = 0;
    for (int i = 0; i < size/5; i++){
        avg += p[i][i];
    }
    avg /=5.;
    int count = 0;
    for (int i = 0; i < size; i++){
        if (a[i] < avg){
            count++;
        }
    }
    return count;
}

// int main(void){
//     int m1[] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5};
//     int m2[] = {0,1,1,1,1,2,0,2,2,2,3,3,0,3,3,4,4,4,0,4,5,5,5,5,0};
    
//     printf("Результат: %d\n", count_num_with_avg(sizeof(m1)/sizeof(int),m1));
//     printf("Результат: %d\n", count_num_with_avg(sizeof(m2)/sizeof(int),m2));
//     return 0;
// }