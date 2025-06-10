#include<stdio.h>
#include<stdlib.h>
#include"studio.h"
#include"item.h"
#define NCHAR 100

Item inputItem()
{
    char *pointerInput;

    pointerInput=malloc(NCHAR * sizeof(char));
    scanf("%s", pointerInput);

    return pointerInput;
}

void outputItem(Item item)
{
    char *pointerOuput;

    pointerOuput=item;
    printf("%s ", pointerOuput);
}

int cmpItem(Item itemA, Item itemB)
{
    char *pointerA, *pointerB;

    pointerA=itemA;
    pointerB=itemB;

    return strcmp(pointerA, pointerB);
}