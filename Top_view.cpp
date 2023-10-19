#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

vector<int> topView(Node *root)
{
    vector<int> ans;
    
    // make the mapping of horizontal distance with the nodes.
    // here first int -> horizontal distance
    // second int -> value of node
    map<int,int> mapping;
    
    // here int in pair is for horizontal distance
    queue< pair< Node* , int > > q;
    
    q.push(make_pair(root,0));
    
    while( !q.empty() )
    {
        pair< Node*, int > temp = q.front();
        q.pop();
        
        Node* node = temp.first;
        
        int distance = temp.second;
        
        // if the mapping exist with the horizontal distance then, don't do anything.
        // else if not then make the mapping
        if( mapping.find(distance) == mapping.end() ) // it means the mapping doesn't exist
            mapping[distance] = node->data;
            
        if(node->left)
            q.push(make_pair(node->left, distance-1));
            
        if(node->right)
            q.push(make_pair(node->right, distance + 1));
    }
    
    
    // we need to print only the node that are visible from the top, that are stored in mapping
    for(auto i : mapping)
        ans.push_back(i.second);
    
    
    return ans;
}

int main()
{
    cout<<"this program will show the top view of the binary tree."<<endl;

    // question link -> https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
    return 0;
}