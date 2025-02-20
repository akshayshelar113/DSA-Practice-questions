#include <stdio.h>
#include "15_stack.c"
#define MAX 50

Display(Stack, iTop);
void InfixToPostfix(const char *, char *);

int main(void)
{
    char Infix[MAX] = {0};
    char Postfix[MAX] = {0};

    printf("Enter expression to  solve\n");
    gets(Infix);

    printf("Entered expression is: %s\n", Infix);

    InfixToPostfix(Infix, Postfix);
    printf("%s", Postfix);

    return 0;
}

void InfixToPostfix(const char *pInfix, char *pPostfix)
{
    int iCounter1;
    int iCounter2;
    char lSymbol;
    int ipriority;

    extern int g_iTop;
    extern int g_Stack[STACK_MAX];

    if (!IsExpresionValid(pInfix))
    {
        printf("Invalid expression");
        return;
    }

    iCounter2 = 0;

    for (iCounter1 = 0; pInfix[iCounter1] != '\0'; iCounter1++)
    {
        lSymbol = pInfix[iCounter1];

        if (IsSpace(lSymbol))
            continue;

        if ((ipriority = IsOperator(lSymbol)) != 0)
        {
            while (!IsEmpty() && IsOperator(g_Stack[g_iTop]) >= ipriority)
                pPostfix[iCounter2++] = Pop();

            Push(lSymbol);
        }
        else if (lSymbol == '(')
            Push(lSymbol);
        else if (lSymbol == ')')
        {
            while ((lSymbol = Pop()) != '(')
                pPostfix[iCounter2++] = lSymbol;
        }
        else
        {
            pPostfix[iCounter2++] = '[';

            while (1)
            {
                pPostfix[iCounter2++] = lSymbol;
                lSymbol = pInfix[++iCounter1];
                if (IsSpace(lSymbol) || IsOperator(lSymbol) || lSymbol == '\0' || lSymbol == ')')
                    break;
            }
            pPostfix[iCounter2++] = ']';
            iCounter1--;
        }
    }
    while (!IsEmpty())
        pPostfix[iCounter2++] = Pop();
    pPostfix[iCounter2] = '\0';
}

int IsExpresionValid(const char *pInfix)
{
    int iCounter;
    int tempTop = -1;
    char tempStack[STACK_MAX];

    for (iCounter = 0; pInfix[iCounter] != '\0'; iCounter++)
    {
        if (pInfix[iCounter] == '(')

            tempStack[++tempTop] = '(';

        else if (pInfix[iCounter] == ')')
        {
            if (tempTop == -1)
                return 0;

            tempTop--;
        }
    }
    return (tempTop == -1);
}

int IsOperator(char chsymbol)
{
    switch (chsymbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;

    default:
        return 0;
    }
}

int IsSpace(char chSymbol)
{
    if (chSymbol == ' ' || chSymbol == '\t')
        return 1;
    return 0;
}