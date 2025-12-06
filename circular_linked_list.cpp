#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
/*
You just want my attention luca na
*/
// Insert at head of circular linked list
Node* insertAtHead(Node* head, int val) {
    Node* newnode = new Node(val);
    
    if (head == nullptr) {
        // First node - points to itself
        newnode->next = newnode;
        return newnode;
    }
    
    // Find tail (node that points back to head)
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    
    // Insert at head
    newnode->next = head;
    tail->next = newnode;
    return newnode;  // New node becomes head
}

Node * insertAtTail(Node* head, int val)
{
    Node* newnode= new Node (val);
    if (head==nullptr)
    {
        newnode->next=newnode;
        return newnode;
    }
    Node* tail= head;

        while (tail->next!=head)
        {
            tail=tail->next;
        }
    
        
}

// Print circular linked list
void print(Node* head) {
    if (head == nullptr) {
        cout << "Empty circular linked list" << endl;
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
}

int main() {
    Node* head = nullptr;
    
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 15);
    
    print(head);
    
    return 0;
}
/*
My name is Naman Vasudev and I am the destroyer of the worlds and I will kill the five  
*/