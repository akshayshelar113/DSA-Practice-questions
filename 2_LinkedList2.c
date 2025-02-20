#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);

int main(void)
{
    struct node *pFirst=NULL;
    printf("Value in engine pFirst: %d\n", pFirst);
    printf("Address of engine pFirst: %d\n", &pFirst);

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);


    free(pFirst);
    pFirst = NULL;

    return 0;
}

void InsertFirst( struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("Memory allocation fail");
        return;
    }

    pNewNode->iData=iNo;

    if(NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }
    pNewNode->pNext = *ppHead;
    *ppHead  = pNewNode;

}