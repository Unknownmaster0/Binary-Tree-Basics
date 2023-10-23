#include<iostream>
#include<vector>
#include<queue>
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


vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* newNode = q.front();
        q.pop();
        
        while(newNode != NULL)
        {
            ans.push_back(newNode->data);
            if(newNode->left)
                q.push(newNode->left);
            
            newNode = newNode->right;
        }
    }
    
    return ans;
}

int main()
{
    // for diagonal traversal of the binary tree
    // question link -> https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
    return 0;
}