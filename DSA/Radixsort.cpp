#include <iostream>
using namespace std;

void Radixsort(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10){
        int output[n];
        int count[10] = {0};
        for (int i = 0; i < n; i++){
            count[(arr[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--){
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++){
            arr[i] = output[i];
        }
    }
}
int main(){
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter the IDs of books: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Radixsort(arr, n);
    cout << "The sorted IDs of books are: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
