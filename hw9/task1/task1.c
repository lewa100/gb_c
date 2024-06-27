#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
В файле .txt даны два слова не более 100 символов каждое, разделенные
одним пробелом. Найдите только те символы слов, которые встречаются в
обоих словах только один раз. Напечатайте их через пробел в файл .txt в
лексикографическом порядке.
Данные на входе: Два слова из маленьких английских букв через
пробел. Длинна каждого слова не больше 100 символов.
Данные на выходе: Маленькие английские буквы через пробел.
Пример №1
Данные на входе: hello world
Данные на выходе: o
Данные на входе: aabcd bcef
Данные на выходе: b c
*/

#define LEN 201
#define NAME_IN "2word.txt"
#define NAME_OUT "res.txt"

/////SORT
void print(char *m, int size){
    for (int i = 0; i < size; i++){
        printf("%c", m[i]);
        if (i < size-1){
            printf(" ");
        }
        
    }
    printf("\n");
}

void swap(char a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void quickSort(char *m, int l, int r){
    if (l>r) return;
    int p = m[(l+r)/2];
    int i = l,
        j = r;
    while (i <= j){
       while (m[i] < p) i++;
        while (m[j] > p) j--;
        if (i <= j) {
            swap(m,i,j);
            i++;
            j--;
        }
    }
    quickSort(m,l,j);
    quickSort(m,i,r);
}

void sort_array(char a[],int size){
    quickSort(a,0, size-1);
}
///////////////////////////

void writeFile(char *buff,int size){
    FILE * f_out= fopen(NAME_OUT, "w");
    if(f_out)
    {
        int i =0;
        while (buff[i] >='a')
        {
            printf("%c",buff[i]);
            putc(buff[i], f_out);
            if (i < size-1){
                printf(" ");
                putc(' ', f_out);
            }
            i++;
        }
        
        printf("\n");
        putc('\n', f_out);

         
        fclose(f_out);
        printf("File has been written\n");
    }
}

void saveRes(char *word1,int count_w1, char *word2, int count_w2){
    sort_array(word1,sizeof(word1)/sizeof(char));
    // print(word1,sizeof(word1)/sizeof(char));
    sort_array(word2,sizeof(word2)/sizeof(char));
    // print(word2,sizeof(word2)/sizeof(char));
    
    char *eq = malloc(100 * sizeof(char));
    int step = 0;
    char buff_w1 = 0;
    char buff_w2 = 0;

    for (int i = 0; i < count_w1; i++){
        if (word1[i] != word1[i+1]){
            for (int j = 0; j < count_w2; j++){
                if (word1[i] == 0 || word2[j] == 0 ||
                word1[i] == buff_w1 ||  word2[j] == buff_w2){
                    continue;
                }
                if (word2[j] != word2[j+1]){    
                    if (word1[i] == word2[j]){
                        eq[step] = word1[i];
                        step++;
                    }
                }else {
                    buff_w2 = word2[j];
                }
                
            }
        }else{
            buff_w1 = word1[i];
        }
    }
    writeFile(eq,sizeof(eq)/sizeof(char));
    free(eq);
}

int main(void){
    char buffer[LEN];
    FILE *f_in = fopen(NAME_IN, "r");

    char *word1 = malloc(100 * sizeof(char));
    char *word2 = malloc(100 * sizeof(char));

    int i = 0;
    int j = 0;
    int new_word = 0;
    while (!feof(f_in)){
        fscanf(f_in,"%c",&buffer[i]);
        i++;
        char ch = buffer[i-1];
        if (new_word){
            word2[j] = ch;
            j++;
            continue;
        }else if (ch == (' ')){
            new_word = 1;
            continue;
        } else if (ch == ('\n')) {
            break;
        }else{
            word1[i-1] = ch;
        }   
    }
    fclose(f_in);
    
    saveRes(word1,sizeof(word1)/sizeof(char),word2,sizeof(word2)/sizeof(char));
    free(word1);
    free(word2);

    // printf("%s\n1 - %s\n2 - %s\n", buffer, word1, word2);
   
    return 0;
}
