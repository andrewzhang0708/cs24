#include "List.h"

#include <iostream>

// List Member Functions

// Constructor
List::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Destructor
List::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Helper Functions

// Member Functions
List::Node* List::insert(const std::string& key, int value) {
    // insert a new node with the given key and value, and return the new node

    Node* newNode = new Node(key, value, nullptr, tail);

    // Update the head
    if (head == nullptr) {
        head = newNode;
    }

    // Update the tail
    if (tail != nullptr) {
        // Update the next pointer of the previous tail
        tail->next = newNode;
    }
    tail = newNode;

    size++;
    return newNode;
}

void List::remove(List::Node* node) {
    // remove the given node from the list and return it

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    size--;
    delete node;
}

int List::getTotal() {
    // return the sum of all values in the list using iterators
    int total = 0;
    Node* current = head;
    while (current != nullptr) {
        total += current->value;
        current = current->next;
    }
    return total;
}

size_t List::getSize() {
    return size;
}