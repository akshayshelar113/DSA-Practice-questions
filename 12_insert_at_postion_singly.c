#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertAtPosition(struct node **, int, int);
int CountNodes(struct node *);
void InsertFirst(struct node **, int);
void InsertLast(struct node **, int);

void Display(struct node *);

int main(void)
{
    struct node *pFirst = NULL;

    InsertAtPosition(&pFirst, 10, 1);
    InsertAtPosition(&pFirst, 20, 2);
    InsertAtPosition(&pFirst, 30, 1);
    Display(pFirst);

    return 0;
}

void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int iCount;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = CountNodes(*ppHead);

    if (iPos <= 0 || iPos > iCount + 1)
    {
        printf("Invalid position");
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(ppHead, iNo);
        return;
    }

    if (iPos == iCount + 1)
    {
        InsertLast(ppHead, iNo);
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;

    pTemp = *ppHead;
    iCount = 1;

    while (iCount < iPos - 1)
    {
        iCount++;
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
        printf("Memory allocation fail");
        return;
    }
    printf("In Insert first");

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
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));
    printf("In Insert Last");
    if (NULL == pNewNode)
    {
        printf("Memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if (NULL == *ppHead)
        *ppHead = pNewNode;

    pTemp = *ppHead;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
}

int CountNodes(struct node *pHead)
{
    int iCount = 0;

    while (pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
}

void Display(struct node *pHead)
{
    int iCount = 0;
    if (NULL == pHead)
    {
        printf("List is empty");
        return;
    }

    while (pHead != NULL)
    {
        iCount++;
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
}
