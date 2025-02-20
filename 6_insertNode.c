#include<stdio.h>
#include<malloc.h>

struct node {
    int iData;
    struct node *pNext;
}

void InsertFirst(struct node **,  int);

int main(void)
{
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst=NULL:
    }

    return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{

    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("memory allocation fail");
        return;
    }

    pNewNode -> iData = iNo;

    if(NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode; 
    }

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}