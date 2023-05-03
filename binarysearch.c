#include <stdio.h>

// Iterative binary search
int iterativeBinarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if x is present at mid
        if (arr[mid] == x) {
            return mid;
        }
        
        // If x is greater, ignore left half
        if (arr[mid] < x) {
            low = mid + 1;
        }
        
        // If x is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }
    
    // Element not present in array
    return -1;
}

// Recursive binary search
int recursiveBinarySearch(int arr[], int low, int high, int x) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if x is present at mid
        if (arr[mid] == x) {
            return mid;
        }
        
        // If x is greater, search right half
        if (arr[mid] < x) {
            return recursiveBinarySearch(arr, mid + 1, high, x);
        }
        
        // If x is smaller, search left half
        else {
            return recursiveBinarySearch(arr, low, mid - 1, x);
        }
    }
    
    // Element not present in array
    return -1;
}

// Driver program
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    // Iterative binary search
    int resultIterative = iterativeBinarySearch(arr, 0, n - 1, x);
    if (resultIterative == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", resultIterative);
    }
    
    // Recursive binary search
    int resultRecursive = recursiveBinarySearch(arr, 0, n - 1, x);
    if (resultRecursive == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", resultRecursive);
    }
    
    return 0;
}
