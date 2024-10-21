#include<iostream>
using namespace std;

int main()
{
    int key,array[9] = {1,23,34,45,51,67,78,83,99};
    int index = -1;
    int low = 0;
    int high = 8;
    cout<<"Enter the element :";
    cin>>key;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(array[mid] == key)
        {
            index = mid;
            break;
            }
            else if(array[mid] < key)
            {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
    }

    if(index==-1)
    {
        cout<<"Not Found"<<endl;
    }
    cout<<"The Index is :"<<index<<endl;

    cout<<"23DCS089_SAMARTH";
    

}