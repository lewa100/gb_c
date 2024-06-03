#include <stdio.h>

/*
Составить функцию, которая определяет наибольший общий делитель двух
натуральных и привести пример ее использования
https://younglinux.info/algorithm/euclidean
int nod(int a, int b)
Данные на входе: Два целых положительных числа
Данные на выходе: Одно целое число - наибольший общий делитель.
Пример №1
Данные на входе: 14 21
Данные на выходе: 7
*/

int nod(int a, int b){
    int min, res = 0;
    if (a > b){
        min = b;
    }else{
        min = a;
    }
    do
    {
        if (a%min==0 && b%min==0){
            res = min;
            break;
        }
        min--;
    } while (min > 0);
      
    return res;
}

int main(void){
    int a,b;
    printf("Ввод 1 числа: ");
    scanf("%d", &a);
    printf("Ввод 2 числа: ");
    scanf("%d", &b);
    
    printf("Результат: %d\n", nod(a,b)); 
    return 0;
}