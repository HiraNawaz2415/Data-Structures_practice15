// 2415..
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Display the list
void display(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    while (head != nullptr) {
        cout << head->data << " → ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Sort the list in ascending or descending order
void sortList(Node* head, bool ascending = true) {
    if (!head) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            bool condition = ascending ? (ptr1->data > ptr1->next->data)
                                       : (ptr1->data < ptr1->next->data);
            if (condition) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "\n===== Linked List Menu =====\n";
        cout << "1. Insert Node\n";
        cout << "2. Display List\n";
        cout << "3. Sort List in Ascending Order\n";
        cout << "4. Sort List in Descending Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertEnd(head, value);
            break;

        case 2:
            cout << "Current List: ";
            display(head);
            break;

        case 3:
            sortList(head, true);
            cout << "List sorted in Ascending order.\n";
            break;

        case 4:
            sortList(head, false);
            cout << "List sorted in Descending order.\n";
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
