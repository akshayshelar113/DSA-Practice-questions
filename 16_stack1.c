#include <stdio.h>

#define MAX 50

void Push(int *, int *, int);
int Pop(int *, int *);
void Display(const int *, int);
int IsStackFull(int);
int IsStackEmpty(int);

int main(void)
{
    int iPopedData;
    int iTop = -1;

    int Stack[MAX];

    Push(Stack, &iTop, 10);
    Push(Stack, &iTop, 20);
    Push(Stack, &iTop, 30);
    Push(Stack, &iTop, 40);
    Display(Stack, iTop);

    iPopedData = Pop(Stack, &iTop);
    if(iPopedData != -1)
    printf("\n\nPoped data is: %d\n",iPopedData);
    Display(Stack, iTop);

    return 0;
}

void Push(int *pStack, int *piTop, int iNo)
{
    if (IsStackFull(*piTop))
    {
        printf("\nStack overflow\n");
        return;
    }

    pStack[++(*piTop)] = iNo;
}

int IsStackFull(int iTop)
{
    if (iTop == MAX - 1)
        return 1;
    return 0;
}

void Display(const int *pStack, int iTop)
{
    int iCounter;

    for (iCounter = 0; iCounter <= iTop; iCounter++)
    {
        printf("%d\t", pStack[iCounter]);
    }
}

int Pop(int *pStack, int *iTop)
{
    if (IsStackEmpty(*iTop))
    {
        printf("\nStack is empty\n");
        return -1;
    }
    return pStack[(*iTop)--];
}

int IsStackEmpty(int iTop)
{
    if (iTop == -1)
        return 1;
    return 0;
}