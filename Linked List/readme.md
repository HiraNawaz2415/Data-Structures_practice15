## What is a Linked List?
A Linked List is a linear data structure in which elements (called nodes) are stored non-contiguously in memory and are connected using pointers.

Each node contains:
        - [ data | next ]
- **data:** stores the actual value

- **next**: a pointer to the next node

---
## Types of Linked List:

| Type                     | Description                                      |
| ------------------------ | ------------------------------------------------ |
| **Singly Linked List**   | Each node points to the next node only           |
| **Doubly Linked List**   | Each node has two pointers: to next and previous |
| **Circular Linked List** | Last node points back to the first node          |

---
## Linked List Node Structure in C++:

```c
struct Node {
    int data;
    Node* next;
};
```

---
## Basic Operations:

| Operation               | Description                    |
| ----------------------- | ------------------------------ |
| **Insert at Beginning** | Add node at the head           |
| **Insert at End**       | Add node at the tail           |
| **Delete Node**         | Remove node from list          |
| **Traverse**            | Visit each node and print data |
| **Search**              | Find a value in the list       |

---
## Advantages:
- Dynamic size
- Efficient insertions/deletions (especially at head)

## Disadvantages:
- No random access (unlike arrays)
- More memory (due to pointers)
- Traversal is slower

---
## Singly Linked List Visualization:

- [10 | * ] → [20 | * ] → [30 | NULL]
- head                          tail

---
