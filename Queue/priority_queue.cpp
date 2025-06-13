// 2415..
#include <iostream>
using namespace std;

const int MAX = 100;

struct Element {
    int data;
    int priority;
};

class PriorityQueue {
    Element queue[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    void insert(int data, int priority) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }

        int i;
        // Shift elements with lower priority
        for (i = size - 1; i >= 0 && queue[i].priority < priority; i--) {
            queue[i + 1] = queue[i];
        }

        queue[i + 1].data = data;
        queue[i + 1].priority = priority;
        size++;

        cout << "Inserted: " << data << " with priority " << priority << endl;
    }

    void deleteHighestPriority() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Deleted: " << queue[0].data << " with priority " << queue[0].priority << endl;

        for (int i = 1; i < size; i++) {
            queue[i - 1] = queue[i];
        }

        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nCurrent Queue:\n";
        for (int i = 0; i < size; i++) {
            cout << "Data: " << queue[i].data << " | Priority: " << queue[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice, data, priority;

    while (true) {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert\n2. Delete Highest Priority\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter priority: ";
                cin >> priority;
                pq.insert(data, priority);
                break;
            case 2:
                pq.deleteHighestPriority();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
