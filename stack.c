#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
int isEmpty();
int isFull();
void push(int value);
void pop();
void peek();
void display();
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
