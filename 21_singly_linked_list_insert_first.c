#include <stdio.h>

struct node
{
    struct node *pNext;
    int iData;
};

void InsertFirst(struct node **, int);
void Display(struct node *);

int main(void)
{
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);
    Display(pFirst);

    return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("Memory allocation failed");
    }

    pNewNode->iData= iNo;

    if(NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }

    pNewNode->pNext= *ppHead;
    *ppHead=pNewNode;
    return;
}

void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("List is empty");
        return;
    }

    while (pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead=pHead->pNext;
    } 
}
