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

Node* insert(Node* root, int val)
{
    if (root==NULL)
    {
        return new Node(val);
    }

    if (root->data > val)
    {
        root->left=insert(root->left, val);
    }
    else if (root->data < val)
    {
        root->right=insert(root->right, val);
    }
    return root;
}


Node* buidBST(vector <int> arr)
{
    Node* root= nullptr;
    for (int val: arr)
    {
        root=insert(root,val);
    }
    return root;

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

bool search(Node* root, int key)
{
    if (root==nullptr) return false;

    if (root->data==key)
    {
        return true;
    }

    if (key<root->data)
    {
       return search(root->left, key);
    }
    else return search(root->right, key);
}

Node * get_in_order_successor(Node* root)
{
    while (root!=nullptr && root->left!=nullptr)
    {
        root=root->left;
    }
    return root;
}

Node* deletenode(Node* root, int key)
{
    if (root==nullptr) return nullptr;
    if (key<root->data)
    {
        root->left=deletenode(root->left, key);
    }
    else if (key>root->data)
    {
        root->right=deletenode(root->right, key);
    }
    else
    {
        if (root->left==nullptr)
        {
            Node* temp= root->right;
            delete root;
            return temp;
        }
        else if (root->right==nullptr)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node* inorder_succesor= get_in_order_successor(root->right);
            root->data=inorder_succesor->data;
            root->right=deletenode(root->right, inorder_succesor->data);
        }
    }
    return root;

}

int main()
{
    vector <int> arr= {3,2,1,5,6,4};
    Node* root= buidBST(arr);
    inorder_traversal(root);
    cout<<endl;
    cout<<search(root,5);
    cout<<search(root,9);
}