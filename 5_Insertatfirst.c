#include<stdio.h>

struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);

int main(void)
{
    struct node *pEngine = NULL;

    InsertFirst(&pEngine, 10 );
    InsertFirst(&pEngine, 20);
    Display(pEngine);

    if(pEngine != NULL)
    {
        DeleteALL(&pEngine);
        pEngine = NULL;
    }

    return 0;
}

void InsertFirst(struct node **pHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("memory allocation fail");
        return;
    }

    pNewNode->iData = iNo;

    pNewNode->pNext=*pHead;

    *pHead = pNewNode;

}
