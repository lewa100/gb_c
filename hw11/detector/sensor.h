#include <stdint.h>
#define MONTH_SIZE 12

struct sensor {
    uint16_t year;
    uint8_t day;
    uint8_t month;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
};

struct month_temp {
    int8_t min_t;
    int8_t max_t;
    float avg_t;
};

char *tmp; 

void print(struct sensor* info,int number);
int ReadFile(struct sensor* info,struct month_temp* m_temp, char * file_name);
void printMenu();
void addTempToMonth(struct month_temp* m_temp,uint8_t month, int8_t t);
void printStatistic(struct month_temp* m_temp, int m);