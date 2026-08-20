#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Insert an element into the circular queue */
void enqueue(int value)
{
    // Queue is full
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is Full!\n");
        return;
    }

    // First element
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        // Move rear circularly
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted\n", value);
}

/* Delete an element from the circular queue */
void dequeue()
{
    int value;

    // Queue is empty
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }

    value = queue[front];

    // Only one element is present
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        // Move front circularly
        front = (front + 1) % MAX;
    }

    printf("%d deleted\n", value);
}

/* Display the queue */
void display()
{
    int i;

    // Queue is empty
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Circular Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        // Stop after reaching rear
        if (i == rear)
            break;

        // Move circularly
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Circular Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}