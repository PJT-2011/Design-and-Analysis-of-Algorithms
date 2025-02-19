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
        Node* prev = nullptr;
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