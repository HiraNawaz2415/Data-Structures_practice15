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
- Index:     0    1    2    3    4
- Value:    10   20   30   40   50
- Address: 1000 1004 1008 1012 1016  (if int = 4 bytes)

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
## Operations on Array
1. Insertion
2. Deleton
3. Updation
4. Searching
5. Sorting

---
## Searching Types
## **1.What is Linear Search?**
- Definition:
Linear Search (also known as Sequential Search) is a simple searching algorithm that checks every element in the array until it finds the target value or reaches the end of the array.

**Time Complexity:**

- Best Case: O(1) (if element is at the beginning)
- Worst Case: O(n) (if element is at the end or not present)

**When to Use:**

- When the array is unsorted

- When the array size is small

---
## 2.What is Binary Search?
- Definition:
Binary Search is an efficient algorithm for finding an element in a sorted array. It repeatedly divides the search interval in half.

Steps:

- Start with the middle element.
- If the element is equal to the target, return the index.
- If the target is less, search the left half.
- If the target is more, search the right half.

**Time Complexity:**

  - O(log n)

**When to Use:**

- Only when the array is sorted

---

## Sorting Algorithms 
**Sorting** is the process of arranging data in a particular format (ascending or descending). Here are the most commonly used sorting algorithms:
1.Bubble Sort
2.Selection Sort
3.Insertion Sort
4.Merge Sort
5.Quick Sort

---
