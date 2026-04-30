#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* temp = new Node();

        temp -> data = x;
        temp -> next = NULL;

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear -> next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == NULL) return;

        Node* temp = front;
        front = front->next;

        if (front == NULL) rear = NULL;

        delete temp;
    }

    int size() {
        int count1 = 0;
        Node *temp = front;
        while (temp != NULL) {
            count1++;
            temp = temp -> next;
        }

        return count1;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
        Node* temp;
        temp = front;

        while (temp != NULL) {
            cout << temp-> data << " ";
            temp = temp -> next;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.size() << endl;
    q.dequeue();
    cout << q.size() << endl;
    q.display();

    return 0;
}