#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char **arr = (char **)malloc(n * sizeof(char *));
    char temp[200];

    printf("Enter strings:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", temp);
        arr[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(arr[i], temp);
    }

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }

    printf("\nSorted Strings:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}

