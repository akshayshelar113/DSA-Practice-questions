#include <stdio.h>

struct node
{
    struct node *pNext;
    int iData;
};

void ConcatList(struct node **, struct node **);
void ConcatFirst(struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, int);
void InsertFirst(struct node **, int);
void InsertLast(struct node **, int);
void InsertAtPosition(struct node **, int, int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **, int);
int CountNodes(struct node *);
void Display(struct node *);
int SearchFirstOccurance(struct node *, int);
int SearchLastOccurance(struct node *, int);
void DeletAll(struct node **);
int main(void)
{
    int iData;

    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    printf("Insert First\n");
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    Display(pFirst);

    printf("\n\nInsert Last\n");
    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 60);
    Display(pFirst);

    printf("\n\nInsert at position\n");
    InsertAtPosition(&pFirst, 2, 100);
    InsertAtPosition(&pFirst, 3, 200);
    InsertAtPosition(&pFirst, 5, 300);
    Display(pFirst);

    printf("\n\nDelete First");
    iData = DeleteFirst(&pFirst);
    if (iData != -1)
        printf("\ndeleted data is: %d\n", iData);
    Display(pFirst);

    printf("\n\nDelete Last");
    iData = DeleteLast(&pFirst);
    if (iData != -1)
        printf("\ndeleted data is: %d\n", iData);
    Display(pFirst);

    printf("\n\nDelete At position");
    iData = DeleteAtPosition(&pFirst, 2);
    if (iData != -1)
        printf("\ndeleted data is: %d\n", iData);
    Display(pFirst);

    printf("\n\nSecond list\n");
    InsertLast(&pSecond, 1);
    InsertLast(&pSecond, 2);
    InsertLast(&pSecond, 3);
    Display(pSecond);

    printf("\n\nConcated list\n");
    ConcatList(&pFirst, &pSecond);
    Display(pFirst);

    printf("\n\nConcat First\n");
    InsertLast(&pSecond, 101);
    InsertLast(&pSecond, 102);
    InsertLast(&pSecond, 103);
    ConcatFirst(&pFirst, &pSecond);
    Display(pFirst);

    printf("\n\nConcat At position\n");
    InsertLast(&pSecond, 201);
    InsertLast(&pSecond, 202);
    InsertLast(&pSecond, 203);
    InsertLast(&pSecond, 1);
    ConcatAtPosition(&pFirst, &pSecond, 10);
    Display(pFirst);

    printf("\n\nSearch first occurance\n");
    iData = SearchFirstOccurance(pFirst, 2);
    printf("key 2 found at %d position\n", iData);

    printf("\nSearch last occurance\n");
    iData = SearchLastOccurance(pFirst, 1);
    printf("key 1 found last at %d position\n", iData);

    printf("\nDeleting all\n");
    DeletAll(&pFirst);
    Display(pFirst);

    return 0;
}

void DeletAll(struct node **ppHead)
{
    struct node *pTemp = NULL;

    while (*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
}

int SearchLastOccurance(struct node *pHead, int iKey)
{
    int iPos = 0;
    int iHolder;

    while (pHead != NULL)
    {
        iPos++;
        if (pHead->iData == iKey)
        {
            iHolder = iPos;
        }
        pHead = pHead->pNext;
    }
    return iHolder;
}

int SearchFirstOccurance(struct node *pHead, int iKey)
{
    int iPos = 0;

    while (pHead != NULL)
    {
        iPos++;
        if (pHead->iData == iKey)
            return iPos;

        pHead = pHead->pNext;
    }
    return 0;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCounter;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCounter = CountNodes(*ppHead1);

    if (iPos <= 0 || iPos > iCounter + 1)
    {
        printf("\nInvalid position\n");
        return;
    }

    if (iPos == iCounter + 1)
    {
        ConcatList(ppHead1, ppHead2);
        return;
    }

    if (iPos == 1)
    {
        ConcatFirst(ppHead1, ppHead2);
        return;
    }

    iCounter = 1;
    pTemp1 = *ppHead1;
    pTemp2 = *ppHead2;

    while (iCounter < iPos - 1)
    {
        iCounter++;
        pTemp1 = pTemp1->pNext;
    }

    while (pTemp2->pNext != NULL)
        pTemp2 = pTemp2->pNext;

    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = *ppHead2;

    *ppHead2 = NULL;
}

void ConcatFirst(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    if (NULL == *ppHead2)
        return;

    if (NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    pTemp1 = *ppHead1;
    pTemp2 = *ppHead2;

    while (pTemp2->pNext != NULL)
        pTemp2 = pTemp2->pNext;

    pTemp2->pNext = *ppHead1;

    *ppHead1 = *ppHead2;
    *ppHead2 = NULL;
}

void ConcatList(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if (NULL == *ppHead2)
        return;

    if (NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    pTemp = *ppHead1;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = *ppHead2;
    *ppHead2 = NULL;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iCounter;
    int iDelData;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCounter = CountNodes(*ppHead);

    if (NULL == *ppHead)
        return -1;

    if (iPos <= 0 || iPos > iCounter)
    {
        printf("\nInvalid position\n");
        return -1;
    }

    if (iPos == 1)
    {
        iDelData = DeleteFirst(ppHead);
        return iDelData;
    }

    if (iPos == iCounter)
    {
        iDelData = DeleteLast(ppHead);
        return iDelData;
    }

    pTemp1 = *ppHead;
    iCounter = 1;

    while (iCounter < iPos - 1)
        pTemp1 = pTemp1->pNext;

    pTemp2 = pTemp1->pNext;
    iDelData = pTemp2->iData;

    pTemp1->pNext = pTemp2->pNext;
    pTemp2->pNext = NULL;

    free(pTemp2);

    return iDelData;
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
    int iData;
    struct node *pTemp = NULL;

    if (NULL == *ppHead)
        return -1;

    pTemp = *ppHead;

    *ppHead = pTemp->pNext;

    iData = pTemp->iData;
    pTemp->pNext = NULL;

    free(pTemp);
    return iData;
}

void InsertAtPosition(struct node **ppHead, int iPos, int iNo)
{
    int iCounter;
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    iCounter = CountNodes(*ppHead);

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

int CountNodes(struct node *pHead)
{
    int iCounter = 0;

    while (pHead != NULL)
    {
        iCounter++;
        pHead = pHead->pNext;
    }

    return iCounter;
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