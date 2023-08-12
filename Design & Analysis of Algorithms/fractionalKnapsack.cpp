#include <iostream>
using namespace std;

void sortArray(float arr1[], float arr2[], float arr3[], int size, int choice) {
    int i, j, min_idx;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (choice == 1 || choice == 2) {
                if (arr1[j] > arr1[min_idx])
                    min_idx = j;
            }
            else {
                if (arr1[j] < arr1[min_idx])
                    min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr1[min_idx], arr1[i]);
            swap(arr2[min_idx], arr2[i]);
            swap(arr3[min_idx], arr3[i]);
        }
    }
}

int fractionalKnapsack(float weight[], float value[], int w, int size) {
    int totalWeight = 0;
    int profit = 0;
    float x[size];
    for(int i = 0; i < size; i++) {
        if (totalWeight + weight[i] <= w) {
            x[i] = 1;
            totalWeight += weight[i];
        }
        else {
            x[i] = (w - totalWeight) / weight[i];
            totalWeight = w;
        }
        profit += x[i] * value[i];
    }
    return profit;
}

int main() {
    float weight[] = {10, 20, 30, 40, 50};
    float value[] = {20, 30, 66, 40, 60};
    int size = sizeof(value) / sizeof(value[0]);
    
    float valueByWeight[size];
    for (int i = 0; i < size; i++) {
        valueByWeight[i] = value[i] / weight[i];
    }
    
    cout << "Enter 1 for decreasing v/w method" << endl;
    cout << "Enter 2 for decreasing value method" << endl;
    cout << "Enter 3 for increasing weight method" << endl;

    while (true) {
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            sortArray(valueByWeight, weight, value, size, choice);
            cout << "Profit by Decreasing Value / Weight: " << fractionalKnapsack(weight, value, 100, size) << endl;
            break;

        case 2:
            sortArray(value, weight, valueByWeight, size, choice);
            cout << "Profit by Decreasing Value: " << fractionalKnapsack(weight, value, 100, size) << endl;
            break;

        case 3:
            sortArray(weight, value, valueByWeight, size, choice);
            cout << "Profit by Increasing Weight: " << fractionalKnapsack(weight, value, 100, size) << endl;
            break;

        default:
            cout << "Enter a valid choice!" << endl;
            break;
        }
    }

    return 0;
}
