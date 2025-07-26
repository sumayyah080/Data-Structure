#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Insert at beginning
void insertAtBeginning(int data) {
    Node* newNode = new Node{data, nullptr, head};
    if (head != nullptr)
        head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Inserting in a specific position 
void insertAtPosition(int pos, int data) {
    if (pos == 0) {
        insertAtBeginning(data);
        return;
    }

    Node* temp = head;
    for (int i = 0; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Invalid position!\n";
        return;
    }

    Node* newNode = new Node{data, temp, temp->next};
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Deleting from beginning
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
}

// Deleting from end
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    if (temp->next == nullptr) {
        delete temp;
        head = nullptr;
        return;
    }

    while (temp->next != nullptr)
        temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

// Deleting from specific position
void deleteFromPosition(int pos) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 0) 
    {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 0; temp != nullptr && i < pos; i++)
        temp = temp->next;

    if (temp == nullptr) 
    {
        cout << "Invalid position!\n";
        return;
    }

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;
    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
}

// Display forward
void displayForward() 
{
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display backward
void displayBackward() 
{
    if (head == nullptr) 
    {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    cout << "Backward: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeginning(5);
    insertAtPosition(2, 15);

    displayForward();   
    displayBackward();  

    deleteFromBeginning();
    deleteFromEnd();
    deleteFromPosition(1);

    displayForward();   

    return 0;
}
