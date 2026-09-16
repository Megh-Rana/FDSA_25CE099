#include <iostream>
using namespace std;

class TokenCounter {
    int max_n;
    char* q;
    int front, rear, count;
    
public:
    TokenCounter(int n) : max_n(n), front(0), rear(-1), count(0) {
        q = new char[max_n];
    }
    
    void join(string s) {
        if (count == max_n) {
            cout << "Error: Counter full" << endl;
            return;
        }
        strcpy(q[++rear], s.c_str());
        cout << "Front: " << q[front] << endl;
    }
    
    void serve() {
        if (count == 0) {
            cout << "Error: Counter empty" << endl;
            return;
        }
        cout << "Served: " << q[front++] << endl;
        cout << "Front: " << q[front] << " (if exists)" << endl;
        count--;
    }
};

int main() {
    int n = 5;
    TokenCounter tc(n);
    
    tc.join("A");
    tc.join("B");
    tc.join("C");
    tc.join("D");
    tc.join("E");
    
    tc.join("F");  // Error
    
    tc.serve();
    
    return 0;
}
