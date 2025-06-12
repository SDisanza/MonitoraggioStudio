#include"item.h"

typedef struct list *List;

List newList();
int isEmpty(List list);
void addHead(List list, Item item);
int sizeList(List list);
void printList(List list);
void freeList(List list);
Item getListItem(List list, int pos);