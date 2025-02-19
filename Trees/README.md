
---

# Binary Tree Operations in C++

This project demonstrates basic binary tree operations implemented in C++. The program allows users to insert nodes into a binary search tree, display the tree using an in-order traversal (which prints the nodes in ascending order), and exit while properly deallocating the tree's memory.

## Overview

The program is designed with the following functionalities:
- **Insertion**: Recursively insert nodes into the binary search tree while maintaining the BST property.
- **In-Order Traversal**: Recursively traverse the tree in in-order to display all the node values in sorted order.
- **Deletion of the Tree**: Recursively delete all nodes in the tree to free up memory when exiting the program.
- **Interactive Menu**: A simple menu-driven interface to perform the operations.

## Code Explanation

- **TreeNode Structure**:  
  Represents a node in the binary tree with an integer `data` and pointers to the left and right child nodes.
  
- **insert Function**:  
  Inserts a new value into the binary search tree. If the tree is empty, it creates a new node; otherwise, it recurses left or right based on the value.

- **inOrderTraversal Function**:  
  Traverses the tree in in-order (left subtree, current node, right subtree) and prints the node values.

- **deleteTree Function**:  
  Recursively deletes every node in the tree to avoid memory leaks when the program terminates.

- **Main Function**:  
  Provides a menu-driven interface that allows the user to insert values into the tree, display the tree, or exit the program (which triggers the deletion of the entire tree).

## Main Code Snippet

```cpp
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void inOrderTraversal(TreeNode* root) {
    if (!root) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;
    int choice, value;
    
    do {
        cout << "\nBinary Tree Operations:\n";
        cout << "1. Insert\n2. Display (In-Order)\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Tree (In-Order Traversal): ";
                inOrderTraversal(root);
                cout << endl;
                break;
            case 3:
                deleteTree(root);
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);
    
    return 0;
}
```

## How to Compile and Run

1. **Clone the Repository (if applicable)**  
   If this code is part of a repository, you can clone it using:
   ```bash
   git clone https://github.com/PJT-2011/Design-and-Analysis-of-Algorithms.git
   cd DAA/Trees
   ```

2. **Compile the Code**  
   Use a C++ compiler such as `g++`:
   ```bash
   g++ -o trees trees.cpp
   ```

3. **Run the Executable**  
   Execute the compiled program:
   ```bash
   ./trees
   ```

## Expected Output

When you run the program, you should see a menu like:

```
Binary Tree Operations:
1. Insert
2. Display (In-Order)
3. Exit
Enter your choice:
```

After inserting values, choosing option 2 will display the tree's in-order traversal, for example:

```
Tree (In-Order Traversal): 10 20 30 40 
```

This demonstrates that the tree is displaying its elements in sorted order.

## Conclusion

This project provides a simple yet effective demonstration of how to implement a binary search tree in C++ with basic operations such as insertion, in-order traversal, and memory deallocation. It serves as a solid foundation for understanding more advanced tree structures and algorithms in C++.

---