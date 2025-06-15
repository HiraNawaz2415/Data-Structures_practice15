// 2415..
// Algorithm for finding midlle lement in the list
// Logic:
//Use two pointers:
//slow moves one node at a time
//fast moves two nodes at a time
//When fast reaches the end, slow will be at the middle.
//----------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert node at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display list
void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " → ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Function to find middle element
void findMiddle(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << endl;
}

int main() {
    Node* head = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        insertEnd(head, val);
    }

    cout << "\nLinked List:\n";
    display(head);

    findMiddle(head);

    return 0;
}
