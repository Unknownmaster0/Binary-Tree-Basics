#include<iostream>
#include<vector>
#include<stack>
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

Node * buildTree(Node *root)
{
    printf("enter data: ");
    int num;
    cin >> num;

    root = new Node(num);

    // base case :
    if (num == -1)
        return NULL;

    cout << "enter the data to fill on left of -> " << num << endl;

    root->left = buildTree(root->left);

    cout << "enter the data to fill on right -> " << num << endl;

    root->right = buildTree(root->right);

    return root;
}

// Preorder traversal in the iterative way
// For preorder traversal -> root , left, right
vector<int> preOrder(Node* root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    stack<Node*> st;
    st.push(root);

    while( !st.empty())
    {
        Node* temp = st.top();
        st.pop();

        ans.push_back(temp->data);
        if(temp->right)
            st.push(temp->right);

        if(temp->left)
            st.push(temp->left);
    }

    return ans;
}

// Postorder traversal in iterative way, and using the two stack.
vector<int> postOrder(Node* root)
{
    vector<int> ans;
    stack<Node*> st1;
    stack<Node*> st2;

    st1.push(root);

    while(!st1.empty())
    {
        Node* temp = st1.top();
        st1.pop();

        st2.push(temp);
        if(temp->left)
            st1.push(temp->left);
        if(temp->right)
            st1.push(temp->right);
    }

    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }

    return ans;
}

// Inordere traversal 
vector<int> inOrder(Node* root)
{
    vector<int> ans;

    stack<Node*> st;

    Node* temp = root;

    while(true)
    {
        if(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty())
                break;

            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }

    return ans;
}

void printVector(vector<int> arr)
{
    for(int i = 0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);

    vector<int> pre = preOrder(root);
    cout<<"preOrder Traversal -> ";
    printVector(pre);
    cout<<endl;
    vector<int> post = postOrder(root);
    cout<<"postOrder Traversal -> ";
    printVector(post);
    cout<<endl;
    vector<int> inorder = inOrder(root);
    cout<<"inOrder Traversal -> ";
    printVector(inorder);
    cout<<endl;
    return 0;
}