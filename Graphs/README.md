# Graph Representation Using Adjacency Lists in C++

This project demonstrates a simple implementation of an undirected graph using the adjacency list data structure in C++. It includes functions for creating the graph, adding edges, and printing the adjacency list for each vertex.

## Overview

The program defines three main structures:

- **AdjListNode**: Represents a node in the adjacency list with an integer `data` and a pointer `next` to the next node.
- **AdjList**: Contains a pointer `head` to the first node of the list.
- **Graph**: Consists of the number of vertices (`V`) and an array of `AdjList`, one for each vertex.

The key functionalities provided are:
- **Graph Creation**: Dynamically allocate a graph with a specified number of vertices.
- **Edge Addition**: Add an undirected edge between two vertices by updating the adjacency lists.
- **Graph Printing**: Print the adjacency list representation for each vertex.

## Code Explanation

- **newAdjListNode(int data)**:  
  Creates a new node with the provided `data` and initializes its `next` pointer to `NULL`.

- **createGraph(int V)**:  
  Allocates memory for a graph with `V` vertices and initializes each adjacency list's head to `NULL`.

- **addEdge(Graph *graph, int src, int dest)**:  
  Adds an edge between vertices `src` and `dest`. Since the graph is undirected, the function updates both the source's and destination's adjacency lists.

- **printGraph(Graph *graph)**:  
  Iterates through each vertex's adjacency list and prints its elements to show the graph's structure.

## Main Code Snippet

Below is the main portion of the code that creates a graph, adds edges, and prints the graph:

```cpp
#include<iostream>
#include<cstdlib>
using namespace std;

struct AdjListNode {
    int data;
    AdjListNode *next;
};

struct AdjList {
    AdjListNode *head;  
};

struct Graph {
    int V;
    AdjList *arr;
};

AdjListNode *newAdjListNode(int);
Graph *createGraph(int);
void addEdge(Graph*, int, int);
void printGraph(Graph*);

int main() {
    int totalVertices = 4;
    Graph *graph = createGraph(totalVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printGraph(graph);
    return 0;
}
```

## How to Compile and Run

1. **Clone this repository**
   ```
   git clone https://github.com/PJT-2011/Design-and-Analysis-of-Algorithms.git
   cd DAA/pt1/Graph
  ```
2. **Compile the code** using a C++ compiler such as `g++`:
   ```
   g++ -o graph main.cpp
   ```
3. **Run the executable**:
   ```
   ./graphs
   ```

## Expected Output

The program will output the adjacency list for each vertex. For example:

```
Adjacency list of vertex 0
3 -> 2 -> 1 -> 
Adjacency list of vertex 1
3 -> 0 -> 
Adjacency list of vertex 2
3 -> 0 -> 
Adjacency list of vertex 3
2 -> 1 -> 0 ->
```

This output shows that vertex 0 is connected to vertices 1, 2, and 3, and so on.

## Conclusion

This simple C++ program illustrates the basics of graph representation using adjacency lists. It serves as a foundation for more complex graph algorithms and helps in understanding dynamic data structures and memory management in C++.

--- 