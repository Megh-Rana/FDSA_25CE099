#include <bits/stdc++.h>
using namespace std;

string infix_to_postfix(string infix) {
    stack<char> s;
    string postfix = "";
    unordered_map<char, int> precedence = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'^', 3}
    };

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // pop '('
        } else { // operator
            while (!s.empty() && precedence[s.top()] >= precedence[c]) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int postfix_evaluation(string postfix) {
    stack<int> s;

    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else { // operator
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }

    return s.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infix_to_postfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = postfix_evaluation(postfix);
    cout << "Result: " << result << endl;

    return 0;
}