#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы
пробел. Если количество символов нечетно (пробелы не считаем), то
последний символ не меняем. Результат записать в файл .txt.
Данные на входе: Строка из английских букв, пробелов и знаков
препинания. Не более 1000 символов.
Данные на выходе: Строка из английских букв, пробелов и знаков
препинания.
Пример №1
Данные на входе: Hello world!
Данные на выходе: eHllw orodl!
Пример №2
Данные на входе: abc def
Данные на выходе: bad cfe
*/

#define LEN 1000
#define NAME_IN "text.txt"
#define NAME_OUT "res.txt"

void swap(char a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}


void changePos(char *buf, int size){
    int i = 0, j = 0;
    while (i <= j && i<size && j < size){
       while (buf[j] == ' ' || j <= i) j++;
       while (buf[i] == ' ' || j <= i) i++;
        swap(buf, i,j);
        i=j+1;
        j++;
    } 
}

void writeFile(char *buf){
    FILE * f_out= fopen(NAME_OUT, "w");
    if(f_out)
    {
        fputs(buf, f_out);
        putc('\n', f_out);

        fclose(f_out);
        printf("File has been written\n");
    }
}

int main(void){
    char buffer[LEN];
    FILE *f_in = fopen(NAME_IN, "r");

    int i = 0;
    int buf_counter = 0; 
    while (!feof(f_in)){
        fscanf(f_in,"%c",&buffer[i]);
        buf_counter++;
        i++;
        char ch = buffer[i-1];
        if (ch == ('\n')) {
            break;
        }
    }
    fclose(f_in);
    printf("%s\n", buffer);
    changePos(buffer, buf_counter);

    printf("%s", buffer) ;  
    writeFile(buffer); 
   
    return 0;
}
