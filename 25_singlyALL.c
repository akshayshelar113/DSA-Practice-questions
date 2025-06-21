#include <stdio.h>

struct node
{
    struct node *pNext;
    int iData;
};

void InsertFirst(struct node **, int);
void InsertLast(struct node **, int);
void InsertAtPosition(struct node **, int, int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);

void Display(struct node *);
int CountNodes(struct node *);

int main(void)
{
    int iCount, iDelData;
    struct node *pFirst = NULL;

    printf("Insert First\n");
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    Display(pFirst);

    iCount = CountNodes(pFirst);
    printf("\nCount of nodes is:- %d", iCount);

    printf("\n\nInsert Last\n");
    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 60);
    Display(pFirst);
    iCount = CountNodes(pFirst);
    printf("\nCount of nodes is:- %d", iCount);

    printf("\n\nInsert at position\n");
    InsertAtPosition(&pFirst, 100, 4);
    InsertAtPosition(&pFirst, 200, 1);
    Display(pFirst);
    iCount = CountNodes(pFirst);
    printf("\nCount of nodes is:- %d", iCount);

    printf("\n\nDelete at first");
    iDelData = DeleteFirst(&pFirst);
    if (iDelData == -1)
        printf("\nList is empty\n");
    else
    {
        printf("\nDeleted data is: %d\n", iDelData);
        Display(pFirst);
        iCount = CountNodes(pFirst);
        printf("\nCount of nodes is:- %d", iCount);
    }

    printf("\n\nDelete at last");
    iDelData = DeleteLast(&pFirst);
    if (iDelData == -1)
        printf("\nList is empty\n");
    else
    {
        printf("\nDeleted data is: %d\n", iDelData);
        Display(pFirst);
        iCount = CountNodes(pFirst);
        printf("\nCount of nodes is:- %d", iCount);
    }

    return 0;
}

int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
        return -1;

    pTemp = *ppHead;

    while (pTemp->pNext->pNext != NULL)
        pTemp = pTemp->pNext;

    iDelData = pTemp->pNext->iData;

    free(pTemp->pNext);
    pTemp->pNext = NULL;

    return iDelData;
}

int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
        return -1;

    pTemp = *ppHead;

    *ppHead = pTemp->pNext;

    iDelData = pTemp->iData;

    pTemp->pNext = NULL;
    free(pTemp);

    return iDelData;
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
    }
    else
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
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
    }

    pTemp = *ppHead;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
}

void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int iCounter;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCounter = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCounter + 1)
    {
        printf("Invalaid position");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(ppHead, iNo);
        return;
    }

    // if (iPos == iCounter + 1)
    // {
    //     InsertLast(ppHead, iNo);
    //     return;
    // }

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

int CountNodes(struct node *pHead)
{
    int icounter = 0;

    while (pHead != NULL)
    {
        icounter++;
        pHead = pHead->pNext;
    }

    return icounter;
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
