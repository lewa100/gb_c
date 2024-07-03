#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "sensor.h"

void printMenu(){
    printf("\t====================================\n");
    printf("\t============|  MENU  |==============\n");
    printf("\t====================================\n");
    printf(" -h\t\t\tСписок ключей, которые обрабатывает\n\t\t\tданное приложение и их назначение\n");
    printf(" -f <filename.csv>\tВходной файл csv для обработки\n");
    printf(" -m <номер месяца>\tЕсли задан данный ключ,\bто выводится только статистику за указанный месяц\n");
}

unsigned int DateToInt(struct sensor* info){
    return info -> year << 16 | info -> month << 8 | info -> day;
}

int ReadFile(struct sensor* info,struct month_temp* m_temp, char * file_name){
    FILE* file = fopen(file_name, "r");
    char line[1024];
    int counter=0;
    if (file){
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, file)) {
            column = 0;
            row++;

            char* value = strtok(buffer, ";");
 
            while (value) {
                // Column 1
                if (column == 0) {
                    int num = atoi(value);
                    info[row].year = num;
                }
 
                // Column 2
                if (column == 1) {
                    int num = atoi(value);
                    info[row].month = num;
                }
 
                // Column 3
                if (column == 2) {
                    int num = atoi(value);
                    info[row].day = num;
                }
                
                // Column 4
                if (column == 3) {
                    int num = atoi(value);
                    info[row].hour = num;
                }

                // Column 5
                if (column == 4) {
                    int num = atoi(value);
                    info[row].minute = num;
                }

                // Column 6
                if (column == 5) {
                    int num = atoi(value);
                    info[row].t = num;
                }
                value = strtok(NULL, ";");
                column++;
            }
            
            addTempToMonth(m_temp,info[row].month, info[row].t);
        }

        fclose(file);
        counter = row;
    }else{
         printf("File not found: %s\n", file_name);
    }
    return counter;
}

void print(struct sensor* info,int number){
    printf("===================================\n");
    for(int i=0;i<number;i++)
    printf("%04d-%02d-%02d %02d:%02d t=%3d\n",
        info[i].year,
        info[i].month,
        info[i].day,
        info[i].hour,
        info[i].minute,
        info[i].t
    );
}

void AddRecord(struct sensor* info,int number,uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,int8_t t){
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].t = t;
}

void addTempToMonth(struct month_temp* m_temp,uint8_t m, int8_t t){
    m -= 1;
    if (m_temp[m].avg_t == 0 &&
    m_temp[m].min_t == 0 &&
    m_temp[m].max_t == 0){
        m_temp[m].avg_t = t;
        m_temp[m].min_t = t;
        m_temp[m].max_t = t;
    }else{
        m_temp[m].avg_t = (m_temp[m].avg_t+t)/2.;
        if (m_temp[m].min_t > t) m_temp[m].min_t = t;
        if (m_temp[m].max_t < t) m_temp[m].max_t = t;
    }
}

void printStatistic(struct month_temp* m_temp, int m){
    printf("-----======START STATISTIC======-----\n\n");
    float avg = m_temp[0].avg_t;
    int8_t min = m_temp[0].min_t; 
    int8_t max = m_temp[0].max_t; 
    for (int i = 0; i < MONTH_SIZE; i++){ 
        if (m_temp[i].avg_t == 0 &&
            m_temp[i].min_t == 0 &&
            m_temp[i].max_t == 0){
            continue;
        }
        avg = (avg + m_temp[m].avg_t)/2.;
        if (m_temp[i].min_t < min) min = m_temp[i].min_t;
        if (m_temp[i].max_t > max) max = m_temp[i].max_t;
        if (m > 12){
            printf("\n----- MONTH #%d -----\n",i+1);
            printf("|  AVG  | MIN | MAX |\n");
            printf("|-------------------|\n");
            printf("|%7.02f",m_temp[i].avg_t);
            printf("|%5d",m_temp[i].min_t);
            printf("|%5d|\n",m_temp[i].max_t);
            printf("|___________________|\n");
        }else if (m == i+1){
            printf("\n----- MONTH #%d -----\n",i+1);
            printf("|  AVG  | MIN | MAX |\n");
            printf("|-------------------|\n");
            printf("|%7.02f",m_temp[i].avg_t);
            printf("|%5d",m_temp[i].min_t);
            printf("|%5d|\n",m_temp[i].max_t);
            printf("|___________________|\n");
        }
    }

    printf("|------ YEAR -------|\n");
    printf("|  AVG  | MIN | MAX |\n");
    printf("|-------------------|\n");
    printf("|%7.02f",avg);
    printf("|%5d",min);
    printf("|%5d|\n",max);
    printf("|___________________|\n");
    printf("\n-----======END STATISTIC======-----\n");
}