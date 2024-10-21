#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};
Node *Insert(Node *head, int data, Node *prev){
    Node *new_node = new Node(data);
    if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
        return head;
    }
Node *Display(Node *head){
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return head;
}
Node* Concatenate(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }
    
    Node* temp = head1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    
    temp->next = head2;
    head2->prev = temp;
    
    return head1;
}
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    
    int n, data;
    cout << "1 for enter element in first list "<<endl;
    cout << "2 for enter element in second list "<<endl;
    cout << "3 for display first list "<<endl;
    cout << "4 for display second list "<<endl;
    cout << "5 for concatenate two list "<<endl;

    do
    {
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            head1 = Insert(head1, data, nullptr);
            break;
        case 2:
            cout << "Enter the data: ";
            cin >> data;
            head2 = Insert(head2, data, nullptr);
            break;
        case 3:
            cout << "First list: ";
            Display(head1);
            cout << endl;
            break;
        case 4:
            cout << "Second list: ";
            Display(head2);
            cout << endl;
            break;
        case 5:
            head1 = Concatenate(head1, head2);
            cout << "Concatenated list: ";
            Display(head1);
            cout << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (n != 6);
    cout<<endl;
    cout<<"23DCS089_Samarth";
    return 0;
}
