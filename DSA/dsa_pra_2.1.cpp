#include <iostream>
using namespace std;

string stack ;
int top = -1;
int size = 5;
void push(char x)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        top--;
    }
}
void display()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}
void undo()
{
    if (top == -1)
    {
        cout << "Nothing to undo" << endl;
    }
    else
    {
        pop();
    }
}
void redo()
{
    if (top == size - 1)
    {
        cout << "Nothing to redo" << endl;
    }
    else
    {
        top++;
    }
}
void revers()
{
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    push('H');
    push('e');
    push('l');
    push('l');
    push('o');
    display();
    undo();
    display();
    redo();
    display();
    revers();
    cout << "23DCS089_Samarth Patel";
    return 0;
}
