#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void Display(struct node *);
void InsertLast(struct node **, int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);

int main(void)
{
    int iDelData;
    struct node *pFirst = NULL;

    printf("Insert at first\n");
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    Display(pFirst);

    printf("\n\nInsert at Last\n");
    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 60);
    Display(pFirst);

    printf("\n\nDelete First\n");
    iDelData = DeleteFirst(&pFirst);
    Display(pFirst);
    printf("\nDeleted data is: %d", iDelData);

    printf("\n\nDelete Last\n");
    iDelData = DeleteLast(&pFirst);
    Display(pFirst);
    printf("\nDeleted data is: %d", iDelData);

    return 0;
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

    if (*ppHead == NULL)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("String is empty");
        return;
    }

    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if (*ppHead == NULL)
    {
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
}

int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (*ppHead == NULL)
    {
        return -1;
    }

    pTemp = *ppHead;

    *ppHead = pTemp->pNext;

    iDelData = pTemp->iData;

    pTemp->pNext = NULL;

    free(pTemp);

    return iDelData;
}

int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if (*ppHead == NULL)
    {
        return -1;
    }

    pTemp = *ppHead;

    if (NULL == pTemp->pNext)
    {
        iDelData = pTemp->iData;
        free(pTemp);
        *ppHead = NULL;
    }
    else
    {
        while (pTemp->pNext->pNext != NULL)
            pTemp = pTemp->pNext;

        iDelData = pTemp->pNext->iData;

        free(pTemp->pNext);
        pTemp->pNext = NULL;
    }
    return iDelData;
}
