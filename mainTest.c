#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studio.h"
#include "report.h"
#include "utils.h"


// --- Test per utils.c ---

void test_dataOggi() {
    printf("Running test_dataOggi...\n");
    int today = dataOggi();
    int year = today / 10000;
    int month = (today / 100) % 100;
    int day = today % 100;

    if (year >= 2024 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
        printf("test_dataOggi PASSED: Formato e range plausibili.\n");
    } 
    else 
    {
        printf("test_dataOggi FAILED: Formato o range non plausibili. Data: %d\n", today);
    }
}

void test_dataValida() {
    printf("Running test_dataValida...\n");
    
    if (dataValida(20231005) == 1) 
    {
        printf("test_dataValida PASSED: 20231005 valida.\n");
    } 
    else 
    {
        printf("test_dataValida FAILED: 20231005 non valida.\n");
    }

    if (dataValida(20240229) == 1) 
    { 
        printf("test_dataValida PASSED: 20240229 valida (anno bisestile).\n");
    } 
    else 
    {
        printf("test_dataValida FAILED: 20240229 non valida (anno bisestile).\n");
    }
    
    // Test casi non validi
    if (dataValida(20230230) == 0) 
    { 
        printf("test_dataValida PASSED: 20230230 non valida (giorno non esistente).\n");
    } 
    else 
    {
        printf("test_dataValida FAILED: 20230230 valida (giorno non esistente).\n");
    }

    if (dataValida(20231301) == 0) 
    { 
        printf("test_dataValida PASSED: 20231301 non valida (mese non esistente).\n");
    } 
    else 
    {
        printf("test_dataValida FAILED: 20231301 valida (mese non esistente).\n");
    }

    if (dataValida(20230631) == 0) 
    { 
        printf("test_dataValida PASSED: 20230631 non valida (giugno ha 30 giorni).\n");
    } 
    else 
    {
        printf("test_dataValida FAILED: 20230631 valida (giugno ha 30 giorni).\n");
    }
}

// --- Test per list.c ---

void test_newList_isEmpty() 
{
    printf("Running test_newList_isEmpty...\n");
    List list = newList();
    if (list != NULL && isEmpty(list) == 1 && sizeList(list) == 0) 
    {
        printf("test_newList_isEmpty PASSED: Lista creata vuota.\n");
    } 
    else 
    {
        printf("test_newList_isEmpty FAILED: Errore creazione lista o isEmpty/sizeList.\n");
    }
    freeList(list); // Libera la memoria
}

void test_addHead_sizeList_getListItem() 
{
    printf("Running test_addHead_sizeList_getListItem...\n");
    List list = newList();
    
    // Creazione di alcuni Studio per i test (usiamo allocazione statica per semplicità qui)
    Studio s1 = newStudio("Studio A", "Corso X", 1, 60, 20251231);
    Studio s2 = newStudio("Studio B", "Corso Y", 2, 30, 20251130);

    addHead(list, s1);
    if (sizeList(list) == 1 && !isEmpty(list)) 
    {
        printf("test_addHead_sizeList_getListItem PASSED: Aggiunto un elemento, size è 1.\n");
    } 
    else 
    {
        printf("test_addHead_sizeList_getListItem FAILED: Problema con addHead o sizeList (dopo 1 elemento).\n");
    }

    addHead(list, s2);
    if (sizeList(list) == 2) 
    {
        printf("test_addHead_sizeList_getListItem PASSED: Aggiunto due elementi, size è 2.\n");
    } 
    else 
    {
        printf("test_addHead_sizeList_getListItem FAILED: Problema con addHead o sizeList (dopo 2 elementi).\n");
    }

    // getListItem verifica se l'ordine è corretto (ultimo aggiunto è head)
    if (getListItem(list, 0) == s2 && getListItem(list, 1) == s1) 
    {
        printf("test_addHead_sizeList_getListItem PASSED: getListItem recupera gli elementi correttamente.\n");
    } 
    else 
    {
        printf("test_addHead_sizeList_getListItem FAILED: getListItem recupera gli elementi in ordine sbagliato.\n");
    }

    // Test getListItem con indice fuori dai limiti
    if (getListItem(list, -1) == NULL && getListItem(list, 2) == NULL) 
    {
        printf("test_addHead_sizeList_getListItem PASSED: getListItem gestisce indici fuori limiti.\n");
    } 
    else 
    {
        printf("test_addHead_sizeList_getListItem FAILED: getListItem non gestisce indici fuori limiti.\n");
    }

    // Nota: freeList libererà anche gli studi s1 e s2
    freeList(list); 
}

// --- Test per item.c  ---

void test_cmpItem() 
{
    printf("Running test_cmpItem...\n");
    char *itemA = strdup("banana");
    char *itemB = strdup("apple");
    char *itemC = strdup("banana");

    if (cmpItem(itemA, itemB) > 0) 
    { 
        printf("test_cmpItem PASSED: 'banana' > 'apple'.\n");
    }
    else
    {
        printf("test_cmpItem FAILED: 'banana' non è maggiore di 'apple'.\n");
    }

    if (cmpItem(itemB, itemA) < 0) 
    { 
        printf("test_cmpItem PASSED: 'apple' < 'banana'.\n");
    } 
    else 
    {
        printf("test_cmpItem FAILED: 'apple' non è minore di 'banana'.\n");
    }

    if (cmpItem(itemA, itemC) == 0) 
    { 
        printf("test_cmpItem PASSED: 'banana' == 'banana'.\n");
    } 
    else 
    {
        printf("test_cmpItem FAILED: 'banana' non è uguale a 'banana'.\n");
    }

    freeItem(itemA);
    freeItem(itemB);
    freeItem(itemC);
}

// --- Test per studio.c (Assumendo l'esistenza delle funzioni in studio.c) ---
void test_printList_freeList() {
    printf("Running test_printList_freeList...\n");
    List list = newList();

    // Creazione di alcuni Studio per i test
    Studio s1 = newStudio("Matematica", "Analisi 1", 2, 120, 20251231);
    Studio s2 = newStudio("Storia", "Medioevo", 0, 60, 20250915);

    addHead(list, s2); // Aggiunge Studio2 (sarà l'ultimo della lista stampato)
    addHead(list, s1); // Aggiunge Studio1 (sarà il primo della lista stampato)

    printf("Verifica manuale: L'output seguente dovrebbe mostrare i dettagli di Studio 'Matematica' e 'Storia'.\n");
    printf("------------------------------------------------------------------------------------------\n");
    printList(list); // Chiamata alla funzione da testare
    printf("------------------------------------------------------------------------------------------\n");
    printf("test_printList PASSED (Verifica manuale richiesta): L'output e' stato generato.\n");

    // --- Test freeList ---
    printf("Testing freeList...\n");
    freeList(list); // Chiamata alla funzione da testare
    printf("test_freeList PASSED: freeList eseguita senza crash apparenti.\n");
}
void test_newStudio_deleteStudio() 
{
    printf("Running test_newStudio...\n");
    Studio s = newStudio("Matematica", "Analisi 1", 5, 120, 20250715);
    if (s != NULL) 
    {
        printf("test_newStudio PASSED: Studio creato con successo.\n");
        outputStudio(s); // Stampa i dettagli dello studio
        deleteStudio(s); // Libera la memoria
    } 
    else 
    {
        printf("test_newStudio FAILED: Impossibile creare lo Studio.\n");
    }

}

void test_aggiornaCompletamento() 
{
    printf("Running test_aggiornaCompletamento...\n");
    
    Studio s = newStudio("Fisica", "Meccanica", 3, 90, 20250820);
    if (s != NULL) 
    {
        
        if (aggiornaCompletamento(s, 0, "Fisica") == 1) { 
            printf("test_aggiornaCompletamento PASSED: Stato aggiornato a 'in corso'.\n");
        } 
        else 
        {
            printf("test_aggiornaCompletamento FAILED: Aggiornamento stato fallito.\n");
        }
        deleteStudio(s);
    } 
    else 
    {
        printf("test_aggiornaCompletamento FAILED: Impossibile creare lo Studio per il test.\n");
    }
}

void test_controlloStudio() {
    printf("Running test_controlloStudio...\n");
    Studio s1 = newStudio("Progetto X", "Ingegneria", 0, 200, 20250610); // Scaduto
    Studio s2 = newStudio("Progetto Y", "Ingegneria", 0, 200, 20250730); // Non scaduto (per oggi: 2025-06-13)

    // Simuliamo dataOggi per i test
    
    int today = 20250613; // Data odierna simulata per il test

    
    if (controlloStudio(s1, today) == 1) 
    { 
         printf("PASSED: Studio scaduto rilevato.\n");
     } 
     else 
     {
         printf("FAILED: Studio scaduto non rilevato.\n");
     }

    deleteStudio(s1);
    deleteStudio(s2);
}


int main() {
    printf("Starting functional tests for your C project...\n\n");

    // Esegui i test delle funzioni di utils
    test_dataOggi();
    printf("\n");
    test_dataValida();
    printf("\n");

    // Esegui i test delle funzioni di list
    test_newList_isEmpty();
    printf("\n");
    test_addHead_sizeList_getListItem();
    printf("\n");
    test_printList_freeList();
    printf("\n");

    // Esegui i test delle funzioni di item
    test_cmpItem();
    printf("\n");

    // Esegui i test delle funzioni di studio 
    test_newStudio_deleteStudio();
    printf("\n");
    test_aggiornaCompletamento();
    printf("\n");
    test_controlloStudio(); 

    printf("\nAll tests completed.\n");
    return 0;
}