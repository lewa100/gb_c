#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
В файле .txt строка из маленьких и больших английских букв, знаков
препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
все пробелы. Результат записать в файл .txt.
Данные на входе: Строка из маленьких и больших английских букв,
знаков препинания и пробелов. Размер строки не более 1000 символов.
Данные на выходе: Строка из маленьких и больших английских
букв.
Пример
Данные на входе: abc cde def
Данные на выходе: abcdef
*/

#define LEN 1000
#define TMP_LEN 100
#define NAME_IN "text.txt"
#define NAME_OUT "res.txt"

void writeFile(char *buff){
    FILE * f_out= fopen(NAME_OUT, "w");
    if(f_out)
    {
        fputs(buff, f_out);
        putc('\n', f_out);

        fclose(f_out);
        printf("File has been written\n");
    }
}

int main(void){
    char buffer[LEN];
    FILE *f_in = fopen(NAME_IN, "r");

    char *tmp = malloc(TMP_LEN * sizeof(char));
    int i_tmp = 0;
    int i = 0;
    while (!feof(f_in)){
        fscanf(f_in,"%c",&buffer[i]);
        char ch = buffer[i];
        if (ch == ('\n')) {
            break;
        }else if (ch == 0 || ch == ' ')
        {
            continue;
        }
        
        if (i_tmp > 0){
            int find = 0;
            for (int i = 0; i < i_tmp; i++){
                if (tmp[i] == ch){
                    find = 1;
                    break;
                } 
            }
            if (!find){
                tmp[i_tmp] = ch;
                i_tmp++;
            }
        }else{
            tmp[i_tmp] = ch;
            i_tmp++;
        }
        i++;
    }
    fclose(f_in);
    printf("%s\n%s\n",buffer, tmp);
    writeFile(tmp);
    free(tmp);   
    return 0;
}
