#include <stdlib.h>
#include "comps.h"
void replacement(void *a, void *b, size_t len){
    char *one = a,*two = b,temp;
    for (size_t i = 0; i < len; ++i) {
        temp = one[i];
        one[i] =  two[i];
        two[i] = temp;
    }
}

void defoultSorting(struct Abonent *arr, size_t len, int (*comp)(const void *, const void *)) {
    qsort(arr, len, sizeof(arr[0]), comp);
}

void gnomesort(struct Abonent *arr, size_t len, size_t sizeofEl,int (*comp)(const void *, const void *)) {
    size_t pos = 0;
    while (pos < len) {
        if (pos == 0 || comp(&arr[pos], &arr[pos - 1]) >= 0) {
            pos++;
        } else {
            replacement(&arr[pos], &arr[pos - 1], sizeofEl);
            pos--;
        }
    }
}
void selectionsort(struct Abonent *arr, size_t len, size_t sizeofEl, int (*comp)(const void *, const void *)) {
    size_t i, j, minIndex;
    for (i = 0; i < len - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < len; j++) {
            if (comp(&arr[j], &arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            replacement(&arr[i], &arr[minIndex], sizeofEl);
        }
    }
}


