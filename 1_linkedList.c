#include<stdio.h>

struct node{
    int iNo;
    struct node *next;
} obj;

int main(void)
{
    int *pPtr=NULL;

    pPtr = (int *) malloc (sizeof(obj));

    free(pPtr);
    pPtr=NULL;

    return 0;
}