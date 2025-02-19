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

    // Display elements from the temporary stack
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        myStack.push(tempStack.top()); // Push back to the original stack
        tempStack.pop();
    }
    cout << endl;

    return 0;
}