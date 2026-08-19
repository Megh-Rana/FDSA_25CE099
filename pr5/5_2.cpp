#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert_at_start(int data)
    {
        Node *new1 = new Node(data);

        if (head == nullptr)
        {
            head = new1;
            new1->next = head;
        }
        else
        {
            Node *t = head;

            while (t->next != head)
            {
                t = t->next;
            }

            new1->next = head;
            t->next = new1;
            head = new1;
        }
    }

    void insert_at_end(int data)
    {
        Node *new1 = new Node(data);

        if (head == nullptr)
        {
            head = new1;
            new1->next = head;
        }
        else
        {
            Node *t = head;

            while (t->next != head)
            {
                t = t->next;
            }

            t->next = new1;
            new1->next = head;
        }
    }

    void delete_at_start()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *t = head;

        while (t->next != head)
        {
            t = t->next;
        }

        Node *temp = head;
        head = head->next;
        t->next = head;

        delete temp;
    }

    void delete_at_end()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *t = head;

        while (t->next->next != head)
        {
            t = t->next;
        }

        delete t->next;
        t->next = head;
    }

    void delete_at_middle(int target)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == target)
        {
            delete_at_start();
            return;
        }

        Node *t = head;

        while (t->next != head && t->next->data != target)
        {
            t = t->next;
        }

        if (t->next == head)
        {
            cout << "Element not found" << endl;
            return;
        }

        Node *temp = t->next;
        t->next = temp->next;

        delete temp;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *t = head;

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
    LinkedList ll;

    ll.insert_at_start(10);
    ll.insert_at_start(20);
    ll.insert_at_end(30);

    ll.display();

    ll.delete_at_start();
    ll.display();

    ll.delete_at_end();
    ll.display();

    ll.delete_at_middle(20);
    ll.display();

    return 0;
}