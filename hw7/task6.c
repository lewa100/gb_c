#include <stdio.h>
#include <string.h>

/*
Дан массив из 10 элементов. Определить, какое число в массиве встречается
чаще всего. Гарантируется, что такое число ровно 1.
Данные на входе: 10 целых числе через пробел
Данные на выходе: Одно число, которое встречается чаще других.
Пример
Данные на входе: 4 1 2 1 11 2 34 11 0 11
Данные на выходе: 11
*/


int main(void){
    int size = 10,m[size];
    printf("Ввод массива:   ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &m[i]);
    }
    
    while (0==0)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (m[i] > m[i+1] && i != size-1){
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

    int num = m[0], 
        cnt = 1,
        max = m[0],
        mCnt = 1;

    for (int i = 1; i < size; i++)
    {
        if (m[i] != num){
            if (num != max && cnt > mCnt){
                max = num;
                mCnt = cnt;
            }
            num = m[i];
            cnt = 1;
        }else{
            cnt++;   
        }
    }
    printf("Результат:\t %d\n", max);
    return 0;
}