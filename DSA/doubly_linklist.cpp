#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

node *InsertAtHead(node *head, int data, node *prev)
{
    node *new_node = new node(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    return head;
}

node *InsertAtTail(node *head, int data)
{
    node *new_node = new node(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new_node->prev = temp;
        temp->next = new_node;
    }
    return head;
}

node *InsertAtPosition(node *head, int data, int pos)
{
    node *new_node = new node(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else if (pos == 0)
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else if (pos == pos-1)
    {
        head = InsertAtTail(head, data);
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if(temp->next == NULL){
                cout << "Position not found" << endl;
                return head;
            }
            temp = temp->next;
        }
        new_node->prev = temp;
        new_node->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
    }
    return head;
}

node *DeleteAtHead(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete temp;
    return head;
}

node *DeleteAtTail(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
    return head;
}

int CountNodes(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void Display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    int n, data;
        cout << "Enter the choice: " << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at tail" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete at head" << endl;
        // cout << "5. Delete at tail" << endl;
        cout << "5. Count Nodes" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
    do
    {
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            head = InsertAtHead(head, data, NULL);
            break;
        case 2:
            cout << "Enter the data: ";
            cin >> data;
            head = InsertAtTail(head, data);
            break;
        case 3:
            int pos;
            cout << "Enter the data: ";
            cin >> data;
            cout << "Enter the position: ";
            cin >> pos;
            head = InsertAtPosition(head, data, pos);
            break;
        case 4:
            head = DeleteAtHead(head);
            break;
        // case 5:
        //     head = DeleteAtTail(head);
        //     break;
        case 5:
            cout << "Number of nodes: " << CountNodes(head) << endl;
            break;
        case 6:
            Display(head);
            break;
        default:
            break;
        }
    } while (n != 7);
    cout<<endl;
    cout<<"23DCS089_Samarth";
    return 0;
}
