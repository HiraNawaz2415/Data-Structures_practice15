// 2415...
#include <iostream>
using namespace std;

// Doubly Linked List Node
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Insert at the beginning
void insertBeginning(DNode*& head, int value) {
    DNode* newNode = new DNode{value, nullptr, head};
    if (head != nullptr) head->prev = newNode;
    head = newNode;
}

// Insert at the end
void insertEnd(DNode*& head, int value) {
    DNode* newNode = new DNode{value, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a specific position
void insertAtPosition(DNode*& head, int value, int pos) {
    if (pos == 1) {
        insertBeginning(head, value);
        return;
    }
    DNode* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; ++i)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of bounds.\n";
        return;
    }

    DNode* newNode = new DNode{value, temp, temp->next};
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete a node by value
void deleteNode(DNode*& head, int value) {
    if (head == nullptr) return;
    DNode* temp = head;

    if (temp->data == value) {
        head = temp->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
    }

    while (temp && temp->data != value)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Value not found.\n";
        return;
    }

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    delete temp;
}

// Search for a value
bool search(DNode* head, int value) {
    DNode* temp = head;
    while (temp) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

// Reverse the doubly linked list
void reverseList(DNode*& head) {
    DNode *current = head, *temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) head = temp->prev;
}

// Display the list
void display(DNode* head) {
    cout << "Doubly Linked List: ";
    while (head != nullptr) {
        cout << head->data << " ⇄ ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    DNode* head = nullptr;
    int choice, value, position;

    do {
        cout << "\n===== Doubly Linked List Menu =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete a Node\n";
        cout << "5. Search a Value\n";
        cout << "6. Reverse the List\n";
        cout << "7. Display the List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(head, value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertAtPosition(head, value, position);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (search(head, value) ? "Found\n" : "Not found\n");
                break;
            case 6:
                reverseList(head);
                cout << "List reversed.\n";
                break;
            case 7:
                display(head);
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 8);

    return 0;
}
