#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sensor.h"

#define SIZE 30
#define MONTH_SIZE 12

int main(int argc, char *argv[]){
    int rez=0;
    char * fname;
    int m = 0;
    int is_file = 0;
    int is_month = 0;
    struct sensor info[SIZE];
    struct month_temp m_temp[MONTH_SIZE];
    memset(&info, 0, sizeof(info));
    memset(&m_temp, 0, sizeof(m_temp));
    while ( (rez = getopt(argc,argv,"h:f:m:")) != -1){
        switch (rez){
            case 'f':fname = optarg;is_file = 1;break;
            case 'm':m = atoi(optarg), is_month = 1;break;
            case 'h': printMenu();break;
            case '?':printf("unknown option: %c\n", optopt);break;
        };   
    };
    if (is_file){
        if (!is_month){
            printf("only file: \"f\" ==%s\n", fname);
            ReadFile(info,m_temp, fname);
            printStatistic(m_temp, 99);
        }else{
            printf("file: \"f\" = %s \"m\" = %d\n", fname,m);
            ReadFile(info,m_temp, fname);
            printStatistic(m_temp, m);
        }
    }
};

