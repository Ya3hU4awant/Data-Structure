
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert a node at the end
void insert() {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted successfully.\n");
}

// Delete a node from the beginning
void deleteNode() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display the list in forward direction
void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Forward List: NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Display the list in backward direction
void displayBackward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward List: NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete from beginning\n");
        printf("3. Display forward\n");
        printf("4. Display backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    // Free remaining nodes
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
