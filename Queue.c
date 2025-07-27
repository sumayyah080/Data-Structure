#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() 
{
    return rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Enqueue function
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty()) front = 0;
    rear++;
    queue[rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Dequeue function
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    front++;
}

// Display function
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Peek function - Optional
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Main function - Manual (hardcoded) test
int main() {
    // Initial enqueues
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    // Dequeue one element
    dequeue();
    display();

    // More enqueue operations
    enqueue(40);
    enqueue(50);
    display();

    // Peek front element
    peek();

    // Dequeue all to test underflow
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // This will show underflow
    display();

    return 0;
}

// Output will be like this:
// 10 enqueued to the queue.
// 20 enqueued to the queue.
// 30 enqueued to the queue.
// Queue elements: 10 20 30
// 10 dequeued from the queue.
// Queue elements: 20 30
// 40 enqueued to the queue.
// 50 enqueued to the queue.
// Queue elements: 20 30 40 50
// Front element: 20
// 20 dequeued from the queue.
// 30 dequeued from the queue.
// 40 dequeued from the queue.
// 50 dequeued from the queue.
// Queue Underflow!
// Queue is empty.
