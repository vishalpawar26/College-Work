#include <iostream>
using namespace std;

void Print(int processSize[], int allocation[]) {
    cout << "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < 4; i++) {
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void FirstFit(int blockSize[], int processSize[], int allocation[]) {
    for(int i = 0; i < 4; i++) {
        int firstInx = -1;
        for (int j = 0; j < 5; j++) {
            if(blockSize[j] >= processSize[i]) {
                if (firstInx == -1)
                    firstInx = j;
            }
        }
        if (firstInx != -1) {
            allocation[i] = firstInx;
            blockSize[firstInx] -= processSize[i];
        }
    }
    cout << "\nFirst-Fit Algorithm" << endl;
    Print(processSize, allocation);
}

void BestFit(int blockSize[], int processSize[], int allocation[]) {
    for (int i = 0; i < 4; i++) {
        int bestIdx = -1;
        for (int j = 0; j < 5; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
 
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    cout << "\nBest-Fit Algorithm" << endl;
    Print(processSize, allocation);
}

void WorstFit(int blockSize[], int processSize[], int allocation[]) {
    for (int i = 0; i < 4; i++) {
        int worstIdx = -1;
        for (int j = 0; j < 5; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1)
                    worstIdx = j;
                else if (blockSize[worstIdx] < blockSize[j])
                    worstIdx = j;
            }
        }
 
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    cout << "\nWorst-Fit Algorithm" << endl;
    Print(processSize, allocation);
}

int main() {
    int blockSize[5] = {100, 500, 200, 300, 600};
    int processSize[4] = {212, 417, 112, 426};
    int allocation[4] = {-1, -1, -1, -1};

    int choice;
    cout << "1) First Fit \n2) Best Fit \n3) Worst Fit \nEnter Your Choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            FirstFit(blockSize, processSize, allocation);
            break;
        case 2:
            BestFit(blockSize, processSize, allocation);
            break;
        case 3:
            WorstFit(blockSize, processSize, allocation);
            break;
        default:
            cout << "Please enter a valid choice!" << endl;
    }
    return 0;
}