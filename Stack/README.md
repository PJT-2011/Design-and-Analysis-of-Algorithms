Below is the content you can include in your **README.md** file:

---

# Stack Operations in C++ Using STL

This project demonstrates basic operations on a stack using the C++ Standard Template Library (STL). The code shows how to push elements onto a stack, display its elements without permanently modifying the original stack, and restore the stack to its original state.

## Overview

The program performs the following operations:
- **Pushing Elements**: Uses `push()` to add elements to the stack.
- **Displaying Elements**: Since accessing elements in a stack is LIFO (Last-In, First-Out) and the only direct access is through `top()`, the code uses a temporary stack to print all elements without losing the original stack order.
- **Restoring the Original Stack**: After transferring elements to a temporary stack and printing them, the elements are pushed back into the original stack.

## Code Explanation

- **Pushing Elements onto the Stack**:  
  The code pushes three integers (10, 20, 30) onto the stack. The last element pushed (30) becomes the top of the stack.

- **Displaying Elements Without Losing Data**:  
  To display the elements without destroying the original stack, the code uses a temporary stack. It pops each element from the original stack, pushes it into the temporary stack, and then uses this temporary stack to print the elements while restoring the original stack.

- **Restoration of the Original Stack**:  
  While printing the elements from the temporary stack, each element is pushed back to the original stack, ensuring that the stack remains unchanged after the display operation.

## Main Code Snippet

```cpp
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Stack elements after pushing: " << endl;
    
    // Display stack elements without modifying the original stack
    stack<int> tempStack;
    while (!myStack.empty()) {
        tempStack.push(myStack.top());
        myStack.pop();
    }

    // Display elements from the temporary stack and restore the original stack
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        myStack.push(tempStack.top()); // Restore original stack
        tempStack.pop();
    }
    cout << endl;

    return 0;
}
```

## How to Compile and Run

1. **Clone the Repository (if applicable)**:  
   If this code is part of a repository, clone it using:
   ```bash
   git clone https://github.com/PJT-2011/Design-and-Analysis-of-Algorithms.git
   cd DAA/Stack
   ```

2. **Compile the Code**:  
   Use a C++ compiler (e.g., `g++`) to compile the code:
   ```bash
   g++ -o stack stack.cpp
   ```

3. **Run the Executable**:  
   Execute the compiled program:
   ```bash
   ./stack
   ```

## Expected Output

When you run the program, the expected output is:

```
Stack elements after pushing: 
10 20 30 
```

This output indicates that:
- The elements were pushed onto the stack.
- They were displayed correctly while the original stack was restored.

## Asciinema Recording
```bash
https://asciinema.org/a/704462
```

## Conclusion

This project provides a clear example of using the STL `stack` container in C++ for basic operations. The method used to display stack elements ensures that the stack's content is preserved, demonstrating an important technique for working with stacks where only the top element is directly accessible.

---