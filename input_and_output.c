#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "comps.h"

#define MAX_ABONENTS 100000
void printAbonents(struct Abonent *arr, size_t len) {
    printf("\nСписок абонентов:\n");
    for (size_t i = 0; i < len; ++i) {
        printf("%lu. ФИО: %s, Телефон: %s, Время последнего звонка: %ld\n",
               i + 1, arr[i].FIO, arr[i].phoneNumber, arr[i].lastCallTime);
    }
}

void saveAbonentsToFile(struct Abonent *arr, size_t len, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return;
    }

    for (size_t i = 0; i < len; ++i) {
        fprintf(file, "%s %s %ld\n", arr[i].FIO, arr[i].phoneNumber, arr[i].lastCallTime);
    }

    fclose(file);
}

void addAbonentFromKeyboard(struct Abonent *arr, size_t *len) {
    if (*len >= MAX_ABONENTS) {
        printf("Ошибка: превышен лимит абонентов.\n");
        return;
    }

    arr[*len].FIO = NULL;

    printf("Введите ФИО абонента: ");
    char buffer[256];
    size_t totalLen = 0;
    do {
        fgets(buffer, sizeof(buffer), stdin);
        size_t curLen = strlen(buffer);
        char *temp = realloc(arr[*len].FIO, totalLen + curLen + 1);
        if (temp == NULL) {
            perror("Ошибка при выделении памяти");
            free(arr[*len].FIO);
            return;
        }
        arr[*len].FIO = temp;
        strcpy(arr[*len].FIO + totalLen, buffer);
        totalLen += curLen;
    } while (totalLen == 1 || arr[*len].FIO[totalLen - 2] == '\n');
    arr[*len].FIO[totalLen - 1] = '\0';

    printf("Введите номер телефона абонента: ");
    fgets(arr[*len].phoneNumber, sizeof(arr[*len].phoneNumber), stdin);
    arr[*len].phoneNumber[strcspn(arr[*len].phoneNumber, "\n")] = '\0';

    printf("Введите время последнего звонка абонента (в формате UNIX time): ");
    scanf("%ld", &arr[*len].lastCallTime);

    (*len)++;
}
void addAbonentFromTextFile(struct Abonent *arr, size_t *len, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return;
    }

    while ((*len < MAX_ABONENTS) &&
           (fscanf(file, "%ms %15s %ld", &arr[*len].FIO, arr[*len].phoneNumber, &arr[*len].lastCallTime) == 3)) {
        printf("Прочитан абонент: %s %s %ld\n", arr[*len].FIO, arr[*len].phoneNumber, arr[*len].lastCallTime);
        (*len)++;
    }

    fclose(file);
}



void addAbonentFromBinaryFile(struct Abonent *arr, size_t *len, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return;
    }

    while ((*len < MAX_ABONENTS) &&
           (fread(&arr[*len], sizeof(struct Abonent), 1, file) == 1)) {
        (*len)++;
    }

    fclose(file);
}