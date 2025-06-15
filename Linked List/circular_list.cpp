// 2415..
// Circular Linked List with All Operations
#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

void insertAtBeginning(CNode*& head, int val) {
    CNode* newNode = new CNode{val, nullptr};
    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertAtEnd(CNode*& head, int val) {
    CNode* newNode = new CNode{val, nullptr};
    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void deleteNode(CNode*& head, int val) {
    if (!head) return;
    if (head->data == val && head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    CNode* curr = head;
    CNode* prev = nullptr;
    do {
        if (curr->data == val) {
            if (prev) prev->next = curr->next;
            else {
                CNode* temp = head;
                while (temp->next != head)
                    temp = temp->next;
                temp->next = head->next;
                head = head->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}

void display(CNode* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    CNode* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " → ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)\n";
}

int main() {
    CNode* head = nullptr;
    int choice, val;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete a Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtBeginning(head, val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(head, val);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteNode(head, val);
                break;
            case 4:
                display(head);
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
