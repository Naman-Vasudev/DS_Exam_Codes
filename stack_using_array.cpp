// Stack implementation using array in C++, Stack uses LIFO (Last In First Out) principle.


#include <iostream>
using namespace std;

// Define the maximum size of the stack, define max is a preprocessor directive.
#define MAX 1000

class Stack {
    int top;      // To keep track of the topmost element index
    int stack[MAX]; // Array to store stack elements, hence time complexity will be O(MAX)

public:
    Stack() {
        top = -1; // Initially stack is empty
    }

    // Push operation: Add an element on top of the stack
    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top+=1;
        stack[top] = x; // Increment top and insert element

        // Time complexity is O(1)
    }

    // Pop operation: Remove the top element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return;
        }
        top -= 1; // Simply decrement top to remove element

        // Time complexity is O(1)        
    }

    // Get the top element of the stack without removing it
    int Top() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return stack[top]; // Return the topmost element

        // Time complexity is O(1)        
    }

    // Return the current size of the stack
    int size() {
        return top + 1; // As index starts from 0, size is top+1

        // Time complexity is O(1)        
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
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
