#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include"item.h"
#include"list.h"
#include"studio.h"


typedef struct studio
{
    char nome[100];
    char corso[100];
    int priorita; //2 = alta, 1 = media, 0 = bassa
    int completata; // 1 = completata, 0 = in corso, -1 = non iniziata
    int durata; // in minuti
    int dataScadenza; // formato AAAAMMGG (es. 20231005 per il 5 ottobre 2023)
} *Studio;

Studio newStudio(char *nome, char *corso, int priorita, int durata, int dataScadenza) 
{
    Studio studio = malloc(sizeof(struct studio));
    strcpy(studio->nome, nome);
    strcpy(studio->corso, corso);
    studio->priorita = priorita;
    studio->completata = -1; // inizialmente non iniziata
    studio->durata = durata;
    studio->dataScadenza = dataScadenza;
    return studio;
}

Studio inputStudio() 
{
    char nome[100], corso[100];
    int priorita = -1, durata = 0, dataScadenza = 0;

    while (getchar() != '\n'); // pulizia del buffer di input

    printf("Inserisci il nome dello studio: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;  // rimuove '\n' se presente

    printf("Inserisci il corso: ");
    fgets(corso, sizeof(corso), stdin);
    corso[strcspn(corso, "\n")] = 0;

    while (priorita < 0 || priorita > 2) 
    {
        printf("Inserisci la priorità (2 = alta, 1 = media, 0 = bassa): ");
        if (scanf("%d", &priorita) != 1) {
            while (getchar() != '\n'); // pulizia input
            priorita = -1; // forza ripetizione
        }
    }

    while (durata <= 0) 
    {
        printf("Inserisci la durata in minuti: ");
        if (scanf("%d", &durata) != 1) {
            while (getchar() != '\n');
            durata = 0;
        }
    }

    while (dataScadenza <= 20250101) 
    {
        printf("Inserisci la data di scadenza (formato AAAAMMGG): ");
        if (scanf("%d", &dataScadenza) != 1) {
            while (getchar() != '\n');
            dataScadenza = 0;
        }
    }

    while (getchar() != '\n');

    return newStudio(nome, corso, priorita, durata, dataScadenza);
}

void outputStudio(Studio studio) 
{
    printf("Nome: %s, Corso: %s, Priorità: %d, Completata: %d, Durata: %d minuti, Data di Scadenza: %d\n", 
           studio->nome, studio->corso, studio->priorita, studio->completata, studio->durata, studio->dataScadenza);
}

void deleteStudio(Studio studio) 
{
    free(studio);
}

int controlloStudio(Studio studio, int dataOggi) 
{
    if (studio == NULL) {
            printf("Errore: studio non trovato nella lista.\n");
            return -1;
        }
        
        if (studio->completata == -1 && dataOggi >= studio->dataScadenza) {
            printf("ATTENZIONE: Lo studio \"%s\" è scaduto e non è stato iniziato.\n", studio->nome);
        } else if (studio->completata == 0 && dataOggi >= studio->dataScadenza) {
            printf("ATTENZIONE: Lo studio \"%s\" è scaduto ma è ancora in corso.\n", studio->nome);
        } else if (studio->completata == 1) {
            printf("Lo studio \"%s\" è stato completato\n", studio->nome);
        } else {
            printf("Lo studio \"%s\" è ancora in tempo.\n", studio->nome);
        }
}

int aggiornaCompletamento(Studio studio, int nuovoStato, const char *nomeStudio) 
{
    if (nuovoStato < -1 || nuovoStato > 1) {
        printf("Errore: stato non valido. Deve essere -1, 0 o 1.\n");
        return -1;
    }
    else if (studio == NULL) 
    {
        printf("Errore: studio non trovato nella lista.\n");
        return -1;
    }
    else if((strcasecmp(studio->nome, nomeStudio) != 0 )) 
    {
        printf("Nessuno studio trovato con il nome specificato.\n");
        return -1;
    }
    else if (strcasecmp(studio->nome, nomeStudio) == 0 && studio->completata != nuovoStato) 
    {
        studio->completata = nuovoStato;
        printf("Stato dello studio \"%s\" aggiornato a %d.\n", studio->nome, nuovoStato);
        return 1;
    }
    else if(strcasecmp(studio->nome, nomeStudio) == 0 && studio->completata == nuovoStato) 
    {
        printf("Lo stato dello studio \"%s\" è già %d.\n", studio->nome, nuovoStato);
        return 0;
    }
      
}
