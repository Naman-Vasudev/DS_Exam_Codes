#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to traverse and print the queue
void traverseQueue(Node* front) {
    if (front == nullptr) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements (front → rear): ";
    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Enqueue operation (insert at rear)
void enqueue(Node*& front, Node*& rear, int value) {
    Node* newNode = new Node{value, nullptr};
    if (rear == nullptr) { // Queue empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued\n";
}

// Dequeue operation (remove from front)
void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) { // Queue empty
        cout << "Queue Underflow (empty queue)\n";
        return;
    }
    Node* temp = front; // store old front
    cout << temp->data << " dequeued\n";
    front = front->next; // move front forward
    if (front == nullptr) { // if queue became empty
        rear = nullptr;
    }
    delete temp; // free memory
}

// FrontPeek: return front element without removing
void frontPeek(Node* front) {
    if (front == nullptr) {
        cout << "Queue is empty\n";
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

// RearPeek: return rear element without removing
void rearPeek(Node* rear) {
    if (rear == nullptr) {
        cout << "Queue is empty\n";
    } else {
        cout << "Rear element: " << rear->data << endl;
    }
}

// Size: count number of elements
int size(Node* front) {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// isEmpty: check if queue is empty
bool isEmpty(Node* front) {
    return (front == nullptr);
}

// isFull: for linked list implementation, always false
bool isFull() {
    return false; // can't be full unless system memory ends
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // Insert elements in queue
    enqueue(front, rear, 10);
    enqueue(front, rear, 20);
    enqueue(front, rear, 30);

    // Traversing queue
    traverseQueue(front);

    // Remove one element
    dequeue(front, rear);
    traverseQueue(front);

    // Insert more
    enqueue(front, rear, 40);
    traverseQueue(front);

    // Remove all elements
    dequeue(front, rear);
    dequeue(front, rear);
    dequeue(front, rear);  // this will empty the queue
    traverseQueue(front);

    // Refill and check peek/size/isEmpty/isFull
    enqueue(front, rear, 50);
    enqueue(front, rear, 60);
    frontPeek(front);
    rearPeek(rear);

    cout << "Queue size: " << size(front) << endl;
    cout << "Is queue empty? " << (isEmpty(front) ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (isFull() ? "Yes" : "No") << endl;

    // cleanup remaining nodes
    while (!isEmpty(front)) dequeue(front, rear);

    return 0;
}
