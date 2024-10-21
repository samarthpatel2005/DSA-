#include <iostream>
using namespace std;

int size;
int front = -1;
int rear = -1;
int queue[5];

void enqueue(int x)
{
    if (rear == size - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}
void display()
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
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