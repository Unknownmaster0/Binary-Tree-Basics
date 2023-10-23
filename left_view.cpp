#include<iostream>
#include<queue>
#include<map>
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

/*
vector<int> leftView(Node *root)
{
   // we need to do the mapping of the level with the node->data.
//   if the particular level is already mapped with some value, then don't push the new element.

    vector<int> ans;
    if(root == NULL)
        return ans;
    
    map<int,int> mapping;
    
    queue< pair< Node*, int > > q;
    
    q.push( make_pair(root,0) );
    
    while(!q.empty())
    {
        pair< Node*, int> p = q.front();
        q.pop();
        
        int level = p.second;
        
        Node* newNode = p.first;
        
        if( mapping.find(level) == mapping.end() )
            mapping[level] = newNode->data;
            
            
        if(newNode->left )
            q.push(make_pair(newNode->left,level+1));
        if(newNode->right)
            q.push(make_pair(newNode->right, level+1));
    }
    
    for(auto i:mapping)
        ans.push_back(i.second);
        
    return ans;
}
*/

// left view using the recursion
void leftView(Node* root, int level, vector<int>& ans)
{
    if(root == NULL)
        return;

    if(level == ans.size())
        ans.push_back(root->data);

// go to left of the root
    leftView(root->left, level+1, ans);
// go to the right of the root.
    leftView(root->right, level+1, ans);
}

int main()
{
    // question link -> https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
    return 0;
}