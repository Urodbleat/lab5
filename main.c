#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include "comps.h"
#include "input_and_output.h"
#include "sortings.h"

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define RESET_TEXT "\033[0m"

char* generate(size_t length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char* result = malloc((length + 1) * sizeof(char));

    for (size_t i = 0; i < length; i++) {
        size_t index = rand() % (sizeof(charset) - 1);
        result[i] = charset[index];
    }

    result[length] = '\0';
    return result;
}

void Random(struct Abonent* abonent,int len) {
    abonent->FIO = generate(len);
    snprintf(abonent->phoneNumber, sizeof(abonent->phoneNumber), "%010d", rand() % 1000000000);
    abonent->lastCallTime = rand();
}


int main() {
    int timelen,maxabonents, fakeend = 0;
    clock_t start,end;
    struct Abonent arr[MAX_ABONENTS];
    size_t len = 0;

    int choice;

    do {
        printf("\nМеню:\n");
        printf("1. Ввести нового абонента\n");
        printf("2. Загрузить абонентов из файла\n");
        printf("3. Сортировать абонентов\n");
        printf("4. Вывести список абонентов\n");
        printf("5. Сохранить абонентов в файл\n");
        printf("6. Таймирование сортировки\n");
        printf("0. Выход\n");

        printf("Выберите действие (введите соответствующую цифру): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAbonentFromKeyboard(arr, &len);
                break;
            case 2:
                addAbonentFromTextFile(arr, &len, "abonents.txt");
                break;
            case 3: {
                int sortAlphaChoice;
                int sortElements;
                int sortChoice;

                printf("Выберите сортировку\n");
                printf("1. Qsort\n");
                printf("2. Gnomesort\n");
                printf("3. Selectionsort\n");
                printf("Ввод: ");

                if (scanf("%d", &sortAlphaChoice) != 1) {
                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                    break;
                }

                switch (sortAlphaChoice) {
                    case 1:
                        printf("Выберите Поле для сортировки:\n");
                        printf("1. ФИО\n");
                        printf("2. Номер\n");
                        printf("3. Время звонка\n");
                        printf("Ввод: ");

                        if (scanf("%d", &sortElements) != 1) {
                            printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                            break;
                        }

                        switch (sortElements) {
                            case 1:
                                printf("\nВыберите Направление сортировки:");
                                printf("\n1. По убыванию");
                                printf("\n2. По возрастанию");
                                printf("\nВвод: ");

                                if (scanf("%d", &sortChoice) != 1) {
                                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                                    break;
                                }

                                if (sortChoice == 1) {
                                    defoultSorting(arr, len, compareFIOUP);
                                } else if (sortChoice == 2) {
                                    defoultSorting(arr, len, compareFIODown);
                                } else {
                                    printf("Неверный выбор направления сортировки.\n");
                                }
                                break;

                            case 2:
                                printf("\nВыберите Направление сортировки:");
                                printf("\n1. По убыванию");
                                printf("\n2. По возрастанию");
                                printf("\nВвод: ");

                                if (scanf("%d", &sortChoice) != 1) {
                                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                                    break;
                                }

                                if (sortChoice == 1) {
                                    defoultSorting(arr, len, comparephoneNumberUp);
                                } else if (sortChoice == 2) {
                                    defoultSorting(arr, len, comparephoneNumberDown);
                                } else {
                                    printf("Неверный выбор направления сортировки.\n");
                                }
                                break;

                            case 3:
                                printf("\nВыберите Направление сортировки:");
                                printf("\n1. По убыванию");
                                printf("\n2. По возрастанию");
                                printf("\nВвод: ");

                                if (scanf("%d", &sortChoice) != 1) {
                                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                                    break;
                                }

                                if (sortChoice == 1) {
                                    defoultSorting(arr, len, comparelastCallTimeUp);
                                } else if (sortChoice == 2) {
                                    defoultSorting(arr, len, comparelastCallTimeDown);
                                } else {
                                    printf("Неверный выбор направления сортировки.\n");
                                }
                                break;

                            default:
                                printf("Неверный выбор элемента для сортировки.\n");
                        }
                        break;

                    case 2:
                        printf("Выберите Поле для сортировки:\n");
                        printf("1. ФИО\n");
                        printf("2. Номер\n");
                        printf("3. Время звонка\n");
                        printf("Ввод: ");

                        if (scanf("%d", &sortElements) != 1) {
                            printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                            break;
                        }

                        switch (sortElements) {
                            case 1:
                                printf("\nВыберите Направление сортировки:");
                                printf("\n1. По убыванию");
                                printf("\n2. По возрастанию");
                                printf("\nВвод: ");

                                if (scanf("%d", &sortChoice) != 1) {
                                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                                    break;
                                }

                                if (sortChoice == 1) {
                                    gnomesort(arr, len, sizeof(struct Abonent), compareFIOUP);
                                } else if (sortChoice == 2) {
                                    gnomesort(arr, len, sizeof(struct Abonent), compareFIODown);
                                } else {
                                    printf("Неверный выбор направления сортировки.\n");
                                }
                                break;

                            case 2:
                                printf("\nВыберите Направление сортировки:");
                                printf("\n1. По убыванию");
                                printf("\n2. По возрастанию");
                                printf("\nВвод: ");

                                if (scanf("%d", &sortChoice) != 1) {
                                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                                    break;
                                }

                                if (sortChoice == 1) {
                                    gnomesort(arr, len, sizeof(struct Abonent), comparephoneNumberUp);
                                } else if (sortChoice == 2) {
                                    gnomesort(arr, len, sizeof(struct Abonent), comparephoneNumberDown);
                                } else {
                                    printf("Неверный выбор направления сортировки.\n");
                                }
                                break;

                            case 3:
                                printf("\nВыберите Направление сортировки:");
                                printf("\n1. По убыванию");
                                printf("\n2. По возрастанию");
                                printf("\nВвод: ");

                                if (scanf("%d", &sortChoice) != 1) {
                                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                                    break;
                                }

                                if (sortChoice == 1) {
                                    gnomesort(arr, len, sizeof(struct Abonent), comparelastCallTimeUp);
                                } else if (sortChoice == 2) {
                                    gnomesort(arr, len, sizeof(struct Abonent), comparelastCallTimeDown);
                                } else {
                                    printf("Неверный выбор направления сортировки.\n");
                                }
                                break;

                            default:
                                printf("Неверный выбор элемента для сортировки.\n");
                        }
                        break;

                    case 3:
                        printf("Выберите Поле для сортировки:\n");
                        printf("1. ФИО\n");
                        printf("2. Номер\n");
                        printf("3. Время звонка\n");
                        printf("Ввод: ");

                        if (scanf("%d", &sortElements) != 1) {
                            printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                            break;
                        }

                        switch (sortElements) {
                            case 1:
                                printf("\nВыберите Направление сортировки:");
                                printf("\n1. По убыванию");
                                printf("\n2. По возрастанию");
                                printf("\nВвод: ");

                                if (scanf("%d", &sortChoice) != 1) {
                                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                                    break;
                                }

                                if (sortChoice == 1) {
                                    selectionsort(arr, len, sizeof(struct Abonent), compareFIOUP);
                                } else if (sortChoice == 2) {
                                    selectionsort(arr, len, sizeof(struct Abonent), compareFIODown);
                                } else {
                                    printf("Неверный выбор направления сортировки.\n");
                                }
                                break;

                            case 2:
                                printf("\nВыберите Направление сортировки:");
                                printf("\n1. По убыванию");
                                printf("\n2. По возрастанию");
                                printf("\nВвод: ");

                                if (scanf("%d", &sortChoice) != 1) {
                                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                                    break;
                                }

                                if (sortChoice == 1) {
                                    selectionsort(arr, len, sizeof(struct Abonent), comparephoneNumberUp);
                                } else if (sortChoice == 2) {
                                    selectionsort(arr, len, sizeof(struct Abonent), comparephoneNumberDown);
                                } else {
                                    printf("Неверный выбор направления сортировки.\n");
                                }
                                break;

                            case 3:
                                printf("\nВыберите Направление сортировки:");
                                printf("\n1. По убыванию");
                                printf("\n2. По возрастанию");
                                printf("\nВвод: ");

                                if (scanf("%d", &sortChoice) != 1) {
                                    printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                                    break;
                                }

                                if (sortChoice == 1) {
                                    selectionsort(arr, len, sizeof(struct Abonent), comparelastCallTimeUp);
                                } else if (sortChoice == 2) {
                                    selectionsort(arr, len, sizeof(struct Abonent), comparelastCallTimeDown);
                                } else {
                                    printf("Неверный выбор направления сортировки.\n");
                                }
                                break;

                            default:
                                printf("Неверный выбор элемента для сортировки.\n");
                        }
                        break;

                    default:
                        printf("Неверный выбор метода сортировки.\n");
                }
                break;
            }

            case 4: {
                int printChoice;
                printf("Выберите формат вывода:\n");
                printf("1. На экран\n");
                printf("2. В файл текстовый\n");
                printf("3. В файл бинарный\n");
                scanf("%d", &printChoice);

                if (printChoice == 1) {
                    printAbonents(arr, len);
                } else if (printChoice == 2) {
                    saveAbonentsToFile(arr, len, "abonents_output.txt");
                } else if (printChoice == 3) {
                    FILE *file = fopen("abonents_output.bin", "wb");
                    if (file == NULL) {
                        perror("Ошибка при открытии файла");
                        break;
                    }

                    fwrite(arr, sizeof(struct Abonent), len, file);
                    fclose(file);
                } else {
                    printf("Неверный выбор формата вывода.\n");
                }

                break;
            }
            case 5:
                saveAbonentsToFile(arr, len, "abonents.txt");
                break;
            case 6:
                printf("Выберите длину строки ФИО(максимум 5000000):");
                scanf("%d",&timelen);
                if(timelen > 500000000){
                    printf("Лимит превышен");
                    break;
                }
                printf("Выберите число абонентов(максимум 100)");
                scanf("%d",&maxabonents);
                if(maxabonents > 1000000000){
                    printf("Лимит превышен");
                    break;
                }
                start = clock();
                for (size_t i = 0; i < maxabonents; i++) {
                    fakeend += 1;
                    if(fakeend > 1000){
                        printf(RED_TEXT "Опасность расплавления реактора!!!аварийная преостановка тестирования!!!\n" RESET_TEXT);
                        break;
                    }
                    Random(&arr[i],timelen);
                }
                fakeend = 0;
                end = clock();
                double time = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf(GREEN_TEXT"Таймирование сортировки завершено. Время заполнения: %f сек.\n" RESET_TEXT, time);
                break;
            case 0:
                printf("Программа завершена.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
