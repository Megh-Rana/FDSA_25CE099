#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList()
    {
        Node* curr = head;
        while (curr)
        {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void insert_at_end(int data)
    {
        Node* newNode = new Node(data);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void reverse()
    {
        Node* prev = nullptr;
        Node* curr = head;
        tail = head;

        while (curr)
        {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        head = prev;
    }

    void display() const
    {
        Node* curr = head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

int main()
{
    int n;
    cin >> n;

    LinkedList list;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        list.insert_at_end(data);
    }

    list.reverse();
    list.display();

    return 0;
}