#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* root = NULL;

// Insert at beginning
void insert_beginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = root;
    root = new_node;
}

// Insert at end
void insert_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (root == NULL) {
        root = new_node;
        return;
    }

    struct Node* current = root;
    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
}

// Insert at position
void insert_position(int index, int data) {
    if (index == 0) {
        insert_beginning(data);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    struct Node* current = root;
    for (int i = 0; i < index - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL) {
        printf("Index out of range!\n");
        free(new_node);
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Display list
void display() {
    struct Node* current = root;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Delete from beginning
void delete_beginning() {
    if (root == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = root;
    root = root->next;
    free(temp);
}

// Delete from end
void delete_end() {
    if (root == NULL) {
        printf("List is empty\n");
        return;
    }

    if (root->next == NULL) {
        free(root);
        root = NULL;
        return;
    }

    struct Node* current = root;
    while (current->next->next != NULL)
        current = current->next;

    free(current->next);
    current->next = NULL;
}

// Delete at position
void delete_position(int index) {
    if (root == NULL) {
        printf("List is empty\n");
        return;
    }

    if (index == 0) {
        delete_beginning();
        return;
    }

    struct Node* current = root;
    for (int i = 0; i < index - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL || current->next == NULL) {
        printf("Index out of range!\n");
        return;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Search element
void search_element(int data) {
    struct Node* current = root;
    int index = 0;

    while (current != NULL) {
        if (current->data == data) {
            printf("Element %d found at index %d\n", data, index);
            return;
        }
        current = current->next;
        index++;
    }

    printf("Element %d not found\n", data);
}

// Count nodes
int count_nodes() {
    int count = 0;
    struct Node* current = root;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    // Insert
    insert_end(10);
    insert_end(20);
    insert_beginning(5);
    insert_position(2, 15);
    printf("List after insertions: ");
    display();

    // Delete
    delete_beginning();
    delete_end();
    delete_position(1);
    printf("List after deletions: ");
    display();

    // Search
    search_element(10);
    search_element(100);

    // Count
    printf("Number of nodes: %d\n", count_nodes());

    return 0;
}
