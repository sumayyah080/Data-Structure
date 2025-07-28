#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
//checking if stack is empty
int isEmpty()
{
    return top==-1;
}
//checking if is it full
int isFull()
{
    return top==MAX-1;

}
void push(int value)
{
    if(isFull())
    {
        printf("Overflow\n");
        return;
    }

    else
    {
        top++;
        stack[top]=value;
        printf("%d pushed to stack\n",value);
    }
}
void pop()
{
    if(isEmpty())
    {
        printf("Underflow\n");
    }
    else
    {
       int value=stack[top];
        top--;
        printf("popped value: %d\n",value);
    }
}
//peek function
void peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("top element: %d\n",stack[top]);
    }

}
//display function
 void display()
{

    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {

printf("Stack Elemnts are: ");
for(int i=top; i>=0; i--)
{
    printf("%d\t",stack[i]);
}
printf("\n");
    }
} 
int main() 
{
    push(10);
    push(20);
    push(30);
    display(); //should show

    pop();
    peek();
    display();

    pop();
    pop();
    pop(); //should show underflow
    return 0;
}
/*
======== Output ========
10 pushed to stack
20 pushed to stack
30 pushed to stack
Stack Elements are: 30	20	10
popped value: 30
Top element: 20
Stack Elements are: 20	10
popped value: 20
popped value: 10
Underflow
*/

