#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push character into stack
void push(char ch)
{
    stack[++top] = ch;
}

// Pop character from stack
char pop()
{
    return stack[top--];
}

// Return priority of operators
int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/' || ch == '%')
        return 2;

    if (ch == '^')
        return 3;

    return 0;
}

// Convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // If operand, add it directly to postfix
        if (isdigit(ch))
        {
            postfix[j++] = ch;
        }

        // If opening bracket, push it
        else if (ch == '(')
        {
            push(ch);
        }

        // If closing bracket, pop until '('
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            pop(); // Remove '('
        }

        // If operator, handle according to priority
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   priority(stack[top]) >= priority(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    int values[MAX];
    int valueTop = -1;
    int i, op1, op2, result;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        // Push operands
        if (isdigit(postfix[i]))
        {
            values[++valueTop] = postfix[i] - '0';
        }

        // Perform operation
        else
        {
            op2 = values[valueTop--];
            op1 = values[valueTop--];

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
            }

            // Push result back
            values[++valueTop] = result;
        }
    }

    return values[valueTop];
}

int main()
{
    char infix[MAX], postfix[MAX];

    // Take normal expression from user
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Display postfix expression
    printf("Postfix expression: %s\n", postfix);

    // Evaluate postfix expression
    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}
