//2415..
#include <iostream>
using namespace std;

// Function for Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // Element found at index i
    }
    return -1; // Element not found
}

// Function for Binary Search (Array must be sorted)
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid; // Element found
        else if (arr[mid] < key)
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }
    return -1; // Element not found
}

// Function to display the array
void displayArray(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, key, choice;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    displayArray(arr, n);

    cout << "\nEnter element to search: ";
    cin >> key;

    cout << "\nChoose Search Method:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search (Array must be sorted)\n";
    cout << "Enter choice: ";
    cin >> choice;

    int result;
    if (choice == 1) {
        result = linearSearch(arr, n, key);
    } else if (choice == 2) {
        result = binarySearch(arr, 0, n - 1, key);
    } else {
        cout << "Invalid choice!";
        return 0;
    }

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found.\n";

    return 0;
}
