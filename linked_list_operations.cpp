# include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int data1)
    {
        data=data1;
        next=nullptr;
    }

};

Node* convert_arr_to_ll (vector <int> &arr)
{
    Node* head= new Node(arr[0]);
    Node* mover= head;

    for (int i=1; i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;


    }
    return head;
}

void print(Node* head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;

}


Node* delete_head (Node*head)
{
    if (head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* delete_tail (Node* head){
    Node* temp=head;
    if (head==NULL || head->next==NULL) return NULL;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }   
    free(temp->next);
    temp->next=nullptr;
    return head;

}

Node* delele_k_th_element (Node* head, int k)
{
    if (head== NULL) return head;
    if (k==1)
    {
        Node* temp= head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node*temp = head;
    Node*prev=nullptr;
    while(temp!=NULL)
    {
        cnt++;
        if (cnt==k)
        {
            prev->next=prev->next->next;
            free(temp);

            break;
            
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* delete_element_value (Node* head, int element)
{
    if (head== NULL) return head;
    if (head->data==element)
    {
        Node* temp= head;
        head=head->next;
        free(temp);
        return head;
    }

    Node*temp = head;
    Node*prev=nullptr;
    while(temp!=NULL)
    {

        if (temp->data==element)
        {
            prev->next=prev->next->next;
            free(temp);
            break;            
        }

        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* insert_head(Node* head, int value)
{
    Node* temp= new Node(value);
    temp->next=head;
    return temp;
}
Node* insert_tail(Node* head, int value)
{   if (head==NULL) return (new Node(value));
    Node*temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newnode=new Node(value);
    temp->next=newnode;

    return head;
}
Node* insert_k_th(Node* head, int value, int k)
{
    if (head == NULL) {
        if (k == 1) return new Node(value);
        else return NULL;
    } 

    if (k == 1) {
        Node* temp = new Node(value);
        temp->next = head;
        return temp;
    }

    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        cnt++;
        if (cnt == k - 1) {
            Node* inserted_node = new Node(value);
            inserted_node->next = temp->next;
            temp->next = inserted_node;
            return head;
        }
        temp = temp->next;
    }

    return head; // if k > length, no insertion
}

Node* insert_element_before_existing_value(Node* head, int existing_value, int element)
{
    if (head == NULL) {
    return NULL;
    } 

    if (head->data==existing_value) {
        Node* temp = new Node(element);
        temp->next = head;
        return temp;
    }

    Node* temp = head;
    while (temp->next != NULL) {

        if (temp->next->data == existing_value) {
            Node* inserted_node = new Node(element);
            inserted_node->next = temp->next;
            temp->next = inserted_node;
            return head;
        }
        temp = temp->next;
    }

    return head; // if k > length, no insertion
}

int main(){
    vector<int> arr={12,5,8,7};
    Node*head = convert_arr_to_ll(arr);
    // head=delete_head(head);
    // head=delete_tail(head);
    // head=delele_k_th_element(head,3);
    // head=delete_element_value(head,5);  
    // head=insert_head(head,100);
    // head=insert_tail(head,100);
    // head=insert_k_th(head,10,1);
    // head=insert_element_before_existing_value(head,2,100);

    print(head);
    
}