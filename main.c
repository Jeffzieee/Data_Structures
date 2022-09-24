#include <stdio.h>

void main() {
    int i = 0, n;
    int a[10];
    do {
        printf("\nEnter array size: ");
        scanf("%d", &n);
        if (n > 10)
            printf("\nArray out of Bounds");
    } while (n > 10);

    //Array Insertion
    for (i = 0; i < n; i++) {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    //Display Contents
    for (i = 0; i < n; i++) {
        printf("\nElement %d: %d", i + 1, a[i]);
    }
}