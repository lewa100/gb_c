#include <stdio.h>
#include <string.h>

void center(char *s, int width)
{
         printf("%*s%*s\n",width+strlen(s)/2,s,width-strlen(s)/2,"");
}

int main(void) {
    center("*",4);
    center("***",4);
    center("*****",4);
    center("*******",4);
    center("HH HH",4);
    center("ZZZZZ",4);

    return 0;
}