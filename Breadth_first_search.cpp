#include <iostream>
#include <queue>
using namespace std;

/* 2nd approach of the " Level order traversal or Breadth first Search ". */
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
/*
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

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
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
*/

// Time complexity -> O(N) where n is the number of nodes
// Space complexity -> O(N) where n is the number of nodes in case when all the nodes are in same straight line.
vector<vector<int>> LevelOrder(Node* root)
{
    vector<vector<int> > ans;
    if(root == NULL)    return ans;

    queue<Node * > q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i<size; i++)
        {
            Node* temp = q.front();
            q.pop();

            level.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }

        ans.push_back(level);
    }
    return ans;
}

void print(vector<vector<int> >  arr)
{
    for(int i = 0; i<arr.size(); i++)
    {
        for(int j = 0; j<arr[i].size(); j++)
            cout<<arr[i][j]<<" ";

        cout<<endl;
    }
}

int main()
{
    // 4 2 1 -1 -1 3 -1 -1 5 6 -1 -1 7 -1 -1
    Node *root = NULL;

    root = buildTree(root);
    vector<vector<int>> arr = LevelOrder(root);
    print(arr);
    return 0;
}