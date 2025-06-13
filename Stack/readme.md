## What is a Stack?
A Stack is a linear data structure that follows the LIFO (Last In, First Out) principle.
This means the last element added to the stack is the first one to be removed.

## Real-life Example:
- Think of a stack of plates:
- You place plates on top (push).
- You remove the top plate first (pop).

---
## Basic Operations

| Operation           | Description                                 |
| ------------------- | ------------------------------------------- |
| `push()`            | Adds an element to the top                  |
| `pop()`             | Removes the top element                     |
| `peek()` or `top()` | Returns the top element without removing it |
| `isEmpty()`         | Checks if the stack is empty                |
| `size()`            | Returns the number of elements              |

---
## Applications of Stack:
- Function call management (Recursion)
- Undo mechanisms in editors
- Backtracking (e.g., maze solving, puzzle)
- Expression evaluation and conversion (Infix to Postfix)
- Browser history

---
## 1. push(element)
**Definition:**
- Adds (inserts) a new element to the top of the stack.

**Example:*
Consider the stack is empty:
- []
- After push(5) → [5]
- After push(10) → [5, 10]
- After push(20) → [5, 10, 20]
Now, 20 is at the top of the stack.

---
## 2. pop()
**Definition:**
- Removes (deletes) the top element from the stack.

**Example:**
- From the stack: [5, 10, 20]
- After pop() → removes 20, the stack becomes: [5, 10]

Element will always be remove from the top.

---
## 3. top() or peek()
**Definition:**
- Returns the top element without removing it.

**Example:**
- From the stack: [5, 10, 20]
- top() → returns 20
- Stack remains: [5, 10, 20]

---
## Stack Example:
For example do these operations:
- push(10)
- push(20)
- push(30)
  
The stack looks like this:
|     30     |   ← top (last pushed, first out)
|     20     |
|     10     |
-------------

Now if  call:
- pop()
- It removes the top element, which is 30:
  

|     20     |   ← top
|     10     |
-------------

---
## Push Operation (Adding):

Before push(40):
|     30     |
|     20     |
|     10     |
-------------

After push(40):
|     40     |  ← top
|     30     |
|     20     |
|     10     |
-------------

---
## Pop Operation (Removing):

Before pop():
|     40     |  ← top
|     30     |
|     20     |
|     10     |
-------------

After pop():
|     30     |  ← top
|     20     |
|     10     |
-------------

