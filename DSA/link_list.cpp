#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
node *InsertAtHead(node *head, int data)
{
    node *new_node = new node(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
        return new_node;
    }
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
    else
    {
        node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    return head;
}

node *DeletAtHead(node*head){
    node*temp=head;
    head=head->next;
    delete temp;
    return head;
}

node *DeletAtTail(node*head){
    node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node*toDelete=temp->next;
    temp->next=NULL;
    delete toDelete;
    return head;
}

node *display(node *head)
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
    int n,data;
        cout << "Enter the choice: "<<endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at tail" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete at head" << endl;
        cout << "5. Delete at tail" << endl;
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
            head = InsertAtHead(head, data);
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
            head=DeletAtHead(head);
            break;
        case 5:
            head=DeletAtTail(head);
            break;
        case 6:
        cout<<"The Link List: ";
            display(head);
            break;
        default:
            break;
        }
    } while (n != 7);
    cout<<endl;
    cout<<"23DCS089_Samarth";
    return 0;
}