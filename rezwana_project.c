#include <stdio.h>

int main() {
    int maxSize;
    printf("Enter the size of the array: ");
    scanf("%d", &maxSize);
    int array[maxSize];
    int size = 0, option, num, idx, i, exists;

    while (1) {
        printf("\n1. Insert\n2. Update\n3. Delete\n4. Search\n5. Min/Max\n6. Exit\nChoose: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (size >= maxSize) {
                    printf("Array full!\n");
                    break;
                }
                printf("Enter number: ");
                scanf("%d", &num);
                printf("Insert at index? (1=Yes, 0=No): ");
                int insertChoice;
                scanf("%d", &insertChoice);

                if (insertChoice == 1) {
                    printf("Index (0 to %d): ", size);
                    scanf("%d", &idx);
                    if (idx >= 0 && idx <= size) {
                        for (i = size; i > idx; i--) array[i] = array[i - 1];
                        array[idx] = num;
                        size++;
                        printf("Inserted at %d.\n", idx);
                    } else {
                        printf("Invalid index.\n");
                    }
                } else {
                    array[size++] = num;
                    printf("Inserted at end.\n");
                }
                break;

            case 2:
                printf("Update index (0 to %d): ", size - 1);
                scanf("%d", &idx);
                if (idx >= 0 && idx < size) {
                    printf("New value: ");
                    scanf("%d", &num);
                    array[idx] = num;
                    printf("Updated.\n");
                } else {
                    printf("Invalid index.\n");
                }
                break;

            case 3:
                printf("Delete index (0 to %d): ", size - 1);
                scanf("%d", &idx);
                if (idx >= 0 && idx < size) {
                    for (i = idx; i < size - 1; i++) array[i] = array[i + 1];
                    size--;
                    printf("Deleted.\n");
                } else {
                    printf("Invalid index.\n");
                }
                break;

            case 4:
                printf("Search number: ");
                scanf("%d", &num);
                exists = 0;
                for (i = 0; i < size; i++) {
                    if (array[i] == num) {
                        printf("Found at index %d\n", i);
                        exists = 1;
                        break;
                    }
                }
                if (!exists) printf("Not found.\n");
                break;

            case 5:
                if (size == 0) {
                    printf("Array empty.\n");
                } else {
                    int max = array[0], min = array[0];
                    for (i = 1; i < size; i++) {
                        if (array[i] > max) max = array[i];
                        if (array[i] < min) min = array[i];
                    }
                    printf("Max: %d, Min: %d\n", max, min);
                }
                break;

            case 6:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }

        printf("Current array: ");
        for (i = 0; i < size; i++) printf("%d ", array[i]);
        printf("\n");
    }
    return 0;
}
