#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int can_place(int c[], int r) {
    for (int i = 0; i < r; i++) {
        if (c[i] == c[r] || abs(c[i] - c[r]) == abs(i - r))
            return 0;
    }
    return 1;
}

void display(int c[], int n) {
    char cb[10][10];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cb[i][j] = '-';

    for (int i = 0; i < n; i++)
        cb[i][c[i]] = 'Q';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c ", cb[i][j]);
        printf("\n");
    }
    printf("\n");
}

void n_queens(int n) {
    int c[MAX];
    int r = 0;

    for (int i = 0; i < n; i++)
        c[i] = -1;

    while (r >= 0) {
        c[r]++;
        while (c[r] < n && !can_place(c, r))
            c[r]++;

        if (c[r] < n) {
            if (r == n - 1) {
                display(c, n);
            } else {
                r++;
                c[r] = -1;
            }
        } else {
            r--;  // Backtrack
        }
    }
}

int main() {
    int n;

    printf("Enter the number of queens: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 10) {
        printf("Invalid input. Please enter a number between 1 and 10.\n");
        return 1;
    }

    printf("\nSolutions for %d-Queens problem:\n\n", n);
    n_queens(n);

    return 0;
}
