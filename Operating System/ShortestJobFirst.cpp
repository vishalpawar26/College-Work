#include <iostream>
using namespace std;

int main() {
    string process[5] = {"p1", "p2", "p3", "p4", "p5"};
    int burstTime[5] = {4, 3, 7, 1, 2};
    int waitingTime[5] = {0, 0, 0, 0, 0};
    int turnAroundTime[5] = {0, 0, 0, 0, 0};

    float totalWaitingTime = 0;
    float totalTurnAroundTime = 0;
    float avgWaitingTime = 0;
    float avgTurnAroundTime = 0;

    // Shorting of burst time
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            if (burstTime[i] > burstTime[j]) {
                int temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                string tempString = process[i];
                process[i] = process[j];
                process[j] = tempString;
            }
        }
    }

    // Calculating waiting time
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            waitingTime[i] += burstTime[j];
        }

        totalWaitingTime += waitingTime[i];
    }
    avgWaitingTime = totalWaitingTime / 5;

    // Calculating turn around time 
    for (int i = 0; i < 5; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];

        totalTurnAroundTime += turnAroundTime[i];
    }
    avgTurnAroundTime = totalTurnAroundTime / 5;

    cout << "P\t" << "BT\t" << "WT\t" << "TAT" << endl;
    for (int i = 0; i < 5; i++) {
        cout << process[i] << "\t" << burstTime[i] << "\t" << waitingTime[i] << "\t" << turnAroundTime[i] << endl;
    }
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turn Around Time: " << avgTurnAroundTime << endl;
    return 0;
}