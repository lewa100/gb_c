#include <stdio.h>
#include <string.h>

/*
Написать только одну функцию, которая ставит в начало массива все четные
элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел
между собой. Строго согласно прототипу:
void sort_even_odd(int n, int a[])
Данные на входе: Функция принимает на вход целые числа
Данные на выходе: Отсортированный исходный массив
Пример №1
Данные на входе: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Данные на выходе: 20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3
1
Пример №2
Данные на входе: 1 0 1 0 1
Данные на выходе: 0 0 1 1 1
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

void swap(int a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void sortOdd(int *m, int size){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (m[i] % 2 == 0){
            count++;
        }
    }
    int lm[count],
        rm[size-count],
        l = 0,
        r = 0;

    for (int i = 0; i < size; i++){
        if (m[i] % 2 == 0){
            lm[l] = m[i];
            l++;
        }else{
            rm[r] = m[i];
            r++;
        }
    }
    r = 0;
    for (int i = 0; i < size; i++)
    {
        if (i < count){
            m[i] = lm[i];
        }else{
            m[i] = rm[r];
            r++;
        }
    } 
}

void sort_even_odd(int n, int a[]){
    printf("Массив:\n");
    print(a, n);
    sortOdd(a,n);
    print(a, n);
}

// int main(void){
//     int m1[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
//     int m2[5] = {1,0,1,0,1};
//     sort_even_odd(sizeof(m1)/sizeof(int),m1);
//     sort_even_odd(sizeof(m2)/sizeof(int),m2);

//     return 0;
// }