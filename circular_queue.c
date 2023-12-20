#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    int length = sizeof(myArray) / sizeof(myArray[0]);

    // Call the function and pass the array
    printf("%d\n",length);
    printArray(myArray, length);

    return 0;
}
