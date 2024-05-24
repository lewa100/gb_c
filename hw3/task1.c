#include <stdio.h>

int main(void){
    int s;
    printf("Размер массива: ");
    scanf("%d", &s);
    int m[s];
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &m[i]);
    }
    int max = m[0];
    for (int i = 1; i < s; i++)
    {
        if (m[i] > max) {
            max = m[i];
        }
    }
    
    printf("Max = %d\n", max); 
    return 0;
}