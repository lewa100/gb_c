#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
В файле .txt дана символьная строка не более 1000 символов. Необходимо
заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
строчные. Результат записать в .txt.
Данные на входе: Строка из маленьких и больших английских букв,
знаков препинания и пробелов.
Данные на выходе: Строка из маленьких и больших английских
букв, знаков препинания и пробелов.
Пример
Данные на входе: aabbccddABCD
Данные на выходе: bbaaccddBACD
*/

#define LEN 1000
#define NAME_IN "text.txt"
#define NAME_OUT "res.txt"


void writeFile(char *buff){
    printf("size:%s",buff);
    FILE * f_out= fopen(NAME_OUT, "w");
    if(f_out)
    {
        fputs(buff, f_out);
        
        printf("\n");
        putc('\n', f_out);

         
        fclose(f_out);
        printf("File has been written\n");
    }
}

int main(void){
    char buffer[LEN];
    FILE *f_in = fopen(NAME_IN, "r");

    int i = 0;
    while (!feof(f_in)){
        fscanf(f_in,"%c",&buffer[i]);
        i++;
        char ch = buffer[i-1];
        if (ch == ('\n')) {
            break;
        }
        switch (ch){
            case 'a': buffer[i-1] = 'b'; break;
            case 'A': buffer[i-1] = 'B'; break;

            case 'b':buffer[i-1] = 'a'; break;
            case 'B':buffer[i-1] = 'A'; break;
            
            default:
                break;
        }
    }
    fclose(f_in);
   
     writeFile(buffer);
    return 0;
}
