#include <bits/stdc++.h>
using namespace std;

int* create_stack(int size) {
    int* stack = new int[size];
    return stack;
}

int pop(int* stack, int& top) {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
        return -1; // Indicate that the stack is empty
    }
    return stack[top--];
}

int peek(int* stack, int top) {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return -1; // Indicate that the stack is empty
    }
    return stack[top];
}

void push(int* stack, int& top, int size, int value) {
    if (top == size - 1) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stack[++top] = value;
}

int main()
{
    cout << "Enter the size of the stack: ";
    int size;
    cin >> size;
    int* stack = create_stack(size);
    int top = -1;

}