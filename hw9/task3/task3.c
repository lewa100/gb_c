#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
числа и иные символы. Требуется все числа, которые встречаются в строке,
поместить в отдельный целочисленный массив. Например, если дана строка
"data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
массив по возрастанию в файл .txt.
Данные на входе: Строка из английских букв, цифр и знаков
препинания
Данные на выходе: Последовательность целых чисел
отсортированная по возрастанию
Пример
Данные на входе: data 48 call 9 read13 blank0a
Данные на выходе: 0 9 13 48
*/

#define LEN 1000
#define TMP_LEN 10
#define NAME_IN "text.txt"
#define NAME_OUT "res.txt"

///SORT
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

void quickSort(int *m, int l, int r){
    if (l >r) return;
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

void sort_array(int size, int a[]){
    quickSort(a,0, size-1);
}

//////

void writeFile(int *buff,int size){
    FILE * f_out= fopen(NAME_OUT, "w");
    if(f_out)
    {
        for (int i = 0; i < size; i++)
        {

            printf("%d",buff[i]);
            fprintf(f_out,"%d",buff[i]);
            if (i < size-1){
                printf(" ");
                putc(' ', f_out);
            }
        }
        
        printf("\n");
        putc('\n', f_out);

         
        fclose(f_out);
        printf("File has been written\n");
    }
}

int main(void){
    char buffer[LEN];
    FILE *f_in = fopen(NAME_IN, "r");

    char *tmp = malloc(10 * sizeof(char));
    int nums[100];
    int i_nums = 0;
    int num_counter = 0;
    int i = 0, pos = 0;
    int num = 0;

    while (!feof(f_in)){
        fscanf(f_in,"%c",&buffer[i]);
        char ch = buffer[i];
        if (ch == ('\n')) {
            break;
        }
        if (ch >= '0' && ch <= '9'){
            if (!num){
                num = 1;
            }  
            tmp[pos] = ch;
            pos++;
        }else if (num){
            long result = strtol(tmp, NULL, 10);
            nums[i_nums] = result;
            i_nums++;
            num_counter++;
            memset(tmp,0,TMP_LEN);
            num = 0;
            pos = 0;
        }
        i++;
    }
    fclose(f_in);
    free(tmp);

    int res[num_counter];

    for (int i = 0; i < num_counter; i++)
    {
        res[i] = nums[i];
    }
    sort_array(num_counter, res);
 
    writeFile(res,num_counter);
    
    return 0;
}
