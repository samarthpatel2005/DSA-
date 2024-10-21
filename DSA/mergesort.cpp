#include <iostream>
using namespace std;

void Mergesort(int arr[], int n)
{
    if (n > 1)
    {
        int mid = n / 2;
        int left[mid];
        int right[n - mid];
        for (int i = 0; i < mid; i++)
        {
            left[i] = arr[i];
        }
        for (int i = mid; i < n; i++)
        {
            right[i - mid] = arr[i];
        }
        Mergesort(left, mid);
        Mergesort(right, n - mid);
        int i = 0, j = 0, k = 0;
        while (i < mid && j < n - mid)
        {
            if (left[i] < right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < mid)
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < n - mid)
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}

int main()
{
     int n;
    cout << "Enter the number of books: ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter the IDs of books: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    Mergesort(arr, n);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "23DCS089_Samarth";
    return 0;
}