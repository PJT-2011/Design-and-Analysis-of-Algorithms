
---

# Queue Operations in C++ Using STL

This project demonstrates basic operations on a queue using the C++ Standard Template Library (STL). The code shows how to enqueue elements, access the front element, and dequeue elements until the queue is empty.

## Overview

The program performs the following operations on a queue:
- **Enqueueing**: Adding elements to the queue using `push()`.
- **Accessing the Front Element**: Retrieving the front element with `front()`.
- **Dequeuing**: Removing elements from the queue using `pop()`.
- **Checking if the Queue is Empty**: Using `empty()` to determine if the queue has any remaining elements.

## Main Code Snippet

Below is the main code that demonstrates the queue operations:

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q; 

    cout << "Enqueueing elements: 10, 20, 30, 40, 50" << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Front element: " << q.front() << endl;

    cout << "Dequeuing elements: " << endl;
    while (!q.empty()) {
        cout << q.front() << " "; 
        q.pop(); 
    }
    cout << endl;

    if (q.empty()) {
        cout << "Queue is now empty." << endl;
    }

    return 0;
}
```

## How to Compile and Run

1. **Clone the Repository (if applicable)**:  
   If this code is part of a repository, clone it using:
   ```bash
   git clone https://github.com/PJT-2011/Design-and-Analysis-of-Algorithms.git
   cd DAA/Queues
   ```

2. **Compile the Code**:  
   Use a C++ compiler (e.g., `g++`) to compile the code:
   ```bash
   g++ -o queues queues.cpp
   ```

3. **Run the Executable**:  
   Execute the compiled program:
   ```bash
   ./queues
   ```

## Expected Output

When you run the program, you should see the following output:

```
Enqueueing elements: 10, 20, 30, 40, 50
Front element: 10
Dequeuing elements: 
10 20 30 40 50 
Queue is now empty.
```

## Asciinema Recording
```bash
https://asciinema.org/a/704460
```

## Conclusion

This project provides a simple demonstration of how to use the C++ STL `queue` container to perform basic queue operations. The code serves as a good starting point for understanding the FIFO (First-In, First-Out) data structure in C++.

---