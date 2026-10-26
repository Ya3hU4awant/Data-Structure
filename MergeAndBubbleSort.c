
#include <stdio.h>

// Merge function
void merge(int a[], int low, int mid, int high) {
    int temp[1000];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

// Merge Sort function
void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

// Bubble Sort function
void bubbleSort(int a[], int n) {
    int i, j, temp, swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;

        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

// Display array
void display(int a[], int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

// Main function
int main() {
    int a[1000], b[1000], n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 1000) {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    do {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Merge Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Copy original array before sorting
        for (i = 0; i < n; i++)
            b[i] = a[i];

        switch (choice) {
            case 1:
                mergeSort(b, 0, n - 1);
                printf("Sorted array using Merge Sort: ");
                display(b, n);
                break;

            case 2:
                bubbleSort(b, n);
                printf("Sorted array using Bubble Sort: ");
                display(b, n);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
