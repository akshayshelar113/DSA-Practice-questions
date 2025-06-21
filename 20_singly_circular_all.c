#include <stdio.h>
#include <malloc.h>
0
struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, struct node **, int);
void InsertLast(struct node **, struct node **, int);
void Display(struct node *, struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    InsertFirst(&pFirst, &pLast, 10);
    Display(pFirst, pLast);

    return 0;
}

void InsertFirst(struct node **ppHead, struct node **ppTail, int iNo)
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
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext = *ppHead;
        return;
    }

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
    (*ppTail)->pNext = *ppHead;
}

void Display(struct node *pHead, struct node *pTail)
{
    if (NULL == pHead)
    {
        printf("List is empty");
        return;
    }

    do
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    } while (pTail->pNext != pHead);
}
 