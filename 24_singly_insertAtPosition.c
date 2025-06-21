#include <stdio.h>

struct node
{
    struct node *pNext;
    int iData;
};

void InsertAtPosition(struct node **, int, int);
void InsertFirst(struct node **, int);
void InsertLast(struct node **, int);
void Display(struct node *);
int CountNode(struct node *);

int main(void)
{
    struct node *pFirst = NULL;

    InsertAtPosition(&pFirst, 10, 1);
    Display(pFirst);
    printf("\n\n");
    InsertAtPosition(&pFirst, 20, 1);
    Display(pFirst);
    printf("\n\n");
    InsertAtPosition(&pFirst, 30, 5);
    Display(pFirst);
    printf("\n\n");
    InsertAtPosition(&pFirst, 40, 2);
    Display(pFirst);
    printf("\n\n");
    InsertAtPosition(&pFirst, 50, 3);
    Display(pFirst);
    printf("\n\n");
    InsertAtPosition(&pFirst, 60, 2);
    Display(pFirst);

    return 0;
}

void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int iCounter;
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    iCounter = CountNode(*ppHead);

    if (iPos <= 0 || iPos > iCounter + 1)
    {
        printf("\nInvalid position\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(ppHead, iNo);
        return;
    }

    if (iPos == iCounter + 1)
    {
        InsertLast(ppHead, iNo);
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;

    pTemp = *ppHead;
    iCounter = 1;

    while (iCounter < iPos - 1)
    {
        iCounter++;
        pTemp = pTemp->pNext;
    }

    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
}

void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
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

void InsertLast(struct node **pphead, int iNo)
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

    if (NULL == *pphead)
    {
        *pphead = pNewNode;
        return;
    }

    pTemp = *pphead;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
}

int CountNode(struct node *pHead)
{
    int iCounter = 0;

    while (pHead != NULL)
    {
        iCounter++;
        pHead = pHead->pNext;
    }
    return iCounter;
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