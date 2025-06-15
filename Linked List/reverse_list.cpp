// 2415..
#include <iostream>
using namespace std;

// Node structure
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

// Display list
void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " → ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Reverse the linked list
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;     // Store next
        current->next = prev;     // Reverse current's pointer
        prev = current;           // Move prev to current
        current = next;           // Move to next node
    }
    head = prev;  // New head
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cout << "Enter value for node " << i << ": ";
        cin >> value;
        insertEnd(head, value);
    }

    cout << "\nOriginal Linked List:\n";
    display(head);

    reverseList(head);

    cout << "\nReversed Linked List:\n";
    display(head);

    return 0;
}
