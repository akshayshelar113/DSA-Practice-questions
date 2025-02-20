#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void InsertLast(struct node **, int);
void Display(struct node *);

void ConcatList(struct node **, struct node **);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);
    printf("\nFirst List is\n");
    Display(pFirst);

    InsertLast(&pSecond, 50);
    InsertLast(&pSecond, 60);
    InsertLast(&pSecond, 70);
    printf("\n\nSecond List is\n");
    Display(pSecond);

    printf("\n\nConcated List is\n");
    ConcatList(&pFirst, &pSecond);
    Display(pFirst);

    return 0;
}

void ConcatList(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if(NULL == ppHead2)
    return;

    if(NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    pTemp = *ppHead1;

    while(pTemp->pNext != NULL)
    pTemp=pTemp->pNext;

    pTemp->pNext = *ppHead2;
    *ppHead2 = NULL;
}




void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;

    if (NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(NULL == *ppHead)
    {
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;
    while(pTemp->pNext != NULL)
    pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
}

void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("List is empty");
        return;
    }

    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
}