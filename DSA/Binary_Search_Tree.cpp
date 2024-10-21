#include <iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *Insert(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
    }
    else if (val <= root->value)
    {
        root->left = Insert(root->left, val);
    }
    else
    {
        root->right = Insert(root->right, val);
    }
    return root;
}

TreeNode *Search(TreeNode *root, int val)
{
    if (root == nullptr || root->value == val)
    {
        return root;
    }
    if (val < root->value)
    {
        return Search(root->left, val);
    }
    return Search(root->right, val);
}

TreeNode *TraversalInorder(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return root;
    }
    TraversalInorder(root->left, val);
    cout << root->value << " ";
    TraversalInorder(root->right, val);
    return root;
}

TreeNode *TraversalPreorder(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return root;
    }
    cout << root->value << " ";
    TraversalPreorder(root->left, val);
    TraversalPreorder(root->right, val);
    return root;
}

TreeNode *TraversalPostorder(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return root;
    }
    TraversalPostorder(root->left, val);
    TraversalPostorder(root->right, val);
    cout << root->value << " ";
    return root;
}

int main()
{
    TreeNode *root = nullptr;
    int n, data;
    cout << "1. Insert" << endl;
    cout << "2. Search" << endl;
    cout << "3. Inorder Traversal" << endl;
    cout << "4. Preorder Traversal" << endl;
    cout << "5. Postorder Traversal" << endl;
    cout << "6. Exit" << endl;
    do
    {
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            root = Insert(root, data);
            break;
        case 2:
            cout << "Enter data to search: ";
            cin >> data;
            if (Search(root, data) != nullptr)
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;
        case 3:
            cout << "Inorder Traversal: ";
            TraversalInorder(root, data);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal: ";
            TraversalPreorder(root, data);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal: ";
            TraversalPostorder(root, data);
            cout << endl;
            break;
            case 6:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        } while (n != 6);
        cout<<"23DCS089_SAMARTH"<<endl;

    return 0;
}