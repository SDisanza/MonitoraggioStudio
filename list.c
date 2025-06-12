#include <stdio.h>
#include <stdlib.h>
#include"item.h"
#include"list.h"
#include"studio.h"

struct list
{
    int size;
    struct node *head;
};

struct node
{
    Item item;
    struct node *next;    
};

List newList()
{
    List list=malloc(sizeof(struct list));
    list->size=0;
    list->head=NULL;

    return list;
}

int isEmpty(List list)
{
    if(list->size==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void addHead(List list, Item item)
{
    struct node *node=malloc(sizeof(struct node));

    node->item=item;
    node->next=list->head;
    list->head=node;
    (list->size)++;
}

int sizeList(List list)
{
    return list->size;
}

void printList(List list)
{
    struct node *p;
    
    for(p=list->head; p!=NULL; p=p->next)
    {
        outputStudio(p->item);
    }
}

void freeList(List list)
{
    struct node *p, *next;

    for(p=list->head; p!=NULL; p=next)
    {
        next=p->next;
        freeItem(p->item);
        free(p);
    }

    free(list);
}

Item getListItem(List list, int pos)
{
    struct node *p;
    int i;

    if(pos<0 || pos>=list->size)
    {
        printf("Indice fuori dai limiti\n");
        return NULL;
    }

    for(p=list->head, i=0; p!=NULL && i<pos; p=p->next, i++);

    return p->item;
}