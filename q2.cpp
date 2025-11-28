#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    
    arr = (int *)realloc(arr, 2 * n * sizeof(int));
    printf("\nArray size doubled. Enter %d new elements:\n", n);

    for (int i = n; i < 2 * n; i++)
        scanf("%d", &arr[i]);

    printf("\nUpdated Array:\n");
    for (int i = 0; i < 2 * n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}

