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

**Code Logic:**
- Traverse each element one by one
- Compare element with the key
- If match found, return index

- **input**arr = [2, 5, 9, 12, 17]

- Let’s search for: 9

| Step | Index | Value at arr\[i] | Comparison | Result               |
| ---- | ----- | ---------------- | ---------- | -------------------- |
| 1    | i = 0 | 2                | 2 == 9 → ❌ | Continue             |
| 2    | i = 1 | 5                | 5 == 9 → ❌ | Continue             |
| 3    | i = 2 | 9                | 9 == 9 → ✅ | **Found at index 2** |

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

**Code Logic:**
Array must be sorted (✔ our array is sorted)
- Start with low = 0, high = n - 1

- Find mid = (low + high) / 2

- Compare arr[mid] with key

- Repeat on left or right sub-array

**Initial values:**
- low = 0, high = 4, key = 9
| Step | low | high | mid | arr\[mid] | Comparison | Result               |
| ---- | --- | ---- | --- | --------- | ---------- | -------------------- |
| 1    | 0   | 4    | 2   | 9         | 9 == 9 → ✅ | **Found at index 2** |

- Try Searching for a Missing Element (e.g. 8)
- Step 1: mid = 2, arr[2] = 9 → 9 > 8 → search left
- Step 2: low = 0, high = 1 → mid = 0 → arr[0] = 2
- Step 3: low = 1, high = 1 → mid = 1 → arr[1] = 5 → still < 8
- low > high → Not found

---

## Sorting Algorithms 
**Sorting** is the process of arranging data in a particular format (ascending or descending). Here are the most commonly used sorting algorithms:
1.Bubble Sort
2.Selection Sort
3.Insertion Sort
4.Merge Sort
5.Quick Sort

---
## 1. Bubble Sort
**Description:**
- Repeatedly compares adjacent elements and swaps them if they are in the wrong order.
- Simple but not efficient for large datasets.

**Time Complexity:**
- Best: O(n) (when already sorted)
- Worst & Average: O(n²)
### How it Works?
- Input: [5, 2, 9]
**Pass 1:**
- Compare 5 and 2 → swap → [2, 5, 9]
- Compare 5 and 9 → no swap
- Array after Pass 1: [2, 5, 9]

**Pass 2:**
- Compare 2 and 5 → no swap

- No changes → Array is sorted

Final Array: [2, 5, 9]

---
## 2. Selection Sort
**Description:**
- Finds the minimum element and places it at the beginning.

- Inefficient but easy to understand.

**Time Complexity:**
 - All cases: O(n²) 

### How it Works?
- Input: [5, 2, 9]

**Pass 1 (i = 0):**
- Find min from index 0 to 2 → min = 2 (at index 1)

- Swap 5 and 2 → [2, 5, 9]

**Pass 2 (i = 1):**
- Find min from index 1 to 2 → min = 5 (already in place)

- Pass 3 (i = 2):
- Only one element left

Final Array: [2, 5, 9]


---
## 3. Insertion Sort
**Description:**
- Builds the sorted array one element at a time.

- Efficient for small or nearly sorted datasets.

**Time Complexity:**
- Best: O(n)
- Worst & Average: O(n²)

### How it Works?
Input: [5, 2, 9]

**Pass 1 (i = 1, key = 2):**
- Compare 2 with 5 → 2 < 5 → shift 5 → [5, 5, 9]

- Insert 2 at index 0 → [2, 5, 9]

**Pass 2 (i = 2, key = 9):**
- Compare 9 with 5 → no shift → insert in place

Final Array: [2, 5, 9]

---
## 4. Merge Sort
**Description:**
- Divide-and-conquer algorithm.

- Divides the array into halves, sorts them, and then merges.

**Time Complexity:**
- All cases: O(n log n)

### How it works?
Input: [5, 2, 9]

**Split:**

- Left: [5]

- Right: [2, 9]

**Right split:**

- Left: [2]

- Right: [9]

**Merge [2] and [9] → [2, 9]**

**Now merge [5] and [2, 9]**

**Compare 5 and 2 → take 2**

**Compare 5 and 9 → take 5**

- Take remaining 9

→ [2, 5, 9]

Final Array: [2, 5, 9]

---
## 5. Quick Sort
**Description:**
- Divide-and-conquer, uses pivot to partition.
- One of the fastest sorting algorithms in practice.

**Time Complexity:**
- Best & Average: O(n log n)

- Worst: O(n²) (rare if good pivot chosen)

### How it Works?
Inut: [5, 2, 9]

- **Pivot** = 9 (last element)

**Partition:**

- Compare 5 < 9 → i = 0

- Compare 2 < 9 → i = 1

- Swap pivot with i+1 (already in place)

- Pivot = 9 is at correct place.

- Now sort left: [5, 2]

- **Pivot** = 2

- 5 > 2 → no changes

- Swap pivot with i+1 → [2, 5]

Final Array: [2, 5, 9]



---
