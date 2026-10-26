
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Insert a node at the end
void insert() {
    struct Node *newNode;
    
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("Node inserted successfully.\n");
}

// Delete a node from the beginning
void deleteNode() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = last->next;

    if (last == temp) {
        last = NULL;
    } else {
        last->next = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display the circular linked list
void display() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to start)\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete from beginning\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    // Free remaining nodes
    while (last != NULL) {
        deleteNode();
    }

    
    return 0;
    
}
