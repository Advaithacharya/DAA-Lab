#include <stdio.h>

#define MAX_ITEMS 100

int getNextItem(double weight[], double value[], double ratio[], int nItems);

double computeMaxValue(double W, double weight[], double value[], double ratio[], int nItems) {
    double cW = 0;
    double cV = 0;
    printf("\nItems included are: ");
    
    while (cW < W) {
        int item = getNextItem(weight, value, ratio, nItems);
        if (item == -1) {  // No more items to select
            break;
        }
        
        printf("%d ", item + 1);
        
        if (cW + weight[item] <= W) {
            cW += weight[item];
            cV += value[item];
            ratio[item] = 0;  // Mark as used
        } else {
            cV += ratio[item] * (W - cW);
            cW = W;
            break;
        }
    }
    
    return cV;
}

int getNextItem(double weight[], double value[], double ratio[], int nItems) {
    double highest = 0;
    int index = -1;
    for (int i = 0; i < nItems; i++) {
        if (ratio[i] > highest) {
            highest = ratio[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int nItems;
    double W;
    double weight[MAX_ITEMS], value[MAX_ITEMS], ratio[MAX_ITEMS];
    
    printf("Enter the number of items: ");
    scanf("%d", &nItems);

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < nItems; i++) {
        scanf("%lf", &weight[i]);
    }

    printf("Enter the values/profits of the items:\n");
    for (int i = 0; i < nItems; i++) {
        scanf("%lf", &value[i]);
    }

    for (int i = 0; i < nItems; i++) {
        ratio[i] = value[i] / weight[i];
    }

    printf("Enter the knapsack capacity: ");
    scanf("%lf", &W);

    double maxValue = computeMaxValue(W, weight, value, ratio, nItems);
    printf("\nThe maximum value in the knapsack of capacity %.2f is %.2f\n", W, maxValue);
    
    return 0;
}
