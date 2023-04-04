#include<iostream>
using namespace std;

class BoundedBuffer {
    int empty = 5, mutex = 1, full = 0;

    void wait(int &s)  {
        while(s <= 0);
        s--;
    }

    void signal(int &s) {
        s++;
    }

    public:
        void Producer();
        void Consumer();
};

void BoundedBuffer :: Producer() {
    if(full < 5 && mutex == 1) {
        wait(empty);
        wait(mutex);
        cout << "Producer produced an item" << endl;
        signal(mutex);
        signal(full);
        cout << "Empty: " << empty << " | " << "Full: " << full << endl;
    }
    else cout << "Buffer is full!" << endl;
}

void BoundedBuffer :: Consumer() {
    if(full > 0 && mutex == 1) {
        wait(full);
        wait(mutex);
        cout << "Consumer consumed an item" << endl;
        signal(mutex);
        signal(empty);
        cout << "Empty: " << empty << " | " << "Full: " << full << endl;
    }
    else cout << "Buffer is empty!" << endl;
}

int main() {
    BoundedBuffer obj;

    while(true) {
        int choice;
        cout << "1) Produce \n2) Consume" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            obj.Producer();
            break;
        case 2:
            obj.Consumer();
            break;
        default:
            cout << "Please enter a valid choice!" << endl;
            break;
        }
    }
    return 0;
}