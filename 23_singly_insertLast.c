#include <stdio.h>

struct node
{
    struct node *pNext;
    int iData;
};

void InsertLast(struct node **, int);
void Display(struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    Display(pFirst);

    return 0;
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
        return;
    }

    pTemp= *ppHead;

    while(pTemp->pNext != NULL)
    pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;

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