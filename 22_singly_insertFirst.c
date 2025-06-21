#include<stdio.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,int);
void Display(struct node *);

int main(void)
{
    struct node *pFirst = NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,40);
    Display(pFirst);

    return 0;
}

void InsertFirst(struct node **ppHead,int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;

    if(NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
    }
    else
    pNewNode->pNext = *ppHead;

    *ppHead = pNewNode;
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