#include "comps.h"
int comparelastCallTimeDown(const void *a, const void *b) {
    return ((struct Abonent*)a)->lastCallTime - ((struct Abonent*)b)->lastCallTime;
}
int comparelastCallTimeUp(const void *a, const void *b) {
    return ((struct Abonent*)b)->lastCallTime - ((struct Abonent*)a)->lastCallTime;
}
int comparephoneNumberDown(const void *a, const void *b) {
    return ((struct Abonent*)a)->phoneNumber - ((struct Abonent*)b)->phoneNumber;
}
int comparephoneNumberUp(const void *a, const void *b) {
    return ((struct Abonent*)b)->phoneNumber - ((struct Abonent*)a)->phoneNumber;
}
int compareFIODown(const void *a, const void *b) {
    return ((struct Abonent*)a)->FIO - ((struct Abonent*)b)->FIO;
}
int compareFIOUP(const void *a, const void *b) {
    return ((struct Abonent*)b)->FIO - ((struct Abonent*)a)->FIO;
}
