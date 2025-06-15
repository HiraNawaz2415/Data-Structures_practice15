//2415....
#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (rear==size-1) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        else
        {
        arr[rear] = value;
        size++;
        cout << value << " enqueued to queue.\n";
        }
    }

    void dequeue() {
        if ((front==-1)&&(rear==-1)) {
            cout << "Queue Underflow! No element to remove.\n";
            return;
        }
        else if(front==rear)
        {
            front=rear-1;
            size--;
        }
        else
        {
        cout << arr[front] << " dequeued from queue.\n";
        front++;
        size--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    Queue q(size);
    int choice, value;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front Element)\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
