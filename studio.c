#include<stdio.h>
#include<stdlib.h>
#include"item.h"
#include"list.h"
#include"studio.h"
#include<string.h>

typedef struct studio;
{
    char nome[100];
    char corso[100];
    int priorita: //2 = alta, 1 = media, 0 = bassa
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

void printStudio(Studio studio) 
{
    printf("Nome: %s, Corso: %s, Priorità: %d, Completata: %d Durata: %d minuti, Data di Scadenza: %d\n", 
           studio->nome, studio->corso, studio->priorita, studio->completata, studio->durata, studio->dataScadenza);
}

void freeStudio(Studio studio) 
{
    free(studio);
}

Studio inputStudio() 
{
    char nome[100], corso[100];
    int priorita, durata, dataScadenza;

    printf("Inserisci il nome dello studio: ");
    scanf("%s", nome);
    printf("Inserisci il corso: ");
    scanf("%s", corso);

    while(priorita < 0 || priorita > 2) 
    {
        printf("Inserisci la priorità (2 = alta, 1 = media, 0 = bassa): ");
        scanf("%d", &priorita);
    }

    while(durata <= 0) 
    {
    printf("Inserisci la durata in minuti: ");
    scanf("%d", &durata);
    }

    while(dataScadenza <= 20250101) 
    {
    printf("Inserisci la data di scadenza (formato AAAAMMGG): ");
    }

    scanf("%d", &dataScadenza);

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