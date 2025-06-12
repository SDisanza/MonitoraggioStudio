#include <stdio.h>
#include <stdlib.h>
#include"item.h"
#include"list.h"

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
        outputItem(p->item);
    }
}

Item removeListItem(List list, Item item)
{
    struct node *p, *prev;
    Item i;

    if(isEmpty(list))
    {
        fprintf(stderr, "La lista è vuota\n");
        return NULL;
    }

    for(p=list->head; p!=NULL; prev=p, p=p->next)
    {
        if(cmpItem(p->item, item)==0)
        {
            if(p==list->head)
            {
                return(removeHead(list));
            }
            else
            {
                prev->next=p->next;
                i=p->item;
                free(p);
                list->size--;
                return i;
            }
        }
    }
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