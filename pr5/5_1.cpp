#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node* prev;
    Node* next;

    Node(string data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DLL
{
    Node* head;

public:
    DLL()
    {
        head = nullptr;
    }

    int get_count()
    {
        int cnt = 0;
        Node* t = head;

        while (t)
        {
            t = t->next;
            cnt++;
        }

        return cnt;
    }

    void add_node_start(string data)
    {
        Node* new1 = new Node(data);

        if (head == nullptr)
        {
            head = new1;
        }
        else
        {
            new1->next = head;
            head->prev = new1;
            head = new1;
        }
    }

    void add_node_end(string data)
    {
        Node* new1 = new Node(data);

        if (head == nullptr)
        {
            head = new1;
        }
        else
        {
            Node* t = head;
            while(t->next!=nullptr)
            {
                t=t->next;
            }
            t->next=new1;
            new1->prev=t;
        }        
    }

void insert_at_middle(string data, string target)
{
    Node* new1 = new Node(data);

    if (head == nullptr)
    {
        head = new1;
        return;
    }

    Node* t = head;

    while (t != nullptr && t->data != target)
    {
        t = t->next;
    }

    if (t == nullptr)
    {
        delete new1;
        return;
    }

    new1->next = t->next;
    new1->prev = t;

    if (t->next != nullptr)
    {
        t->next->prev = new1;
    }

    t->next = new1;
}

    void display()
    {
        Node* t = head;

        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }

        cout << endl;
    }
};

int main()
{
    DLL list;

    list.add_node_start("C");
    list.add_node_start("B");
    list.add_node_start("A");

    list.display();

    cout << "Count: " << list.get_count() << endl;
}