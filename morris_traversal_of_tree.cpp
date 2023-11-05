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

void MorrisTraversal(Node* root)
{
    if(root == NULL)
        return ;

    // we need two iterator.
    Node * current, * previous;
    current = root;

    while(current != NULL)
    {
        if(current -> left == NULL)
        {
            cout<< current->data<<" ";
            current = current -> right;
        }

        else{
            // then find the predecessor of current.
            previous = current -> left;
            while(previous != NULL && previous -> right != current)
                previous = previous->right;

            // make the link from the previous to the current node.
            if(previous -> right == NULL){
                previous -> right = current;
                current = current -> left;
            }

            // remove the made link from the previous to the current.

            else{
                previous -> right = NULL;
                cout<<current->data<<" ";
                current = current -> right;
            }
        }
    }
}

int main()
{
    
    return 0;
}