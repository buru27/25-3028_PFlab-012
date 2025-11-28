#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    float *sales = (float *)malloc(n * sizeof(float));

    printf("Enter sales for %d days:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &sales[i]);

    float total = 0;
    for (int i = 0; i < n; i++)
        total += sales[i];

    printf("\nInitial Total Sales = %.2f\n", total);

    
    int extra;
    printf("\nHow many more days to add? ");
    scanf("%d", &extra);

    sales = (float *)realloc(sales, (n + extra) * sizeof(float));

    printf("Enter sales for the new days:\n");
    for (int i = n; i < n + extra; i++)
        scanf("%f", &sales[i]);

    
    total = 0;
    for (int i = 0; i < n + extra; i++)
        total += sales[i];

    printf("\nUpdated Total Sales = %.2f\n", total);

    free(sales);
    return 0;
}

