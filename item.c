#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studio.h"
#include "item.h"
#define NCHAR 100

Item inputItem() {
    char *input = malloc(NCHAR * sizeof(char));
    if (input == NULL) {
        fprintf(stderr, "Errore di allocazione memoria\n");
        exit(EXIT_FAILURE);
    }
    scanf("%99s", input); // Limita la lunghezza dell'input
    return input;
}

void outputItem(Item item) {
    printf("%s", (char*)item);
}

int cmpItem(Item itemA, Item itemB) {
    return strcmp((char*)itemA, (char*)itemB);
}

void freeItem(Item item) {
    free(item);
}