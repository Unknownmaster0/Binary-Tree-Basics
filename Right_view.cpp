#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void rightView(Node* root, int level, vector<int>& ans)
{
    if(root == NULL)
        return;

    if(level == ans.size())
        ans.push_back(root->data);

// go to the right of the root.
    rightView(root->right, level+1, ans);
// go to left of the root
    rightView(root->left, level+1, ans);
}

int main()
{
  // right view of the binary tree using the recursion.  
    return 0;
}