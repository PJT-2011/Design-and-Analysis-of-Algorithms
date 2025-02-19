Below is the content you can include in your **README.md** file:

---

# Singly Linked List in C++

This project demonstrates a basic implementation of a **singly linked list** in C++. The code provides functionalities for inserting nodes, removing nodes, searching for a specific value, and displaying the list. Each node in the list stores an integer value and a pointer to the next node.

## Overview

The implementation includes the following components:

- **Node Structure**:  
  A simple structure that represents an individual node in the list. Each node contains:
  - `data`: An integer value.
  - `next`: A pointer to the next node in the list.

- **SinglyLinkedList Class**:  
  This class manages the linked list operations and maintains a pointer to the `head` (the first node) of the list. The main methods include:
  - `insert(int value)`: Inserts a new node with the specified value at the end of the list.
  - `remove(int value)`: Removes the first occurrence of a node with the specified value.
  - `search(int value)`: Searches for a node containing the given value.
  - `display()`: Prints out all the nodes in the list.
  - A **destructor** to free the allocated memory and prevent memory leaks.

- **Main Function**:  
  Demonstrates the usage of the singly linked list by:
  - Inserting several nodes.
  - Displaying the list.
  - Searching for a value.
  - Removing a node.
  - Displaying the list again after deletion.

## Main Code Snippet

Below is the complete code including the main function:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void remove(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Value not found in the list.\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~SinglyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Linked List: ";
    list.display();

    cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << "\n";
    cout << "Deleting 20...\n";
    list.remove(20);

    cout << "Linked List after deletion: ";
    list.display();

    return 0;
}
```

## How to Compile and Run

1. **Clone the Repository (if applicable)**:  
   If this code is part of a repository, clone it using:
   ```bash
   git clone https://github.com/PJT-2011/Design-and-Analysis-of-Algorithms.git
   cd DAA/SinglyLinkedList
   ```

2. **Compile the Code**:  
   Use a C++ compiler such as `g++` to compile the code:
   ```bash
   g++ -o singlylinkedlist SinglyLinkedList.cpp
   ```

3. **Run the Executable**:  
   Execute the compiled program:
   ```bash
   ./singlylinkedlist
   ```

## Expected Output

When you run the program, you should see output similar to:

```
Linked List: 10 -> 20 -> 30 -> 40 -> NULL
Searching for 20: Found
Deleting 20...
Linked List after deletion: 10 -> 30 -> 40 -> NULL
```

This output confirms that:
- The nodes are inserted correctly.
- The search operation finds the specified value.
- The removal operation successfully deletes the node with the value `20`, and the list updates accordingly.

## Conclusion

This project provides a simple example of how to implement and manage a singly linked list in C++. It covers basic operations such as insertion, deletion, search, and display, and serves as a good starting point for learning about linked data structures in C++.

---

