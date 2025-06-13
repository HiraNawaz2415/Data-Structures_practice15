# **What is a Queue?**
A queue is a linear data structure that follows the FIFO (First In, First Out) principle. The element that is inserted first is the one to be removed first.

## Real-life Examples of Queues:
- People standing in line at a ticket counter.
- Print jobs sent to a printer.
- Task scheduling in operating systems.

---
## Queue Terminology

| Term          | Description                                      |
| ------------- | ------------------------------------------------ |
| **Enqueue**   | Add (insert) an element at the rear of the queue |
| **Dequeue**   | Remove (delete) an element from the front        |
| **Front**     | Points to the first element in the queue         |
| **Rear**      | Points to the last element in the queue          |
| **Overflow**  | Trying to insert into a full queue               |
| **Underflow** | Trying to remove from an empty queue             |

---
## Types of Queues
1.Simple Queue (Linear Queue)
2.Circular Queue
3.Priority Queue
4.Deque (Double-ended Queue)

---
## Operations on Queue
**1. Enqueue**
- Inserts an element at the end (rear) of the queue.

**2. Dequeue**
- Removes an element from the front of the queue.

**3. Peek / Front**
- Shows the front element without removing it.

**4. isEmpty()**
- Checks if the queue is empty.

**5. isFull()**
- Checks if the queue is full (important in fixed-size array implementations).

---
## Circular Queue
**What is a Circular Queue?**
A Circular Queue is a linear data structure where the last position is connected back to the first position to make a circle. It solves the problem of the unused space in a normal (linear) queue.

## Why Circular?
- In a simple queue (array-based), if you enqueue and dequeue multiple times, the front keeps moving right, and even if there is space left on the left side of the array, it's not reused.

- A circular queue uses that leftover space efficiently by wrapping around to the beginning of the array when the end is reached.

---
## What is a Double Ended Queue (Deque)?
A Deque (Double Ended Queue) is a linear data structure that allows insertion and deletion from both ends — front and rear.

It is more flexible than a regular queue and is often used when elements need to be processed from both ends.

## Types of Deques
**Input-Restricted Deque:** Insertion is restricted to one end, but deletion can be done from both ends.

**Output-Restricted Deque:** Deletion is restricted to one end, but insertion can be done from both ends.

### Basic Operations on deque

| Operation        | Description                         |
| ---------------- | ----------------------------------- |
| `insertFront(x)` | Inserts an element `x` at the front |
| `insertRear(x)`  | Inserts an element `x` at the rear  |
| `deleteFront()`  | Deletes an element from the front   |
| `deleteRear()`   | Deletes an element from the rear    |
| `getFront()`     | Gets the front element              |
| `getRear()`      | Gets the rear element               |
| `isFull()`       | Checks if the deque is full         |
| `isEmpty()`      | Checks if the deque is empty        |

---
## What is a Priority Queue?
A Priority Queue is a special type of queue in which each element is associated with a priority, and elements are served based on their priority.

Elements with higher priority are dequeued before elements with lower priority.

If two elements have the same priority, they are served according to their order in the queue (FIFO).

---
