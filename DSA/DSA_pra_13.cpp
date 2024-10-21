#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to calculate the hash value using the provided H(x) function
int hashFunction(int x) {
    return (x % 18) + 2;
}

int main() {
    const int SIZE = 20;
    int arr[SIZE] = {0};
    int values[15];
    
    srand(time(0));
    
    // Generate 15 unique random values between 100000 and 999999
    for (int i = 0; i < 15; i++) {
        bool unique;
        do {
            unique = true;
            values[i] = rand() % 900000 + 100000;
            for (int j = 0; j < i; j++) {
                if (values[i] == values[j]) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
    }

    // Insert values into the array using the hash function and linear probing
    for (int i = 0; i < 15; i++) {
        int key = hashFunction(values[i]);
        
        while (arr[key] != 0) {
            key = (key + 1) % SIZE;
        }
        arr[key] = values[i];
    }
    
    // Display the final values in the array
    cout << "Final array values:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": " << arr[i] << endl;
    }
    
    return 0;
}
