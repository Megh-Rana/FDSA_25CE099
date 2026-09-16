#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode* next;
};

StackNode* create_stack() {
    return nullptr; // Return an empty stack (nullptr)
}

StackNode* pop(StackNode*& top) {
    if (top == nullptr) {
        cout << "Stack underflow!" << endl;
        return nullptr; // Indicate that the stack is empty
    }
    StackNode* poppedNode = top;
    top = top->next;
    return poppedNode;
}

StackNode* peek(StackNode* top) {
    if (top == nullptr) {
        cout << "Stack is empty!" << endl;
        return nullptr; // Indicate that the stack is empty
    }
    return top;
}

void push(StackNode*& top, int value) {
    StackNode* newNode = new StackNode();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int main()
{
    StackNode* top = create_stack();

    // Example usage
    push(top, 10);
    push(top, 20);
    push(top, 30);

    StackNode* peekedNode = peek(top);
    if (peekedNode != nullptr) {
        cout << "Top element is: " << peekedNode->data << endl;
    }

    StackNode* poppedNode = pop(top);
    if (poppedNode != nullptr) {
        cout << "Popped element is: " << poppedNode->data << endl;
        delete poppedNode; // Free the memory of the popped node
    }

    return 0;
}