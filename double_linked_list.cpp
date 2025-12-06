# include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;
    Node (int data1)
    {
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};

Node* convert_arr_to_dll(vector<int> &arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        temp->back = prev;       // Connect backward
        prev->next = temp;       // Connect forward
        prev = temp;
    }

    return head;
}

void print(Node* head)
{
    Node* temp= head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node * delete_head(Node* head)
{
    if (head==NULL || head->next==NULL)
    {
        return nullptr;
    }
    Node* prev= head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}

Node* delete_tail(Node* head)
{
    if (head == nullptr)
        return nullptr;

    // Case: Only one node in the list
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    // Traverse to the tail
    Node* tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    // tail is now the last node
    Node* newtail = tail->back;
    newtail->next = nullptr;

    delete tail;
    return head;
}

Node * delete_k_th_element(Node* head, int k)

{
    if (head==nullptr) return nullptr;
    int cnt=0;
    Node* knode= head;
    while(knode!=NULL)
    {
        cnt++;
        if (cnt==k) break;
        knode=knode->next;

    }

    Node* prev= knode->back;
    Node* front= knode ->next;

    if (prev==NULL && front==NULL) return nullptr;
    else if (prev==NULL) {
        return delete_head(head);
    }
    else if (front==NULL) {
        return delete_tail(head);
    }
    prev->next=front;
    front->back=prev;
    knode->next=nullptr;
    knode->back=nullptr;
    delete knode;
    return head;
}

void deleteNode(Node* temp)
{
    Node* prev= temp->back;
    Node* front= temp->next;

    if (front==NULL)
    {
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
    }
    prev->next=front;
    front->back=prev;
    temp->back=nullptr;
    temp->next=nullptr;
    delete temp;
}
    
Node* insert_before_head (Node* head, int val)
{
    Node* new_head= new Node(val);
    new_head->back=nullptr;
    new_head->next=head;
    head->back=new_head;
    return new_head;
}

Node* insert_before_tail (Node* head, int val)
{   if (head->next==nullptr) return insert_before_head(head, val);
    Node* tail =head;
    while(tail->next!=nullptr)
    {
        tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newNode= new Node(val);
    newNode->next=tail;
    newNode->back=prev;
    prev->next=newNode;
    tail->back=newNode;
    return head;
}

Node* insert_before_kth_element (Node* head, int k, int value)
{   
    if (k==1)
    {
        return insert_before_head(head,value);
    }
    Node* temp = head;
    int cnt=0;
    while (temp!=NULL)
    {
        cnt++;
        if (cnt==k)
        {
         break;   
        }
        temp=temp->next;
    }
    Node* prev= temp->back;
    Node* newNode= new Node (value);
    newNode->next=temp;
    newNode->back= prev;
    prev->next=newNode;
    temp->back=newNode;
    return head;
}

void insert_before_a_node (Node* node, int val)
{
    Node* prev= node->back;
    Node* newNode= new Node(val);
    newNode->next=node;
    newNode->back=prev;
    prev->next=newNode;
    node->back=newNode;
}

int main(){
    vector<int> arr={12,5,8,7};
    Node*head = convert_arr_to_dll(arr);
    // head=delete_head(head);
    // head=delete_tail(head);
    // head=delete_k_th_element(head,2);
    // deleteNode(head->next);
    // head=insert_before_head(head,100);
    // head=insert_before_tail(head,100);
    // head=insert_before_kth_element(head, 3, 10);
    // insert_before_a_node(head->next,100);
    print(head);


}