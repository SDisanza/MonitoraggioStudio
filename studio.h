#include<stdio.h>
#include<stdlib.h>
#include"item.h"
#include"list.h"

typedef struct studio *Studio;

Studio newStudio(char *nome, char *corso, int priorita, int durata, int dataScadenza);
void printStudio(Studio studio);
void freeStudio(Studio studio);
Studio inputStudio();
void outputStudio(Studio studio);
void deleteStudio(Studio studio);
