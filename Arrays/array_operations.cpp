//2415.....
#include <iostream>
using namespace std;

class Array {
private:
    int* arr;      // Pointer for dynamic array
    int size;      // Current number of elements
    int capacity;  // Maximum capacity (user-defined)

public:
    Array(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    ~Array() {
        delete[] arr;
    }

    void insertAtEnd(int value) {
        if (size >= capacity) {
            cout << "Array is full!\n";
            return;
        }
        arr[size++] = value;
    }

    void insertAtBeginning(int value) {
        if (size >= capacity) {
            cout << "Array is full!\n";
            return;
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    void insertAtPosition(int value, int pos) {
        if (size >= capacity) {
            cout << "Array is full!\n";
            return;
        }
        if (pos < 0 || pos > size) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
    }

    void deleteFromBeginning() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void deleteFromEnd() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        size--;
    }

    void deleteFromPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void search(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element found at index " << i << endl;
                return;
            }
        }
        cout << "Element not found.\n";
    }

    void update(int pos, int newValue) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";
            return;
        }
        arr[pos] = newValue;
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the size (capacity) of the array: ";
    cin >> capacity;

    Array a(capacity);
    int choice, value, position;

    do {
        cout << "\nArray Operations Menu:\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from End\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search\n";
        cout << "8. Update\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> value;
            a.insertAtEnd(value);
            break;
        case 2:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            a.insertAtBeginning(value);
            break;
        case 3:
            cout << "Enter value and position to insert: ";
            cin >> value >> position;
            a.insertAtPosition(value, position);
            break;
        case 4:
            a.deleteFromEnd();
            break;
        case 5:
            a.deleteFromBeginning();
            break;
        case 6:
            cout << "Enter position to delete from: ";
            cin >> position;
            a.deleteFromPosition(position);
            break;
        case 7:
            cout << "Enter element to search: ";
            cin >> value;
            a.search(value);
            break;
        case 8:
            cout << "Enter position and new value: ";
            cin >> position >> value;
            a.update(position, value);
            break;
        case 9:
            a.display();
            break;
        case 10:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 10);

    return 0;
}
