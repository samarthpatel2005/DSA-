#include <iostream>
using namespace std;

class Double_Ended_Queue{
    public:
    int size;
    int f = -1;
    int r = -1;
    int circiuarqueue[5];

    
    void enqueuefromfront(int x){
        if ((f == r+1) || (r == size-1 && f == 0))
        {
            cout << "Overflow";
        }
        else if (r == size-1 && f !=0)
        {
            r = 0;
            circiuarqueue[r] = x;
        }
        else
        {
            if (f == -1)
            {
                f = 0;
            }
            r++;
            circiuarqueue[r] = x;
        }
    }
    void enqueuefromrear(int x){
        if ((r == f-1) || (f == 0 && r == size-1))
        {
            cout << "Overflow";
        }
        else if (f == 0 && r == -1)
        {
            f = 0;
            r = 0;
            circiuarqueue[r] = x;
        }
        else if (r == size-1 && f != 0)
        {
            r = 0;
            circiuarqueue[r] = x;
        }
        else
        {
            r++;
            circiuarqueue[r] = x;
        }
    }
    void dequeuefromfront(){
        if (f == -1)
        {
            cout << "Underflow";
        }
        else if (f == r)
        {
            f = -1;
            r = -1;
        }
        else if (f == size-1 && f!=r)
        {
            f = 0;
        }
        else
        {
            f++;
        }
    }
    void dequeuefromrear(){
        if (f == -1)
        {
            cout << "Underflow";
        }
        else if (f == r)
        {
            f = -1;
            r = -1;
        }
        else if (r == 0)
        {
            r = size-1;
        }
        else
        {
            r--;
        }
    }
    void display(){
        if (f == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Elements in the queue are: ";
            if (r >= f)
            {
                for (int i = f; i <= r; i++)
                {
                    cout << circiuarqueue[i] << " ";
                }
            }
            else
            {
                for (int i = f; i < size; i++)
                {
                    cout << circiuarqueue[i] << " ";
                }
                for (int i = 0; i <= r; i++)
                {
                    cout << circiuarqueue[i] << " ";
                }
            }
        }
    }
};
int main(){
    Double_Ended_Queue q;
    q.size = 5;
    q.enqueuefromfront(10);
    q.enqueuefromfront(30);
    q.enqueuefromfront(40);
    // q.enqueuefromrear(20);
    q.display();
    // q.dequeuefromfront();
    // q.display();
    q.dequeuefromrear();
    q.display();
    return 0;
}