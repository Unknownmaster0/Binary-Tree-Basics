//question link ->  https://practice.geeksforgeeks.org/problems/deletion-in-a-binary-tree/1
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val)
    {
        this -> data = val;
        left = NULL;
        right = NULL;
    }

};

// function to delete the deepest
void deleteDeep(Node* &root,int val)
{
    
    if(root == NULL)
        return ;
        
    // check for the deepest condition
    if(root -> right != NULL && root -> right->data == val )
    {
        root -> right = NULL;
    }
    // check for the deepest condition
    if(root -> left != NULL && root -> left->data == val )
    {
        root -> left = NULL;
    }
    deleteDeep(root->right, val);
    deleteDeep(root->left, val);
}

// function to replace the node.
void findReplace(Node* &root, int key,int val)
{
    if(root == NULL)
        return ;
        
    if(root -> data == key)
        root->data = val;
        
    findReplace(root -> left,key, val);
    findReplace(root -> right, key,val);
}

int deepest(struct Node* root)
{
    if(root==NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int temp;
    while(!q.empty())
    {
        Node *fr=q.front();
        q.pop();
        temp=fr->data;
        if(fr->left)
         q.push(fr->left);
        if(fr->right)
         q.push(fr->right);
        
    }
    return temp;
}

struct Node* deletionBT(struct Node* root, int key)
{
    int rd=deepest(root);
    // deleteN(root,rd);
    deleteDeep(root,rd);
    findReplace(root,key,rd);
    
    return root;
}

int main()
{
    /*concpt -> 
    1. first find the deepest node of the tree using level order traversal.
    2. then delete the deepest node of the tree.
    3. then replace the deepest node with the node to be deleted.*/
    return 0;
}