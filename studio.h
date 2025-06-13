#include<stdio.h>
#include<stdlib.h>
#include"item.h"
#include"list.h"
#include"utils.h"

typedef struct studio *Studio;

Studio newStudio(char *nome, char *corso, int priorita, int durata, int dataScadenza);
Studio inputStudio();
void outputStudio(Studio studio);
void deleteStudio(Studio studio);
int aggiornaCompletamento(Studio studio, int nuovoStato, const char *nomeStudio);
int controlloStudio(Studio studio, int dataOggi);