/*
Front: Position of the entry in a queue ready to be served, that is, the first entry that will be removed from the queue, is called the front of the queue. It is also referred as the head of the queue.

Rear: Position of the last entry in the queue, that is, the one most recently added, is called the rear of the queue. It is also  referred as the tail of the queue.

Size: Size refers to the current number of elements in the queue.

Capacity: Capacity refers to the maximum number of elements the queue can hold

Queue Operations

1. Enqueue: Adds an element to the end (rear) of the queue. 
   If the queue is full, an overflow error occurs.

2. Dequeue: Removes the element from the front of the queue.                                        If the queue is empty, an underflow error occurs.

3. FrontPeek : Returns the element at the front without removing it. ( O(1) time complexity)

4. RearPeek : Returns the element at the rear without removing it. ( O(1) time complexity)

5. Size: Returns the number of elements in the queue.

6. isEmpty: Returns true if the queue is empty, otherwise false.

7. isFull: Returns true if the queue is full, otherwise false.
*/

// Queue implementation using array in C++, Queue uses FIFO (First In First Out) principle.

#include <iostream>
using namespace std;

// Define the maximum size of the queue, define Capacity is a preprocessor directive.
#define Capacity 1000

class Queue {
    int front;      // To keep track of the front element index
    int rear;       // To keep track of the rear element index
    int currSize;   // To keep track of current number of elements
    int queue[Capacity]; // Array to store queue elements, hence space complexity will be O(Capacity)

public:
    Queue() {
        front = -1;   // Initially queue is empty
        rear = -1;    // Initially queue is empty
        currSize = 0; // Initially no elements
    }

    // Enqueue operation: Add an element at the rear of the queue
    // Inserts element at the end using circular array implementation
    void enqueue(int x) {
        if (currSize == Capacity) {
            cout << "Queue Overflow\n";
            return;
        }
        
        if (rear == -1) {
            // First element being inserted
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % Capacity; // Circular increment
        }
        
        queue[rear] = x;
        currSize++;
        
        // Time complexity is O(1)
    }

    // Dequeue operation: Remove the front element from the queue
    // Removes element from the front using circular array implementation
    void dequeue() {
        if (currSize == 0) {
            cout << "Queue Underflow\n";
            return;
        }
        
        if (currSize == 1) {
            // Last element being removed
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % Capacity; // Circular increment
        }
        
        currSize--;
        
        // Time complexity is O(1)
    }

    // Front/Peek operation: Get the front element without removing it
    // Returns the element at the front of the queue
    int Front() {
        if (currSize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[front]; // Return the front element
        
        // Time complexity is O(1)
    }

    // Rear/Peek operation: Get the rear element without removing it
    // Returns the element at the rear of the queue
    int Rear() {
        if (currSize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[rear]; // Return the rear element
        
        // Time complexity is O(1)
    }

    // Size operation: Return the current number of elements in the queue
    int size() {
        return currSize;
        
        // Time complexity is O(1)
    }

    // isEmpty operation: Check if the queue is empty
    // Returns true if queue has no elements, otherwise false
    bool isEmpty() {
        return currSize == 0;
        
        // Time complexity is O(1)
    }

    // isFull operation: Check if the queue is full
    // Returns true if queue has reached maximum capacity, otherwise false
    bool isFull() {
        return currSize == Capacity;
        
        // Time complexity is O(1)
    }

    // Display operation: Show all elements in the queue from front to rear
    void display() {
        if (currSize == 0) {
            cout << "Queue is empty\n";
            return;
        }
        
        cout << "Queue elements are: ";
        int count = 0;
        int i = front;
        
        while (count < currSize) {
            cout << queue[i] << " ";
            i = (i + 1) % Capacity; // Circular increment
            count++;
        }
        cout << endl;
        
        // Time complexity is O(n) where n is number of elements
    }
};

int main() {
    Queue q;

    q.enqueue(6); // Enqueue 6 into queue
    q.enqueue(3); // Enqueue 3 into queue
    q.enqueue(7); // Enqueue 7 into queue

    cout << "Front element is: " << q.Front() << endl; // Display front element
    cout << "Rear element is: " << q.Rear() << endl;   // Display rear element

    q.dequeue(); // Remove front element (6)
    cout << "Front after dequeue: " << q.Front() << endl; // Display new front

    cout << "Queue size is: " << q.size() << endl; // Display current size

    if (q.isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";
    
    if (q.isFull())
        cout << "Queue is full\n";
    else
        cout << "Queue is not full\n";
    
    q.display(); // Display all queue elements
    
    // Testing more operations
    q.enqueue(9);
    q.enqueue(12);
    
    cout << "\nAfter adding more elements:\n";
    q.display();
    cout << "Queue size is: " << q.size() << endl;

    return 0;
}
