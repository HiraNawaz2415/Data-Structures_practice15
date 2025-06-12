//2415...
#include <iostream>
using namespace std;

// Swap function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    cout << "Time Complexity of Bubble Sort:\n";
    cout << "Best: O(n), Average: O(n^2), Worst: O(n^2)\n";
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
    cout << "Time Complexity of Selection Sort:\n";
    cout << "Best: O(n^2), Average: O(n^2), Worst: O(n^2)\n";
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
    cout << "Time Complexity of Insertion Sort:\n";
    cout << "Best: O(n), Average: O(n^2), Worst: O(n^2)\n";
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print array
void printArray(int arr[], int n) {
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int choice, n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: bubbleSort(arr, n); break;
        case 2: selectionSort(arr, n); break;
        case 3: insertionSort(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1);
                cout << "Time Complexity of Merge Sort:\n";
                cout << "Best: O(n log n), Average: O(n log n), Worst: O(n log n)\n";
                break;
        case 5: quickSort(arr, 0, n - 1);
                cout << "Time Complexity of Quick Sort:\n";
                cout << "Best: O(n log n), Average: O(n log n), Worst: O(n^2)\n";
                break;
        default: cout << "Invalid choice!" << endl; return 0;
    }

    printArray(arr, n);
    return 0;
}
