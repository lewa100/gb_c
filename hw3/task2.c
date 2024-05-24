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
    int min = m[0];
    for (int i = 1; i < s; i++)
    {
        if (m[i] < min) {
            min = m[i];
        }
    }
    
    printf("Min = %d\n", min); 
    return 0;
}