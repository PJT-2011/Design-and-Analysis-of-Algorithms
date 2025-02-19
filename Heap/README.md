
---

# Priority Queue (Heap) Example in C++

This project demonstrates how to use C++'s Standard Template Library (STL) `priority_queue` to implement both max-heaps and min-heaps. The code shows how to insert elements into these heaps and display them according to their ordering properties.

## Overview

The code performs the following tasks:
- **Max Heap**: Uses the default behavior of `priority_queue<int>`, where the largest element is always at the top.
- **Min Heap**: Uses a custom comparator (`greater<int>`) with `priority_queue` to keep the smallest element at the top.
- **Display Functions**: Two functions, `displayMaxHeap` and `displayMinHeap`, are used to print and empty the heaps by continuously popping the top element.

## Code Explanation

- **displayMaxHeap(priority_queue<int> maxHeap)**:  
  This function takes a copy of the max-heap and prints each element. Since the max-heap always keeps the largest element at the top, the printed order will be descending.

- **displayMinHeap(priority_queue<int, vector<int>, greater<int>> minHeap)**:  
  This function prints the elements of a min-heap in ascending order because of the custom comparator.

- **main()**:  
  The `main` function demonstrates how to:
  1. Create a max-heap and a min-heap.
  2. Insert the same set of integers into both heaps.
  3. Display the heaps using the respective display functions.

## Main Code Snippet

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void displayMaxHeap(priority_queue<int> maxHeap) {
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
}

void displayMinHeap(priority_queue<int, vector<int>, greater<int>> minHeap) {
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(40);
    maxHeap.push(30);
    maxHeap.push(50);
    maxHeap.push(20);
    
    cout << "Max Heap Elements: ";
    displayMaxHeap(maxHeap);

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(40);
    minHeap.push(30);
    minHeap.push(50);
    minHeap.push(20);
    
    cout << "Min Heap Elements: ";
    displayMinHeap(minHeap);

    return 0;
}
```

## How to Compile and Run

1. **Clone the Repository**  
   Open your terminal and clone the repository:
   ```bash
   git clone https://github.com/PJT-2011/Design-and-Analysis-of-Algorithms.git
   ```
2. **Navigate to the Project Directory**  
   Change into the appropriate directory:
   ```bash
   cd DAA/Heap
   ```
3. **Compile the Code**  
   Use a C++ compiler (e.g., `g++`) to compile the code:
   ```bash
   g++ -o heap Heap.cpp
   ```
4. **Run the Executable**  
   Execute the compiled program:
   ```bash
   ./heap
   ```

## Expected Output

When you run the program, you should see output similar to:

```
Max Heap Elements: 50 40 30 20 10 
Min Heap Elements: 10 20 30 40 50 
```

This output demonstrates:
- The **max-heap** displays elements in descending order.
- The **min-heap** displays elements in ascending order.

## Asciinema Recording
```bash
https://asciinema.org/a/704466
```

## Conclusion

This example illustrates the use of the STL `priority_queue` to implement both max-heaps and min-heaps in C++. It serves as a basic demonstration of heap operations and can be extended for more complex applications that require efficient retrieval of the maximum or minimum element.

--- 

