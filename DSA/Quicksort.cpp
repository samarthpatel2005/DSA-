#include <iostream>
using namespace std;

int Partition(int arr[], int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i = i + 1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

void Quicksort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(arr, p, r);
        Quicksort(arr, p, q - 1);
        Quicksort(arr, q + 1, r);
    }
}

int main () {
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Quicksort(arr, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}