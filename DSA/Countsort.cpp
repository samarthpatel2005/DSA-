#include <iostream>
using namespace std;

void Countsort(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    int count[max + 1] = {0};
    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++){
        count[i] += count[i - 1];
    }
    int output[n];
    for (int i = n - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++){
        arr[i] = output[i];
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
    Countsort(arr, n);
    cout << "The sorted IDs of books are: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
