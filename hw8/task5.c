#include <stdio.h>
#include <string.h>

/*
Составить функцию, которая меняет в массиве минимальный и максимальный
элемент местами. Прототип функции
void change_max_min(int size, int a[])
Данные на входе: Функция принимает на вход размер массива и
массив чисел типа int
Данные на выходе: Функция не возвращает значения, измененный
массив сохраняется на месте исходного.
Пример
Данные на входе: 1 2 3 4 5 6 7 8 9 10
Данные на выходе: 10 2 3 4 5 6 7 8 9 1
*/

void swap(int a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void print(int *m, int size){
    for (int i = 0; i < size; i++){
        printf("%d", m[i]);
        if (i < size-1){
            printf(" ");
        }
        
    }
    printf("\n");
}


void change_max_min(int size, int a[]){
    printf("Массив:\n");
    print(a, size);
    int min = a[0], i_min = 0,
        max = a[0], i_max = 0;
    for (int i = 0; i < size; i++){
        if(a[i] > max) {
            max = a[i];
            i_max = i;
        }
        if(a[i] < min) {
            min = a[i];
            i_min = i;
            
        }
    }
    if (i_max != i_min){
        swap(a, i_max, i_min);
    }
    
    print(a, size);
}

// int main(void){
//     int m1[] = {1,2,3,4,5,6,7,8,9,10};
//     int m2[] = {1,2,1,4,5};
    
//     change_max_min(sizeof(m1)/sizeof(int),m1);
//     change_max_min(sizeof(m2)/sizeof(int),m2);
//     return 0;
// }