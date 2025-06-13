#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studio.h"
#include "utils.h"

int compare_strings(const char *s1, const char *s2) 
{
    return strcmp(s1, s2) == 0;
}

// --- Test per utils.c ---

void test_dataOggi() {
    printf("Running test_dataOggi...\n");
    int today = dataOggi();
    // Non possiamo asserire un valore specifico per dataOggi,
    // ma possiamo fare un controllo di formato e range
    int year = today / 10000;
    int month = (today / 100) % 100;
    int day = today % 100;

    if (year >= 2024 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
        printf("test_dataOggi PASSED: Formato e range plausibili.\n");
    } else {
        printf("test_dataOggi FAILED: Formato o range non plausibili. Data: %d\n", today);
    }
}

void test_dataValida() {
    printf("Running test_dataValida...\n");
    // Test casi validi
    if (dataValida(20231005) == 1) {
        printf("test_dataValida PASSED: 20231005 valida.\n");
    } else {
        printf("test_dataValida FAILED: 20231005 non valida.\n");
    }

    if (dataValida(20240229) == 1) { // Anno bisestile
        printf("test_dataValida PASSED: 20240229 valida (anno bisestile).\n");
    } else {
        printf("test_dataValida FAILED: 20240229 non valida (anno bisestile).\n");
    }
    
    // Test casi non validi
    if (dataValida(20230230) == 0) { // Giorno non esistente
        printf("test_dataValida PASSED: 20230230 non valida (giorno non esistente).\n");
    } else {
        printf("test_dataValida FAILED: 20230230 valida (giorno non esistente).\n");
    }

    if (dataValida(20231301) == 0) { // Mese non esistente
        printf("test_dataValida PASSED: 20231301 non valida (mese non esistente).\n");
    } else {
        printf("test_dataValida FAILED: 20231301 valida (mese non esistente).\n");
    }

    if (dataValida(20230631) == 0) { // Giorno non esistente per giugno
        printf("test_dataValida PASSED: 20230631 non valida (giugno ha 30 giorni).\n");
    } else {
        printf("test_dataValida FAILED: 20230631 valida (giugno ha 30 giorni).\n");
    }
}

// --- Test per list.c ---

void test_newList_isEmpty() 
{
    printf("Running test_newList_isEmpty...\n");
    List list = newList();
    if (list != NULL && isEmpty(list) == 1 && sizeList(list) == 0) {
        printf("test_newList_isEmpty PASSED: Lista creata vuota.\n");
    } else {
        printf("test_newList_isEmpty FAILED: Errore creazione lista o isEmpty/sizeList.\n");
    }
    freeList(list); // Libera la memoria
}

void test_addHead_sizeList_getListItem() {
    printf("Running test_addHead_sizeList_getListItem...\n");
    List list = newList();
    
    // Creazione di alcuni Studio per i test (usiamo allocazione statica per semplicità qui)
    // NOTA: In un test reale, useresti newStudio e inputStudio simulando l'input.
    // Per questo test, useremo dei mock semplici
    Studio s1 = newStudio("Studio A", "Corso X", 1, 60, 20251231);
    Studio s2 = newStudio("Studio B", "Corso Y", 2, 30, 20251130);

    addHead(list, s1);
    if (sizeList(list) == 1 && !isEmpty(list)) {
        printf("test_addHead_sizeList_getListItem PASSED: Aggiunto un elemento, size è 1.\n");
    } else {
        printf("test_addHead_sizeList_getListItem FAILED: Problema con addHead o sizeList (dopo 1 elemento).\n");
    }

    addHead(list, s2);
    if (sizeList(list) == 2) {
        printf("test_addHead_sizeList_getListItem PASSED: Aggiunto due elementi, size è 2.\n");
    } else {
        printf("test_addHead_sizeList_getListItem FAILED: Problema con addHead o sizeList (dopo 2 elementi).\n");
    }

    // getListItem verifica se l'ordine è corretto (ultimo aggiunto è head)
    if (getListItem(list, 0) == s2 && getListItem(list, 1) == s1) {
        printf("test_addHead_sizeList_getListItem PASSED: getListItem recupera gli elementi correttamente.\n");
    } else {
        printf("test_addHead_sizeList_getListItem FAILED: getListItem recupera gli elementi in ordine sbagliato.\n");
    }

    // Test getListItem con indice fuori dai limiti
    if (getListItem(list, -1) == NULL && getListItem(list, 2) == NULL) {
        printf("test_addHead_sizeList_getListItem PASSED: getListItem gestisce indici fuori limiti.\n");
    } else {
        printf("test_addHead_sizeList_getListItem FAILED: getListItem non gestisce indici fuori limiti.\n");
    }

    // Nota: freeList libererà anche gli studi s1 e s2
    freeList(list); 
}

// --- Test per item.c (limitato, dato che Item è void* e le funzioni usano strcmp) ---

void test_cmpItem() {
    printf("Running test_cmpItem...\n");
    char *itemA = strdup("banana");
    char *itemB = strdup("apple");
    char *itemC = strdup("banana");

    if (cmpItem(itemA, itemB) > 0) { // banana > apple
        printf("test_cmpItem PASSED: 'banana' > 'apple'.\n");
    } else {
        printf("test_cmpItem FAILED: 'banana' non è maggiore di 'apple'.\n");
    }

    if (cmpItem(itemB, itemA) < 0) { // apple < banana
        printf("test_cmpItem PASSED: 'apple' < 'banana'.\n");
    } else {
        printf("test_cmpItem FAILED: 'apple' non è minore di 'banana'.\n");
    }

    if (cmpItem(itemA, itemC) == 0) { // banana == banana
        printf("test_cmpItem PASSED: 'banana' == 'banana'.\n");
    } else {
        printf("test_cmpItem FAILED: 'banana' non è uguale a 'banana'.\n");
    }

    freeItem(itemA);
    freeItem(itemB);
    freeItem(itemC);
}

// --- Test per studio.c (Assumendo l'esistenza delle funzioni in studio.c) ---
// Per testare queste, avremmo bisogno dell'implementazione di studio.c
// Qui simuliamo i test su alcune delle funzioni dichiarate in studio.h

void test_newStudio() {
    printf("Running test_newStudio...\n");
    Studio s = newStudio("Matematica", "Analisi 1", 5, 120, 20250715);
    if (s != NULL) {
        printf("test_newStudio PASSED: Studio creato con successo.\n");
        // Qui dovremmo aggiungere asserzioni per i campi di Studio
        // ma non abbiamo accesso diretto ai membri di struct studio
        // Potremmo aggiungere funzioni getter in studio.h per testare questo.
        deleteStudio(s); // Libera la memoria
    } else {
        printf("test_newStudio FAILED: Impossibile creare lo Studio.\n");
    }
}

void test_aggiornaCompletamento() {
    printf("Running test_aggiornaCompletamento...\n");
    // Per testare questa funzione, dovremmo mockare uno Studio o avere i getter.
    // Assumiamo che aggiornaCompletamento cambi uno stato interno.
    // Questo è un test molto basilare, non conoscendo l'implementazione interna.
    Studio s = newStudio("Fisica", "Meccanica", 3, 90, 20250820);
    if (s != NULL) {
        // Supponiamo che aggiornaCompletamento restituisca 1 in caso di successo
        if (aggiornaCompletamento(s, 0, "Fisica") == 1) { // -1 = non iniziata, 0 = in corso, 1 = completata
            printf("test_aggiornaCompletamento PASSED: Stato aggiornato a 'in corso'.\n");
        } else {
            printf("test_aggiornaCompletamento FAILED: Aggiornamento stato fallito.\n");
        }
        deleteStudio(s);
    } else {
        printf("test_aggiornaCompletamento FAILED: Impossibile creare lo Studio per il test.\n");
    }
}

void test_controlloStudio() {
    printf("Running test_controlloStudio...\n");
    Studio s1 = newStudio("Progetto X", "Ingegneria", 2, 200, 20250610); // Scaduto
    Studio s2 = newStudio("Progetto Y", "Ingegneria", 2, 200, 20250730); // Non scaduto (per oggi: 2025-06-13)

    // Simuliamo dataOggi per i test
    // Per testare questa funzione in modo robusto, sarebbe ideale poter
    // passare la data odierna come parametro o mockare dataOggi().
    // Per ora, assumiamo che dataOggi() restituisca la data corrente.
    // Se esegui il test il 13 giugno 2025, s1 dovrebbe essere scaduto.
    int today = 20250613; // Data odierna simulata per il test

    // Necessiterebbe di un modo per "leggere" lo stato interno di Studio dopo controlloStudio
    // Se controlloStudio stampa un messaggio, dovremmo catturare l'output.
    // Qui testiamo il valore di ritorno, se presente.
    // L'attuale controlloStudio in studio.h non ha valore di ritorno, lo aggiungiamo.
    // Per il momento possiamo solo assumere che faccia il suo lavoro.

    printf("test_controlloStudio: Necessita di output catturato o modifiche a studio.h per asserzioni dirette.\n");
    // Esempio:
    // if (controlloStudio(s1, today) == 1) { // Assumendo che 1 significhi "scaduto"
    //     printf("PASSED: Studio scaduto rilevato.\n");
    // } else {
    //     printf("FAILED: Studio scaduto non rilevato.\n");
    // }

    deleteStudio(s1);
    deleteStudio(s2);
}


int main() {
    printf("Starting functional tests for your C project...\n\n");

    // Esegui i test delle funzioni di utilità
    test_dataOggi();
    printf("\n");
    test_dataValida();
    printf("\n");

    // Esegui i test delle funzioni della lista
    test_newList_isEmpty();
    printf("\n");
    test_addHead_sizeList_getListItem();
    printf("\n");

    // Esegui i test delle funzioni item
    test_cmpItem();
    printf("\n");

    // Esegui i test delle funzioni studio (necessitano dell'implementazione di studio.c)
    test_newStudio();
    printf("\n");
    test_aggiornaCompletamento();
    printf("\n");
    test_controlloStudio(); // Questo test è concettuale senza l'implementazione completa e getter/setter

    printf("\nAll tests completed.\n");
    return 0;
}