=
---

# Doubly Linked List in C++

This project demonstrates a basic implementation of a **doubly linked list** in C++. The code provides functionalities for inserting nodes, removing nodes, searching for a value, and displaying the list. Each node in the list stores an integer and pointers to both the next and previous nodes, allowing for efficient bidirectional traversal.

## Overview

The key components of this implementation are:

- **Node Structure**:  
  Represents an individual node in the doubly linked list. Each node contains:
  - `data`: An integer value.
  - `next`: A pointer to the next node in the list.
  - `prev`: A pointer to the previous node in the list.

- **DoublyLinkedList Class**:  
  Manages the operations on the list, maintaining pointers to both the `head` and `tail` of the list. The class includes:
  - `insert(int value)`: Adds a new node with the given value to the end of the list.
  - `remove(int value)`: Removes the first node that contains the specified value.
  - `search(int value)`: Searches for a node with the specified value.
  - `display()`: Displays the list from head to tail.
  - A **destructor** that cleans up the allocated memory to prevent memory leaks.

- **Main Function**:  
  Demonstrates the usage of the doubly linked list by:
  - Inserting several nodes.
  - Displaying the list.
  - Searching for a particular value.
  - Removing a node.
  - Displaying the list again after the removal.

## Main Code Snippet

Below is the complete code including the main function:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void remove(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Value not found in the list.\n";
            return;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        delete temp;
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
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~DoublyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Doubly Linked List: ";
    list.display();

    cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << "\n";
    cout << "Deleting 20...\n";
    list.remove(20);

    cout << "Doubly Linked List after deletion: ";
    list.display();

    return 0;
}
```

## How to Compile and Run

1. **Clone the Repository (if applicable)**:  
   If this code is part of a repository, clone it using:
   ```bash
   git clone https://github.com/PJT-2011/Design-and-Analysis-of-Algorithms.git
   cd DAA/DoubleLinkedList
   ```

2. **Compile the Code**:  
   Use a C++ compiler (e.g., `g++`) to compile the code:
   ```bash
   g++ -o doublelinkedlist doublelinkedlist.cpp
   ```

3. **Run the Executable**:  
   Execute the compiled program:
   ```bash
   ./doublelinkedlist
   ```

## Expected Output

After running the program, you should see output similar to the following:

```
Doubly Linked List: 10 <-> 20 <-> 30 <-> 40 <-> NULL
Searching for 20: Found
Deleting 20...
Doubly Linked List after deletion: 10 <-> 30 <-> 40 <-> NULL
```

This confirms that:
- The nodes are inserted correctly.
- The search operation successfully finds the value.
- The deletion operation removes the specified node and the list updates accordingly.

## Asciinema Recording
```bash
https://asciinema.org/a/704468
```

## Conclusion

This project provides a fundamental example of how to implement and manipulate a doubly linked list in C++. The operations demonstrated here serve as a foundation for more advanced data structure manipulations and algorithms. Feel free to modify and expand this code to suit your learning or project needs.

--- 

