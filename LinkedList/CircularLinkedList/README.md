
---

# Circular Linked List in C++

This project demonstrates a simple implementation of a **circular linked list** in C++. The code supports fundamental operations such as insertion, deletion, searching, and displaying the list elements.

## Overview

The project consists of the following key components:

- **Node Structure**:  
  Defines a node in the linked list with an integer `data` and a pointer `next` to the next node.

- **CircularLinkedList Class**:  
  Encapsulates all functionalities for managing the circular linked list. It includes:
  - `insert(int value)`: Inserts a new node into the list.
  - `remove(int value)`: Removes a node with the specified value from the list.
  - `search(int value)`: Searches for a node containing the specified value.
  - `display()`: Displays the list starting from the head node.
  - **Destructor**: Cleans up the dynamically allocated nodes to prevent memory leaks.

- **Main Function**:  
  Demonstrates the usage of the circular linked list by inserting nodes, searching for a value, deleting a node, and displaying the list before and after deletion.

## Code Snippet (Main Code)

Below is the main code snippet that includes the core functionality:

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

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void remove(int value) {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = tail;
        do {
            if (temp->next->data == value) {
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                if (nodeToDelete == tail) {
                    if (tail == tail->next) {
                        tail = nullptr;
                    } else {
                        tail = temp;
                    }
                }
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        } while (temp != tail);
        cout << "Value not found in the list.\n";
    }

    bool search(int value) {
        if (tail == nullptr) return false;
        Node* temp = tail->next;
        do {
            if (temp->data == value)
                return true;
            temp = temp->next;
        } while (temp != tail->next);
        return false;
    }

    void display() {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(head)\n";
    }

    ~CircularLinkedList() {
        if (tail == nullptr) return;
        Node* temp = tail->next;
        while (temp != tail) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete tail;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Circular Linked List: ";
    list.display();

    cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << "\n";
    cout << "Deleting 20...\n";
    list.remove(20);

    cout << "Circular Linked List after deletion: ";
    list.display();

    return 0;
}
```

## How to Compile and Run

1. **Clone the Repository (if applicable)**:  
   If your code is part of a repository, you can clone it using:
   ```bash
   git clone https://github.com/PJT-2011/Design-and-Analysis-of-Algorithms.git
   cd DAA/CircularLinkedList
   ```

2. **Compile the Code**:  
   Use a C++ compiler such as `g++` to compile the code:
   ```bash
   g++ -o circulerlinkedlist CircularLinkedList.cpp
   ```

3. **Run the Executable**:  
   Execute the compiled program:
   ```bash
   ./circularlinkedlist
   ```

## Expected Output

After running the program, you should see output similar to:

```
Circular Linked List: 10 -> 20 -> 30 -> 40 -> (head)
Searching for 20: Found
Deleting 20...
Circular Linked List after deletion: 10 -> 30 -> 40 -> (head)
```

This output confirms that the circular linked list is:
- **Displaying** all the nodes in a circular manner.
- **Searching** for a value correctly.
- **Deleting** the specified node and updating the list accordingly.

## Conclusion

This project offers a simple yet effective demonstration of implementing a circular linked list in C++. The operations include insertion, deletion, search, and display, making it a useful reference for understanding the management of circular linked lists and dynamic memory in C++.

---

