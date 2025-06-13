#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "studio.h"
#include "list.h"
#include "report.h"
#include "utils.h"


void generaReport(List lista) 
{
    /*
        In questa funzione viene generato un report degli studi presenti nella lista.
        Viene stampato il numero totale di studi e i dettagli di ciascuno se la lista
        non è vuota.
    */
    if (lista == NULL || isEmpty(lista)) {
        printf("La lista degli studi è vuota.\n");
        return;
    }

    printf("\n===== REPORT STUDI =====\n");

    printf("Numero totale di studi: %d\n\n", sizeList(lista));
    printList(lista);

    printf("========================\n");
}

void aggiornaCompletamentoNome(List lista, char *nomeStudio, int nuovoStato) 
{
    /*
        Questa funzione aggiorna lo stato di completamento di uno studio specifico
        nella lista, identificato dal nome. Se lo studio non viene trovato o se il
        nuovo stato non è valido, viene stampato un messaggio di errore.
    */
    int trovato=0;

    for (int i = 0; i < sizeList(lista); i++) 
    {
        Studio studio = getListItem(lista, i);
        if((trovato = aggiornaCompletamento(studio, nuovoStato, nomeStudio)) >=-1 && trovato <=1)
        {
            generaReport(lista);
            monitoraggioData(lista);
        };   
    }
}

void monitoraggioData(List lista)
{
    /*
        Questa funzione controlla lo stato di ciascuno studio nella lista rispetto alla data
        odierna. Se uno studio è scaduto o completato, viene stampato un messaggio appropriato.
    */
    if(lista == NULL || isEmpty(lista)) 
    {
        printf("La lista degli studi è vuota.\n");
        return;
    }

    for(int i = 0; i < sizeList(lista); i++) 
    {
        Studio studio = getListItem(lista, i);
        if(studio != NULL) 
        {
            controlloStudio(studio, dataOggi());   
        } 
        else 
        {
            printf("Errore: studio non trovato nella lista.\n");
        }
    }
}