#include <iostream>
using namespace std;

int main()
{
    int key, array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index = -1;
    int low = 0;
    int high = 8;

    cin >> key;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (array[mid1] == key)
        {
            index = mid1;
            break;
        }
        else if (array[mid2] == key)
        {
            index = mid2;
        }
        else if (array[mid1] < key && array[mid2] > key)
        {
            low = mid1 + 1;
        }
        else if (array[mid1] > key && array[mid2] < key)
        {
            high = mid2 - 1;
        }
    }

     if(index==-1)
    {
        cout<<"Not Found"<<endl;
    }
    cout<<index;
}