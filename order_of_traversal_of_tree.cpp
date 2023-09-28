#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // making the constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    printf("enter data: ");
    int num;
    cin >> num;

    root = new Node(num);

    // base case :
    if (num == -1)
        return NULL;

    cout << "enter the data to fill on left of -> " << num << endl;

    root->left = buildTree(root->left);

    cout << "enter the data to fill on right -> " << num << endl;

    root->right = buildTree(root->right);

    return root;
}

// Function to Breadth first search of the Binary tree.
// Now using the separator to print the Binary tree in tree format
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

// Remember about -> "LNR"
void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// Remember -> NLR
void PreOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// Remember -> LRN
void PostOrder(Node *root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    // 4 2 1 -1 -1 3 -1 -1 5 6 -1 -1 7 -1 -1
    Node *root = NULL;

    root = buildTree(root);
    cout << "printing the data in the level order traversal." << endl;
    LevelOrder(root);
    cout << "Printing the data of the Inorder traversal." << endl;
    Inorder(root);
    cout << endl;
    cout << "Printing the data of the PreOrder traversal." << endl;
    PreOrder(root);
    cout << endl;
    cout << "Printing the data of the PostOrder traversal." << endl;
    PostOrder(root);
    cout << endl;

    return 0;
}