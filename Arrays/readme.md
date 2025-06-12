# What is array?
An array is a collection of elements (variables) of the same data type stored in contiguous memory locations.
Each element in the array can be accessed using its index, starting from 0.

---
## Characteristics of Arrays
- Fixed size (decided at compile time).

- Elements are stored in continuous memory.

- Can access any element in O(1) time using its index.

- All elements are of the same data type (e.g., int, float, char).


---
## Memory Layout
For an int arr[5] = {10, 20, 30, 40, 50};
Index:     0    1    2    3    4
Value:    10   20   30   40   50
Address: 1000 1004 1008 1012 1016  (if int = 4 bytes)
---
## Advantages
- Fast access using index.

- Easy to implement and use.

- Efficient use of memory (no extra pointer overhead like in linked lists).

---
## Disadvantages
- Fixed size: Cannot grow or shrink dynamically.

- Insertion/deletion in the middle is slow (O(n)).

- Wastes space if the array is sparsely used.

---
