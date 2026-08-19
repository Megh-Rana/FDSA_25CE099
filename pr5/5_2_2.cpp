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
        if (head == nullptr)
            return 0;

        int cnt = 0;
        Node* t = head;

        do
        {
            cnt++;
            t = t->next;
        } while (t != head);

        return cnt;
    }
    void add_node_start(string data)
    {
        Node* new1 = new Node(data);

        if (head == nullptr)
        {
            head = new1;
            new1->next = head;
            new1->prev = head;
        }
        else
        {
            Node* tail = head->prev;

            new1->next = head;
            new1->prev = tail;

            head->prev = new1;
            tail->next = new1;

            head = new1;
        }
    }

    void add_node_end(string data)
    {
        Node* new1 = new Node(data);

        if (head == nullptr)
        {
            head = new1;
            new1->next = head;
            new1->prev = head;
        }
        else
        {
            Node* tail = head->prev;

            new1->next = head;
            new1->prev = tail;

            tail->next = new1;
            head->prev = new1;
        }
    }

    void insert_at_middle(string data, string target)
    {
        if (head == nullptr)
            return;

        Node* t = head;

        do
        {
            if (t->data == target)
                break;

            t = t->next;
        } while (t != head);

        if (t->data != target)
        {
            cout << "Element not found" << endl;
            return;
        }

        Node* new1 = new Node(data);

        new1->next = t->next;
        new1->prev = t;

        t->next->prev = new1;
        t->next = new1;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* t = head;

        do
        {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);

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