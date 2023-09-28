#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// building the tree using level order traversal.
void buildTree(Node *&root)
{
    cout << "enter root data : ";
    int rootData;
    cin >> rootData;
    root = new Node(rootData);

    // create the queue
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // pushing the left part of the tree
        cout << "enter data for left of " << temp->data << endl;
        int left;
        cin >> left;

        if (left != -1)
        {
            temp->left = new Node(left);
            q.push(temp->left);
        }

        // pushing the right part of the tree
        cout << "enter data for right of " << temp->data << endl;
        int right;
        cin >> right;

        if (right != -1)
        {
            temp->right = new Node(right);
            q.push(temp->right);
        }
    }
}

// Printing the binary Tree.
void LevelOrder(Node *root)
{
    cout << endl;
    // creating the queue and pushing the root element of the queue. **** condition -> check whether the root is null or not *****
    if (root == NULL)
    {
        cout << "binary tree is empty." << endl;
        return;
    }

    queue<Node *> q;
    // first push the root element in the queue.
    q.push(root);
    // using separator
    q.push(NULL);

    // push, pop and print the element which is at the front of the queue.
    while (!q.empty())
    {
        // as the front of the Queue contains the Node* thus we need to store this first.
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            // pushing the left part of the binary tree to the queue.
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    // our tree is -> 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    Node *root = NULL;
    buildTree(root);
    cout << endl;
    cout << "printing the tree" << endl;
    LevelOrder(root);
    cout << endl;
    return 0;
}