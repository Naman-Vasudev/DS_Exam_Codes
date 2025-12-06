#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node (int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
static int index=-1;
Node * buildtree(vector <int> preorder)
{
    index++;

    if (preorder[index]==-1)
    {
        return nullptr;
    }

    Node* root = new Node (preorder[index]);
    root->left=buildtree(preorder);
    root->right=buildtree(preorder);
    return root;


}
//ROOT LEFT RIGHT
void preorder_traversal(Node* root)
{
    if (root==nullptr)
    {
        return;
    }
    cout<<root->data<<" ";

    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
//LEFT ROOT RIGHT

void inorder_traversal(Node* root)
{
    if (root==nullptr)
    {return;}
    inorder_traversal(root->left);
    cout<<root->data<<" "; 
    inorder_traversal(root->right);

}
//LEFT RIGHT ROOT

void postorder_traversal(Node* root)
{
    if (root==nullptr)
    {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" "; 
}

void level_order_traversal(Node* root)
{
   queue <Node*> q;
   q.push(root);
   while (q.size()>0)
   {
    Node* curr= q.front();
    q.pop();
    cout<<curr->data<<" ";
    if (curr->left!=nullptr)
    {
        q.push(curr->left);
    }
    if (curr->right!=nullptr)
    q.push(curr->right);
   }
}

int main()
{
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root= buildtree(preorder);
    cout<<root->data<<endl;
    preorder_traversal(root);
    cout<<endl;
    inorder_traversal(root); 
    cout<<endl;
    postorder_traversal(root);   
    cout<<endl;
    level_order_traversal(root);
    return 0;
}