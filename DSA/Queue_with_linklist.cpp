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
node *DeletAtHead(node*head){
    if(head == NULL){
        cout<<"Queue is empty"<<endl;
    }
    else{
    node*temp=head;
    head=head->next;
    delete temp;
    return head;
    }
}
void display(node *head)
{
    node *temp = head;
    if(head == NULL){
        cout<<"Queue is empty"<<endl;
    }
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
    cout << "1. EnQueue" << endl;
    cout << "2. DeQueue" << endl;
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
            head = InsertAtTail(head, data);
            break;
        case 2:
            head = DeletAtHead(head);
            break;
        case 3:
            cout<<"Elements Are:";
            display(head);
            break;
        case 4:
            break;
        default:
            cout << "Enter the correct choice" << endl;
            break;
        }
    } while (n != 4);
    cout << "23DCS089_SAMARTH" << endl;
    return 0;
}