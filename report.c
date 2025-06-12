#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studio.h"
#include "list.h"
#include "report.h"

void generaReport(List lista) {
    if (lista == NULL || isEmpty(lista)) {
        printf("La lista degli studi è vuota.\n");
        return;
    }

    printf("\n===== REPORT STUDI =====\n");

    printf("\n>> Studi completati:\n");
    stampaCompletate(lista);

    printf("\n>> Studi in corso:\n");
    stampaInCorso(lista);

    printf("\n>> Studi non iniziati:\n");
    stampaNonIniziate(lista);

    printf("========================\n");
}

void stampaCompletate(List lista) {
    int found = 0;
    for (int i = 0; i < sizeList(lista); i++) {
        Studio studio = getListItem(lista, i);
        if (studio->completata == 1) {
            outputStudio(studio);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Nessuno studio completato.\n");
    }
}

void stampaInCorso(List lista) {
    int found = 0;
    for (int i = 0; i < sizeList(lista); i++) {
        Studio studio = getListItem(lista, i);
        if (studio->completata == 0) {
            outputStudio(studio);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Nessuno studio in corso.\n");
    }
}

void stampaNonIniziate(List lista) {
    int found = 0;
    for (int i = 0; i < sizeList(lista); i++) {
        Studio studio = getListItem(lista, i);
        if (studio->completata == -1) {
            outputStudio(studio);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Nessuno studio non iniziato.\n");
    }
}
