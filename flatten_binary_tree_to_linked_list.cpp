#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            this -> data = val;
            this -> right = NULL;
            this -> left = NULL;
        }
};

void flatten(Node *root)
{
    /* using the famous traversal technique of the binary tree. -> MORRIS Traversal */ 
    Node* curr = root;
    Node *prev;
    
    while(curr != NULL)
    {
        if(curr -> left != NULL)
        {
            // then find the predessor or prev
            prev = curr -> left;
            while(prev->right != NULL)
            {
                prev = prev -> right;
            }
            prev -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;
        }
        
        curr = curr -> right;
    }
}

int main()
{
    
    return 0;
}