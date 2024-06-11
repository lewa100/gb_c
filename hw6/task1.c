#include <stdio.h>
#include <string.h>

/*
Дано натуральное число N. Выведите все его цифры по одной, в прямом
порядке, разделяя их пробелами или новыми строками. Необходимо
реализовать рекурсивную функцию.
void print_num(int num)
Данные на входе: Одно целое неотрицательное число
Данные на выходе: Все цифры числа через пробел в прямом порядке.
Пример №1
Данные на входе: 15
Данные на выходе: 1 5
Пример №2
Данные на входе: 54321
Данные на выходе: 5 4 3 2 1
*/

void print_num(int num){
    if (num <= 0 ){
        return;
    }
    print_num(num/10); 
    printf("%d ", num%10);
}

int main(void){
    int s;
    printf("Ввод числа: ");
    scanf("%d", &s);
    
    print_num(s);
    return 0;
}