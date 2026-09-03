#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert at start
void insertStart(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    printf("Node inserted at start.\n");
}

// Insert at end
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("Node inserted at end.\n");
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Node inserted at end.\n");
}

// Insert at a given position
void insertPosition(struct Node **head, int value, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertStart(head, value);
        return;
    }

    struct Node *temp = *head;

    // Move to node before the required position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", position);
}

// Delete from start
void deleteStart(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    free(temp);

    printf("Node deleted from start.\n");
}

// Delete from end
void deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    struct Node *temp = *head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Node deleted from end.\n");
}

// Delete from a given position
void deletePosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteStart(head);
        return;
    }

    struct Node *temp = *head;

    // Move to node before the required position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    free(deleteNode);

    printf("Node deleted from position %d.\n", position);
}

// Display the list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    struct Node *head = NULL;

    int choice, value, position;

    while (1) {
        printf("\n========== SINGLY LINKED LIST ==========\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Start\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("=========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertStart(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                insertEnd(&head, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &position);

                insertPosition(&head, value, position);
                break;

            case 4:
                deleteStart(&head);
                break;

            case 5:
                deleteEnd(&head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);

                deletePosition(&head, position);
                break;

            case 7:
                display(head);
                break;

            case 8:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
