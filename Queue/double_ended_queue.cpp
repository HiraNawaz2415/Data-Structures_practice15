// 2415.
#include <iostream>
using namespace std;

class Deque {
    int* arr;
    int front, rear, size;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Overflow: Cannot insert at front\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = key;
        cout << key << " inserted at front.\n";
    }

    void insertRear(int key) {
        if (isFull()) {
            cout << "Overflow: Cannot insert at rear\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = key;
        cout << key << " inserted at rear.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow: Cannot delete from front\n";
            return;
        }
        cout << arr[front] << " deleted from front.\n";
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow: Cannot delete from rear\n";
            return;
        }
        cout << arr[rear] << " deleted from rear.\n";
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void getRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Rear element: " << arr[rear] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque contents: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of deque: ";
    cin >> size;

    Deque dq(size);

    while (true) {
        cout << "\n--- Deque Menu ---\n";
        cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Get Front\n6. Get Rear\n7. Display\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dq.insertFront(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            dq.insertRear(value);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.getFront();
            break;
        case 6:
            dq.getRear();
            break;
        case 7:
            dq.display();
            break;
        case 8:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
