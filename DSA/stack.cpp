#include <iostream>
using namespace std;

int stack[5];
int top = -1;

void isfull()
{
    if (top == 4)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        cout << "Stack is not Full" << endl;
    }
}

void isempty()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is not Empty" << endl;
    }
}

int push(int a)
{

    if (top == 4)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = a;
    }
    return top;
}

int pop(int a)
{

    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        top--;
    }
    return top;
}

int undo(int a)
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "The element is :" << stack[top] << endl;
        top--;
    }
    return top;
}


int redo(int a)
{
    if (top == 4)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        cout << "The element is :" << stack[top] << endl;
        top++;
    }
    return top;
}

int peek(int a)
{

    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "The top element is :" << stack[top] << endl;
    }
    return top;
}

int show(int a)
{

    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "The elements are :" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
    return top;
}

int main()
{
    // cout << "Enter the stack elements :";
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> stack[i];
    // }
    int choice;
    int a;
    cout << "1. Check if Stack is Full" << endl;
    cout << "2. Check if Stack is Empty" << endl;
    cout << "3. Push an element" << endl;
    cout << "4. Pop an element" << endl;
    cout << "5. Peek the top element" << endl;
    cout << "6. Show the elements" << endl;
    cout << "7. undo elements" << endl;
    cout << "8. redo elements" << endl;
    cout << "9. Exit" << endl;
    
    do
    {
        cout << "Enter your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            isfull();
            break;
        case 2:
            isempty();
            break;
        case 3:
            cout << "Enter the element :";
            cin >> a;
            push(a);
            break;
        case 4:
            // cout << "enter the element :";
            // cin >> a;
            pop(a);
            break;
        case 5:
            peek(a);
            break;
        case 6:
            show(a);
            break;
        case 7:
            undo(a);
            break;
        case 8:
            redo(a);
            break;
        case 9:
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (choice != 9);
    cout << "23DCS089_SAMARTH";
}