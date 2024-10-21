#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* insertAtHead(Node* head, int data)
{
    Node *new_node = new Node(data);
    if (head == NULL)
    {
        head = new_node;
        head->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

Node *deleteAtTail(Node *head)
{
    if (head == NULL)
    {
        cout << "Circular linked list is empty." << endl;
        return head;
    }
    else if (head->next == head)
    {
        delete head;
        // head = NULL
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *tail = temp->next;
        temp->next = head;
        delete tail;
    }
    return head;
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "Circular linked list is empty." << endl;
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    int n, data;
    Node *head = NULL; 

    cout << "Enter the choice: " << endl;
    cout << "1. Insert at head" << endl;
    cout << "2. Delete at tail" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;

    do
    {
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            head = insertAtHead(head, data);
            break;
        case 2:
            head = deleteAtTail(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (n != 4);

    cout<<endl;
    cout<<"23DCS089_Samarth";

    return 0;
}

