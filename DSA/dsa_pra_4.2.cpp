#include <iostream>
using namespace std;

int size;
int f = -1;
int r = -1;
int circiuarqueue[5];

void enqueue(int x)
{
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

void dequeue()
{
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
void display()
{
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
        cout << endl;
    }
}
int main()
{
    size = 5;
    
    int choice;
    int a;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be inserted: ";
            cin >> a;
            enqueue(a);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (choice != 4);
    return 0;
}