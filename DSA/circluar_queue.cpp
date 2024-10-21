#include<iostream>
using namespace std;

int size;
int front = -1;
int rear = -1;
int circularqueue[5];

void enqueue(int x)
{
    if ((rear + 1) % size == front)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        circularqueue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
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
        for (int i = front; i != rear; i = (i + 1) % size)
        {
            cout << circularqueue[i] << " ";
        }
        // cout << circularqueue[rear] << endl;
    }
}

// void display()
// {
//     if (front == -1)
//     {
//         cout << "Queue is Empty" << endl;
//     }
//     else
//     {
//         cout << "Elements in the queue are: ";
//         if (rear >= front)
//         {
//             for (int i = front; i <= rear; i++)
//             {
//                 cout << circiuarqueue[i] << " ";
//             }
//         }
//         else
//         {
//             for (int i = front; i < size; i++)
//             {
//                 cout << circiuarqueue[i] << " ";
//             }
//             for (int i = 0; i <= rear; i++)
//             {
//                 cout << circiuarqueue[i] << " ";
//             }
//         }
//         cout << endl;
//     }
// }

int main(){
    size = 5;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    // dequeue();
    // dequeue();
    display();

    cout << endl;
    return 0;
}