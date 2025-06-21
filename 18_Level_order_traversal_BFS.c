#include <stdio.h>
#include <malloc.h>
#define MAX 100

struct node
{
    struct node *pLchild;
    int iData;
    struct node *pRchild;
};
struct QueueNode
{
    struct node *pData;
    struct QueueNode *pNext;
};

void InsertNode(struct node **, int);
void Postorder(struct node *);
void LevelOrder(struct node *);
void Enqueue(struct QueueNode **, struct node *);
struct node *Dequeue(struct QueueNode **);
int IsQueueEmpty(struct QueueNode *);
int CountNodes(struct QueueNode *);

int main(void)
{
    struct node *pParent = NULL;

    InsertNode(&pParent, 100);
    InsertNode(&pParent, 150);
    InsertNode(&pParent, 90);
    InsertNode(&pParent, 120);
    InsertNode(&pParent, 80);
    InsertNode(&pParent, 50);
    InsertNode(&pParent, 140);
    InsertNode(&pParent, 160);

    printf("Postorder\n");
    Postorder(pParent);

    printf("\n\nLevel order\n");
    LevelOrder(pParent);

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
            printf("Duplicate data");
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
    if (NULL == pRoot)
        return;

    Postorder(pRoot->pLchild);
    Postorder(pRoot->pRchild);
    printf("%d\t", pRoot->iData);
}

void LevelOrder(struct node *pRoot)
{
    struct QueueNode *pQueue = NULL;
    struct node *pPtr = NULL;

    if (pRoot == NULL)
    {
        printf("tree is empty");
        return;
    }

    printf("\nIn Level Order before Enque call\n");
    Enqueue(&pQueue, pRoot);
    printf("\nIn Level Order after Enque call\n");

    while (!IsQueueEmpty(pQueue))
    {
        printf("\nIn Level Order In while before dequeue\n");
        pPtr = Dequeue(&pQueue);
        printf("\nIn Level Order In while after dequeue\n");
        printf("%d\t", pPtr->iData);

        if (pPtr->pLchild != NULL)
        {
            printf("\nIn Level Order In while in pPtr->pLchild != NULL before enqueue\n");
            Enqueue(&pQueue, pPtr->pLchild);
            printf("\nIn Level Order In while in pPtr->pLchild != NULL after enqueue\n");
        }

        if (pPtr->pRchild != NULL)
        {
            printf("\nIn Level Order In while in pPtr->pRchild != NULL before enqueue\n");
            Enqueue(&pQueue, pPtr->pRchild);
            printf("\nIn Level Order In while in pPtr->pRchild != NULL after enqueue\n");
        }
    }
}

void Enqueue(struct QueueNode **pProot, struct node *pNode)
{
    struct QueueNode *pNewNode = NULL;
    struct QueueNode *pTemp = NULL;

    pNewNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));

    if (NULL == pNewNode)
    {
        printf("Memory allocation failed");
        return;
    }
    printf("\nIn Enqueue\n");

    pNewNode->pData = pNode;
    pNewNode->pNext = NULL;

    if (NULL == *pProot)
    {
        printf("\nIn Enqueue in stack if pProot in empty\n");
        *pProot = pNewNode;
        return;
    }

    printf("\nIn Enqueue in stack if pProot in not empty\n");

    pTemp = *pProot;
    while (pTemp->pNext != NULL)
        pTemp = pTemp->pNext;

    pTemp->pNext = pNewNode;
}

struct node *Dequeue(struct QueueNode **pRoot)
{
    struct node *pDequed = NULL;
    struct QueueNode *pTemp = NULL;

    if (IsQueueEmpty(*pRoot))
    {
        printf("Queue is empty");
        return NULL;
    }

    printf("\nIn Dequeue in stack\n");

    pTemp = *pRoot;

    *pRoot = pTemp->pNext;

    pDequed = pTemp->pData;

    free(pTemp);

    return pDequed;
}

int IsQueueFull(struct QueueNode *pRoot)
{
    if (CountNodes(pRoot) == MAX)
        return 1;
    return 0;
}

int CountNodes(struct QueueNode *pRoot)
{
    int iCount = 0;
    while (pRoot != NULL)
    {
        iCount++;
        pRoot = pRoot->pNext;
    }

    return iCount;
}

int IsQueueEmpty(struct QueueNode *pRoot)
{
    if (NULL == pRoot)
        return 1;
    return 0;
}