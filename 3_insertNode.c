#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst( struct node **, int);

int main(void)
{
    struct node *pFirst = NULL;

    printf("Value in engine pFirst creting node: %d\n",pFirst);
    printf("Address of engine pFirst before creating node: %d\n\n",&pFirst);

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);

    printf("Value in enging pFirst after creating node: %d\n", pFirst);

    return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node * ) malloc (sizeof(struct node));

    printf("Value in the New node: %d\n\n",pNewNode);

    // printf("\nValue of pNext before assign value: %d\n", (*ppHead)->pNext);

    if(NULL == pNewNode)
    {
        printf("Memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;

    if(NULL == *ppHead )
    { 
        pNewNode->pNext=NULL;
        *ppHead = pNewNode;
        printf("address of pNewNode%d\n",pNewNode);
        printf("\nValue of pNext before assign value: %d\n", (*ppHead)->pNext);
        return;
    }
    printf("\nValue of pNext before assign value: %d\n", (*ppHead)->pNext);
    
    pNewNode->pNext=*ppHead;
    printf("%d\n",(*ppHead)->pNext);
    *ppHead = pNewNode;

    // printf("\nValue of pNext: %d\n", (*ppHead)->pNext);

}