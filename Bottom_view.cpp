#include<iostream>
#include<map>
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

vector <int> bottomView(Node *root) {
    
    vector<int> ans;
    
    map<int,int> mapping;
    
    queue< pair< Node* , int> > q;
    
    q.push(make_pair(root, 0));
    
    while( !q.empty())
    {
        pair<Node*, int> p = q.front();
        q.pop();
        
        int distance = p.second;
        Node* newNode = p.first;
        
        mapping[distance] = newNode->data;
        
        if(newNode->left)
            q.push( make_pair(newNode->left, distance -1 ));
            
        if(newNode->right)
            q.push(make_pair(newNode->right, distance + 1));
        
    }
    
    for(auto i:mapping)
        ans.push_back(i.second);
    
    
    return ans;
}

int main()
{
    // question link -> https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
    return 0;
}