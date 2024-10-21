#include<iostream>
using namespace std;

int main()
{
    int key,array[9] = {1,2,3,4,5,6,7,8,9};
    int index = -1;
    cout<<"Enter the number :";
    cin>>key;
    for(int i=0; i<9; i++)
    {
        if(array[i] == key){
            index = i;
            break;
        }
    }
    if(index==-1)
    {
        cout<<"Not Found"<<endl;
    }
    cout<<"The index is :"<<index<<endl;

    cout<<"23DCS089_SAMARTH";
}

