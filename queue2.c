#include<stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Checks if the queue is empty
int isEmpty()
{
    return front == -1 || front > rear;
}

// Checks if the queue is full
int isFull()
{
    return rear == MAX - 1;
}

// Adds an element to the queue
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }

    if (isEmpty())
    {
        front = 0;
    }

    rear++;
    queue[rear] = value;
    printf("%d enqueued to queue\n", value);
}

// Removes an element from the queue
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
    }
    else
    {
        int value = queue[front];
        front++;
        printf("Dequeued value: %d\n", value);
    }
}

// Shows the front element
void peek()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

// Displays all elements in the queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();       // Shows all elements

    dequeue();       // Removes 10
    peek();          // Shows front element: 20
    display();       // Shows 20 and 30

    dequeue();       // Removes 20
    dequeue();       // Removes 30
    dequeue();       // Underflow (queue is empty)

    return 0;
}
/*10 enqueued to queue
20 enqueued to queue
30 enqueued to queue
Queue elements are: 10    20    30
Dequeued value: 10
Front element: 20
Queue elements are: 20    30
Dequeued value: 20
Dequeued value: 30
Queue Underflow*/
