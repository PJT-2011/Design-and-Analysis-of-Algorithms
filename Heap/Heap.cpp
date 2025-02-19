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
