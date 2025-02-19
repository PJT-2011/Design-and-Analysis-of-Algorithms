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