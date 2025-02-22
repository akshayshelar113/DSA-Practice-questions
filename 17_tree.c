#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pLchild;
    int iData;
    struct node *pRchild;
};

void InsertNode(struct node **, int);
void Postorder(struct node *);

int main(void)
{
    struct node *pParent = NULL;

    InsertNode(&pParent, 100);
    InsertNode(&pParent, 20);
    InsertNode(&pParent, 300);
    InsertNode(&pParent, 40);

    Postorder(pParent);

    return 0;
}

void InsertNode(struct node **ppRoot, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pPtr = NULL;
    struct node *pParent = NULL;

    pPtr = *ppRoot;

    while (pPtr != NULL)
    {
        pParent = pPtr;

        if (iNo < pPtr->iData)
            pPtr = pPtr->pLchild;
        else if (iNo > pPtr->iData)
            pPtr = pPtr->pRchild;
        else
        {
            printf("Dublicate data");
            return;
        }
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pLchild = pNewNode->pRchild = NULL;

    if (NULL == pParent)
        *ppRoot = pNewNode;

    else if (iNo < pParent->iData)
        pParent->pLchild = pNewNode;
    else
    pParent->pRchild = pNewNode;
}

void Postorder(struct node *pRoot)
{
    if(NULL == pRoot)
    return;

    Postorder(pRoot->pLchild);
    Postorder(pRoot->pRchild);
    printf("%d\t",pRoot->iData);
}