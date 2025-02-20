#include <stdio.h>
#define MAX 5

void EnQueue(int *, int);
int DeQueue(int *);
int IsQueueFull(void);
int IsQueueEmpty(void);
void Display(const int *);

int iFront = 0;
int iRear = -1;

int main(void)
{
    int DeQuedData;
    int Queue[MAX];

    EnQueue(Queue, 10);
    EnQueue(Queue, 20);
    EnQueue(Queue, 30);
    EnQueue(Queue, 40);
    EnQueue(Queue, 50);
    printf("Queue is\n");
    Display(Queue);

    DeQuedData = DeQueue(Queue);
    if (DeQuedData != -1)
        printf("\n\nDequed data is: %d", DeQuedData);
    printf("\nQueue after DeQueue is\n");
    Display(Queue);

    printf("\nEntering data after dequed one data\n");
    EnQueue(Queue, 60);
    Display(Queue);

    EnQueue(Queue, 70);

    return 0;
}

void EnQueue(int *pQueue, int iNo)
{
    if (IsQueueFull())
    {
        printf("\nQueue is full\n");
        return;
    }
    if (iRear == MAX -1)
        iRear = 0;
    else
        ++iRear;

    pQueue[iRear] = iNo;
}

int DeQueue(int *pQueue)
{
    int iDeQuedData;
    if (IsQueueEmpty())
    {
        printf("\nQueue is empty\n");
        return -1;
    }

    iDeQuedData = pQueue[iFront];

    if (iRear == iFront)
    {
        iRear = -1;
        iFront = 0;
    }
    else if (iFront == MAX - 1)
        iFront = 0;
    else
        ++iFront;

    return iDeQuedData;
}

int IsQueueEmpty(void)
{
    if (iRear == -1)
        return 1;
    return 0;
}

int IsQueueFull(void)
{
    if ((iFront == 0 && iRear == MAX - 1) || (iRear == iFront - 1 && iRear != -1))
        return 1;
    return 0;
}

void Display(const int *pQueue)
{
    int iCounter;

    if (iRear == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    if (iRear < iFront)
    {
        for (iCounter = iFront; iCounter <= MAX - 1; iCounter++)
            printf("%d\t", pQueue[iCounter]);

        for (iCounter = 0; iCounter <= iRear; iCounter++)
            printf("%d\t", pQueue[iCounter]);
    }

    else
    {
        for (iCounter = iFront; iCounter <= iRear; iCounter++)
            printf("%d\t", pQueue[iCounter]);
    }
}
