#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *buildTree(Node *root)
{
    // enter the data of the root
    printf("enter data: ");
    int num;
    cin >> num;

    root = new Node(num);

    // base case :
    // cout<<"we consider -1 as NULL. To terminate the loop."<<endl;
    if (num == -1)
        return NULL;

    // now filling the left and right part of the tree.

    // Left Part
    cout << "enter the data to fill on left of -> " << num << endl;

    // recursive call for the left part of the tree
    root->left = buildTree(root->left);

    // Right Part
    cout << "enter the data to fill on right -> " << num << endl;

    // recursive call for the left part of the tree
    root->right = buildTree(root->right);

    // finally return the root
    return root;
}

void MorrisTraversal(Node *root)
{
    if (root == NULL)
        return;

    // we need two iterator.
    Node *current, *previous;
    current = root;

    cout<<"hello"<<endl;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }

        else
        {
            // then find the predecessor of current.
            previous = current->left;
            while (previous->right != NULL && previous->right != current)

                previous = previous->right;

            // if previous right is null -: it means we need to point the predessor or previour to the current elements.
            if (previous->right == NULL)
            {
                previous->right = current;
                current = current->left;
            }

            // if the previous right is already pointing to the current element -: then simply remove the made link
            else
            {
                previous->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout << "root -> data -> " << root->data << endl;
    MorrisTraversal(root);
// 5 4 -1 -1 3 -1 -1
    return 0;
}