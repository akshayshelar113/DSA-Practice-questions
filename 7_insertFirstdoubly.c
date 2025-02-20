#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;

};

void InsertFirst(struct node **, int);

int main(void)
{
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);

    return 0;
}


void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("Memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    if(NULL == *ppHead)
    {
        pNewNode -> pNext = NULL;
        *ppHead= pNewNode;
        return;
    }

    pNewNode->pNext=*ppHead;
    (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;
    
}