#include <iostream>
using namespace std;

/* If you don't understand the flow of recursion then comment all the other function and run only the buildTree function and see the value of right and left and you
will get the flow of recursion. */

/*Steps to create the binary tree
1. make the node class
2. make the build function of binary tree
*/

/* In this code we will see the two methods of the level order traversal of the binary tree.
    Second method will be in the "Breadth first search file" */

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

// finding the height of the binary tree.
int height(Node *root)
{
    if (root == NULL)
        return 0;

    else
    {
        // compute the left height.
        int Lheight = height(root->left);
        int Rheight = height(root->right);

        // NOW return the larger height
        Lheight += 1;
        Rheight += 1;

        return max(Lheight, Rheight);
    }
}

// *****************  1st method of the level of iteration without using the queue instead that using the "simple recursion" *********************
// printing the current level.
void currentLevel(Node *root, int level)
{
    if (root == NULL)
        return;

    else if (level == 1)
    {
        cout << root->data << " ";
        return;
    }
    else if (level > 1)
    {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}

// iterating the levels of the binary tree.
void LevelOrder(Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        currentLevel(root, i);
        cout << endl;
    }
}

int main()
{
    // 4 2 1 -1 -1 3 -1 -1 5 6 -1 -1 7 -1 -1
    Node *root = NULL;

    root = buildTree(root);

    int depth = height(root);
    cout << "The height of the binary tree is -> " << depth << endl;

    // printing the binary tree in level order traversal.
    LevelOrder(root);
    cout << endl;

    return 0;
}