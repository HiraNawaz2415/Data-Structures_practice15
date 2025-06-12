// 2415..
#include <iostream>
using namespace std;

class Array {
private:
    int* arr;
    int size;
    int capacity;

public:
    // Constructor to initialize array with given capacity
    Array(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Destructor
    ~Array() {
        delete[] arr;
    }

    // ================== INSERTION ==================
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
        if (pos < 0 || pos > size || size >= capacity) {
            cout << "Invalid position or array full.\n";
            return;
        }
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
    }

    // ================== DELETION ==================
    void deleteFromBeginning() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void deleteFromEnd() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        size--;
    }

    void deleteFromPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // ================== SEARCHING ==================
    void search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Element found at index " << i << endl;
                return;
            }
        }
        cout << "Element not found.\n";
    }

    // ================== SORTING ==================
    void sortArray() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Array sorted successfully.\n";
    }

    // ================== DISPLAY ==================
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

// ================== MAIN FUNCTION ==================
int main() {
    int capacity;
    cout << "Enter array capacity: ";
    cin >> capacity;

    Array arr(capacity);
    int choice, value, pos;

    do {
        cout << "\n----- Array Operation Menu -----\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from End\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search\n";
        cout << "8. Sort Array\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            arr.insertAtEnd(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            arr.insertAtBeginning(value);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            arr.insertAtPosition(value, pos);
            break;
        case 4:
            arr.deleteFromEnd();
            break;
        case 5:
            arr.deleteFromBeginning();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> pos;
            arr.deleteFromPosition(pos);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            arr.search(value);
            break;
        case 8:
            arr.sortArray();
            break;
        case 9:
            arr.display();
            break;
        case 10:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    return 0;
}
