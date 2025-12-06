// Stack implementation using Linked List in C++, Stack uses LIFO (Last In First Out) principle.

#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top; // Pointer to the topmost node

public:
    Stack() {
        top = NULL; // Initially stack is empty
    }

    // Push operation: Add an element on top of the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow (no memory)\n";
            return;
        }
        Node* newnode = new Node(); // Dynamically create node
        newnode->data = x;          // Assign value
        newnode->next = top;        // Point to previous top
        top = newnode;              // Move top to new node

        // Time complexity is O(1)
    }

    // Pop operation: Remove the top element from the stack
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;    // Store current top
        top = top->next;     // Move top pointer to next node
        delete temp;         // Free memory of old top

        // Time complexity is O(1)
    }

    // Get the top element of the stack without removing it
    int Top() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data; // Return the topmost element

        // Time complexity is O(1)
    }

    // Return the current size of the stack
    int size() {
        int count = 0;
        Node* temp = top;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;

        // Time complexity is O(n) where n is number of elements
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top == NULL);

        // Time complexity is O(1)
    }

    // Check if the stack is full (memory not available)
    bool isFull() {
        // Try allocating memory safely
        Node* temp = new(nothrow) Node;
        if (temp == NULL) {
            return true; // Memory not available
        }
        delete temp; // Free test allocation
        return false;

        // Time complexity is O(1)
    }

    // Display all elements in the stack
    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements are: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;

        // Time complexity is O(n) where n is number of elements
    }

    // Destructor to free all allocated memory
    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.push(6); // Push 6 into stack
    s.push(3); // Push 3 into stack
    s.push(7); // Push 7 into stack

    cout << "Top element is: " << s.Top() << endl; // Display top element

    s.pop(); // Remove top element (7)
    cout << "Top after pop: " << s.Top() << endl; // Display new top

    cout << "Stack size is: " << s.size() << endl; // Display current size

    if (s.isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";
    
    s.display(); // Display all stack elements

    return 0;
}