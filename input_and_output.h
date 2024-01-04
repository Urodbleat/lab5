#ifndef LAB5_2_INPUT_AND_OUTPUT_H
#define LAB5_2_INPUT_AND_OUTPUT_H
#define MAX_ABONENTS 1000
void printAbonents(struct Abonent *arr, size_t len);
void saveAbonentsToFile(struct Abonent *arr, size_t len, const char *filename);
void addAbonentFromKeyboard(struct Abonent *arr, size_t *len);
void addAbonentFromTextFile(struct Abonent *arr, size_t *len, const char *filename);
void addAbonentFromBinaryFile(struct Abonent *arr, size_t *len, const char *filename);

#endif //LAB5_2_INPUT_AND_OUTPUT_H
