#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл
.txt.
Данные на входе: Строка состоящая из символов: a-z, A-Z, 0-9, /
Данные на выходе: Исходная строка с измененным расширением.
Пример №1
Данные на входе: /DOC.TXT/qqq
Данные на выходе: /DOC.TXT/qqq.html
Пример №2
Данные на входе: /DOC.TXT/qqq.com
Данные на выходе: /DOC.TXT/qqq.html
*/

#define LEN 1000
#define NAME_IN "text.txt"
#define NAME_OUT "res.txt"
#define TK ".html"

void joinString (char str1[],int size_st1, char str2[], int size_st2, char *tmp){
    int i = 0;
    while (i < size_st1){
        tmp[i] = str1[i];
        i++;
    }
    
    int j = 0;
    while (j < size_st2){
        tmp[i] = str2[j];
        j++;
        i++;
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

void addHTML(char *buf, int size){
    int i = size-1;
    // memset(tmp,0,size);
    int tk_pos = 0;
    int sp_pos = 0;
    while (buf[i] != '/'){
        if (buf[i] == '.'){
            tk_pos = i;
        }else if (buf[i] == ' '){
            sp_pos = i;
        }
        
        i--;
    } 
    if (tk_pos == 0){
        if (sp_pos == 0){
            char tmp[size+sizeof(TK)];
            joinString(buf,size,TK,sizeof(TK), tmp);
            writeFile(tmp); 
        }else{
            char tmp[sp_pos+sizeof(TK)];
            joinString(buf,sp_pos,TK,sizeof(TK), tmp);
            writeFile(tmp); 
        }   
    }else{
        char tmp[tk_pos+sizeof(TK)];
        joinString(buf,tk_pos,TK,sizeof(TK), tmp);
        writeFile(tmp); 
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
    }
    fclose(f_in);
    addHTML(buffer, i-1);
   
    return 0;
}
