// 2415
// Algorithm for printing odd values in linked list
//--------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert node at end
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

// Display all elements
void displayList(Node* head) {
    cout << "Full List: ";
    while (head) {
        cout << head->data << " → ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Display only odd values
void printOddValues(Node* head) {
    cout << "Odd values in the list: ";
    bool found = false;
    while (head) {
        if (head->data % 2 != 0) {
            cout << head->data << " ";
            found = true;
        }
        head = head->next;
    }
    if (!found)
        cout << "None";
    cout << endl;
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

    displayList(head);
    printOddValues(head);

    return 0;
}
