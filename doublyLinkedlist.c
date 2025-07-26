#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) 
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Inserting in specific position
void insertAtPosition(int pos, int data) 
{
    if (pos == 0) {
        insertAtBeginning(data);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) 
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Deleting from beginning
void deleteFromBeginning() 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

// Deleting from end
void deleteFromEnd() 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (temp->next == NULL) 
    {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

// Deleting from specificposition
void deleteFromPosition(int pos) 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    if (pos == 0) 
    {
        deleteFromBeginning();
        return;
    }
    struct Node* temp = head;
    for (int i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) 
    {
        printf("Invalid position\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

// Display
void displayList() 
{
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() 
{
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(1, 15); 

    displayList();

    deleteFromBeginning();   
    deleteFromEnd();       
    deleteFromPosition(1); 

    displayList();

    return 0;
}
