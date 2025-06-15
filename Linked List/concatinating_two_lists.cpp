#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display list
void display(Node* head) {
    while (head) {
        cout << head->data << " → ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Function to concatenate two lists
void concatenate(Node*& head1, Node* head2) {
    if (!head1) {
        head1 = head2;
        return;
    }
    Node* temp = head1;
    while (temp->next)
        temp = temp->next;
    temp->next = head2;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    int n1, n2, val;

    // Input for List 1
    cout << "Enter number of nodes in List 1: ";
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        insertEnd(list1, val);
    }

    // Input for List 2
    cout << "\nEnter number of nodes in List 2: ";
    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        insertEnd(list2, val);
    }

    // Display both lists before concatenation
    cout << "\nList 1: ";
    display(list1);

    cout << "List 2: ";
    display(list2);

    // Concatenate
    concatenate(list1, list2);

    // Display final list
    cout << "\nAfter Concatenation (List1 + List2): ";
    display(list1);

    return 0;
}
