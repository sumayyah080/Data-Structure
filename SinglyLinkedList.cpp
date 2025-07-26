#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* root = nullptr;

// Insert at beginning
void insert_beginning(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = root;
    root = new_node;
}

//  Insert at end
void insert_end(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;

    if (root == nullptr) {
        root = new_node;
        return;
    }
    Node* current = root;
    while (current->next != nullptr)
        current = current->next;
    current->next = new_node;
}

//  Insert at specific position
void insert_position(int index, int data) {
    if (index == 0) {
        insert_beginning(data);
        return;
    }
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;

    Node* current = root;
    for (int i = 0; i < index - 1 && current != nullptr; i++)
        current = current->next;

    if (current == nullptr) {
        cout << "index out of limit!!\n";
        delete new_node;
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
}

// Display list
void display() {
    Node* current = root;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//  Delete from beginning
void delete_beginning() {
    if (root == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = root;
    root = root->next;
    delete temp;
}

//  Delete from end
void delete_end() {
    if (root == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (root->next == nullptr) {
        delete root;
        root = nullptr;
        return;
    }
    Node* current = root;
    while (current->next->next != nullptr)
        current = current->next;
    delete current->next;
    current->next = nullptr;
}

//  Delete from specific position
void delete_position(int index) {
    if (root == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (index == 0) {
        delete_beginning();
        return;
    }
    Node* current = root;
    for (int i = 0; i < index - 1 && current != nullptr; i++)
        current = current->next;

    if (current == nullptr || current->next == nullptr) {
        cout << "index out of limit\n";
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

//  Search for element
void search_element(int data) {
    Node* current = root;
    int index = 0;
    while (current != nullptr) {
        if (current->data == data) {
            cout << "found at index " << index << "\n";
            return;
        }
        current = current->next;
        index++;
    }
    cout << "not found\n";
}

//  Count nodes
int count_nodes() {
    int count = 0;
    Node* current = root;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    // for Insertions
    insert_end(10);
    insert_end(20);
    insert_beginning(5);
    insert_position(2, 15);
    cout << "List after insertions: ";
    display();

    // for Deletions
    delete_beginning();
    delete_end();
    delete_position(1);
    cout << "list after deletions: ";
    display();

    // Searching
    search_element(10);
    search_element(100);

    //Count
    cout << "Number of nodes: " << count_nodes() << endl;

    return 0;
}
