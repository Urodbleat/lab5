#ifndef LAB5_2_SORTINGS_H
#define LAB5_2_SORTINGS_H
#include <stdlib.h>
void defoultSorting(struct Abonent *arr, size_t len, int (*comp)(const void *, const void *));
void gnomesort(struct Abonent *arr, size_t len, size_t sizeofEl,int (*comp)(const void *, const void *));
void selectionsort(struct Abonent *arr, size_t len, size_t sizeofEl, int (*comp)(const void *, const void *));

#endif //LAB5_2_SORTINGS_H
