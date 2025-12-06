#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================

 Array vs Linked List:
   - Array: contiguous memory, fixed size.
   - Linked List: dynamic size, nodes linked by pointers, not contiguous.

 Node:
   - A user-defined struct (NOT a keyword).
   - Contains "data" + "next" (pointer to another Node).
   - Nodes are allocated using "new" on the heap.

 "->" operator:
   - Access a member of a struct through a pointer.
   - mover->next  ==  (*mover).next

 new:
   - Allocates memory dynamically on heap.
   - Example: Node* temp = new Node(5);

 Memory (64-bit typical):
   - int = 4 bytes
   - pointer = 8 bytes
   - Node ≈ 12 bytes (alignment may round up).

-------------------------------------------------------------------------------
 ASCII DIAGRAM for arr = {2,5,8,7}

   head
     │
     v
   [2 | next] --> [5 | next] --> [8 | next] --> [7 | next=nullptr]

===============================================================================
*/

// --------------------- Node definition ---------------------
struct Node {
    int data;      // stores the value
    Node* next;    // pointer to next Node

    // Constructor (runs when "new Node(x)" is called)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// ---------------- Convert Array to Linked List ---------------
Node* convertArr2LL(vector<int>& arr) {
    // Create the first Node from   arr[0]
    Node* head = new Node(arr[0]);

    // "mover" will always point to the last node we created
    Node* mover = head;

    // Loop for remaining elements
    for (int i = 1; i < arr.size(); i++) {
        // Create a new Node for arr[i]
        Node* temp = new Node(arr[i]);

        //  English: Take the Node that "mover" points to,
        // and set its "next" field to point at this new Node (temp).
        mover->next = temp;

        //  English: Move "mover" forward so it now points to the new last Node.
        mover = temp;
    }
    //  English: Return the address of the first Node (start of list).
    return head;
}
// Time Complexity is O(n)

// ---------------- Print Linked List (Traversal) ---------------
void printLinkedList(Node* head) {
    // English: Start from head, keep moving through "next" until nullptr
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";  //  English: Print current Node's data
        temp = temp->next;          //  English: Jump to the next Node
    }
    cout << endl;
}

int length_of_linked_list (Node* head){
    int count=0;
    Node* temp = head;
    while (temp){
        temp= temp -> next;
        count++;
    }
    return count;

}


// ---------------- Main Function -------------------------------
int main() {
    vector<int> arr = {2, 5, 8, 7};

    //  English: Convert array into a linked list
    Node* head = convertArr2LL(arr);

    // English: Print the data stored in the first Node
    cout << "Head node data: " << head->data << endl;

    cout<<"Length of Linked List is "<<length_of_linked_list(head);

    // English: Print all elements of the linked list
    cout << "Complete Linked List: ";
    printLinkedList(head);

    return 0;
}
