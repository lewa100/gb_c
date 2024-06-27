#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt.
Данные на входе: Строка из английских букв, знаков препинания и
пробелов. Не более 1000 символов.
Данные на выходе: Строка из английских букв, знаков препинания и
пробелов.
Пример
Данные на входе: Hello world!
Данные на выходе: Hello world!
*/

#define LEN 1000
#define NAME_IN "text.txt"
#define NAME_OUT "res.txt"

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

void clearSpace(char *buf, int size){
    int start = 1;
    int find = 0;
    int i = 0;
    char *tmp = malloc(size * sizeof(char));
    memset(tmp,0,size);
    int i_tmp = 0;
    while (i < size){
        if ((buf[i] == ' ' || buf[i] == 0) && start){
            i++;
            continue;
        }else{
            if (start){
                start = 0;
            }   
        }
        if (buf[i] == ' ' || buf[i] == 0){
            if (!find){
                find = 1;
            }else{
               i++;
               continue; 
            }
        }else{
            find = 0;
        }

        tmp[i_tmp] = buf[i];
        i_tmp++;
        i++;
    } 
    writeFile(tmp); 
    free(tmp);
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
    clearSpace(buffer, buf_counter);
   
    return 0;
}
