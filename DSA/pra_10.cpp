#include <iostream>
using namespace std;

// Selection Sort Function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort Function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the IDs of books: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);
    
    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int c;
    cout << "Do you want to Enter new books? (1 for Yes): ";
    cin >> c;

    if (c == 1) {
        int na;
        cout << "How many books: ";
        cin >> na;

        int* newArr = new int[n + na]; // New dynamic array

        // Copy the old array into the new array
        for (int i = 0; i < n; i++) {
            newArr[i] = arr[i];
        }

        cout << "Enter the IDs of new books: ";
        for (int i = n; i < n + na; i++) {
            cin >> newArr[i];
        }

        // Sort the combined array using Insertion Sort
        insertionSort(newArr, n + na);

        cout << "After integrating new books: ";
        for (int i = 0; i < n + na; i++) {
            cout << newArr[i] << " ";
        }
        cout << endl;

        delete[] newArr;
    }

    delete[] arr;

    cout<<"23DCS089_Samarth";

    return 0;
}

//For selection Sort
// Time complexity: O(n^2)
// Space complexity: O(1)

//For insertion Sort
//Time complexity: O(n^2)->worst and avg case  O(n)-> Best case
//Space complexity: O(1)
