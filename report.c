#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "studio.h"
#include "list.h"
#include "report.h"

void generaReport(List lista) 
{
    if (lista == NULL || isEmpty(lista)) {
        printf("La lista degli studi è vuota.\n");
        return;
    }

    printf("\n===== REPORT STUDI =====\n");

    printf("Numero totale di studi: %d\n\n", sizeList(lista));
    printList(lista);

    printf("========================\n");
}

void aggiornaCompletamentoDaNome(List lista, char *nomeStudio, int nuovoStato) 
{
    int trovato=0;

    for (int i = 0; i < sizeList(lista); i++) 
    {
        Studio studio = getListItem(lista, i);
        if((trovato = aggiornaCompletamento(studio, nuovoStato, nomeStudio)) >=-1 && trovato <=1)
        {
            break;
        };   
    }
}

