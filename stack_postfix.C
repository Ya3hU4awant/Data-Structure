#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push element into stack
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

// Pop element from stack
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    int i, op1, op2, result;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        // If operand, push it into stack
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        // If operator, pop two operands
        else
        {
            op2 = pop();
            op1 = pop();

            switch (postfix[i])
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;

                case '%':
                    result = op1 % op2;
                    break;

                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}

// The program scans the postfix expression, pushes operands onto the stack, and whenever it finds an operator, 
// it pops two operands, performs the operation, and pushes the result back. The final value in the stack is the answer.