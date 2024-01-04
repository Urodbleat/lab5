#ifndef LAB5_2_COMPS_H
#define LAB5_2_COMPS_H
#include <stdlib.h>
#include <time.h>

int comparelastCallTimeDown(const void *a, const void *b);
int comparelastCallTimeUp(const void *a, const void *b);
int comparephoneNumberDown(const void *a, const void *b);
int comparephoneNumberUp(const void *a, const void *b);
int compareFIODown(const void *a, const void *b);
int compareFIOUP(const void *a, const void *b);


struct Abonent {
    char* FIO;
    char phoneNumber[16];
    time_t lastCallTime;
};

#endif
