#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int );

int main(void)
{
    struct node *pFirst=NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    

    return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));
    printf("%d\n",pNewNode);

    if(NULL == pNewNode )
    {
        printf("Memory allocation fail");
        return ;
    }

    // printf("1 %d\n",(*ppHead)->pNext);  

    pNewNode->iData=iNo;
    // printf("2 %d\n",(*ppHead)->pNext);  

    if(NULL == *ppHead)
    {
        pNewNode->pNext=NULL;
        // printf("3 %d\n",(*ppHead)->pNext);  
        *ppHead = pNewNode;
        // printf("%d");
        printf("3: %d\n",(*ppHead)->pNext);
        return;
    }

    pNewNode->pNext=*ppHead;
    *ppHead = pNewNode;
    printf("4:  %d\n",(*ppHead)->pNext);
}