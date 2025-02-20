#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void InsertAtLast(struct node **, int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int CountNodes(struct node *);

void Display(struct node *);

int main(void)
{
    int iPlaceHolder;
    struct node *pFirst = NULL;

    printf("Inserting node at firts postion of list\n");
    InsertFirst(&pFirst, 0);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);
    Display(pFirst);

    printf("\n\nInsert at last\n");
    InsertAtLast(&pFirst, 30);
    InsertAtLast(&pFirst, 40);
    Display(pFirst);

    printf("\n\nDelete First Node\n");
    iPlaceHolder = DeleteFirst(&pFirst);
    printf("Deletd node data is: %d\n", iPlaceHolder);
    Display(pFirst);

    printf("\n\nDelete Last Node\n");
    iPlaceHolder = DeleteLast(&pFirst);
    printf("Deletd node data is: %d\n", iPlaceHolder);
    Display(pFirst);

    printf("\n\nCount Nodes\n");

    iPlaceHolder = CountNodes(pFirst);
    printf("Total nodes are: %d", iPlaceHolder);

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

    if (NULL == *ppHead)
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
        printf("List is Empty");
        return;
    }
    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
}

void InsertAtLast(struct node **ppHead, int iNo)
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

    if (NULL == *ppHead)
        *ppHead = pNewNode;

    pTemp = *ppHead;

    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
}

int DeleteFirst(struct node **ppHead)
{
    struct node *pTemp = NULL;
    int iDelData;

    if (NULL == *ppHead)
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
    if (NULL == *ppHead)
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

