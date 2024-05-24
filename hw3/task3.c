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
    
    int last = m[0];
    for (int i = 1; i < s; i++)
    {
        if (m[i] < last){
            printf("NO\n");
            return 0;
        }
        last = m[i];
    }
    
    printf("YES\n"); 
    return 0;
}