#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    shared_ptr<Node> next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{
private:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insert_at_end(int data)
    {
        auto newNode = make_shared<Node>(data);
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

    void display() const
    {
        if (!head)
        {
            cout << "No Node\n";
            return;
        }

        shared_ptr<Node> curr = head;
        while (curr)
        {
            cout << curr->data;
            if (curr->next)
                cout << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
int sum_odd()
{
    if (!head)
    {
        cout << "No Node\n";
        return -1;
    }

    int sum = 0;
    shared_ptr<Node> t = head;
    int i = 1;

    while (t)
    {
        if (i % 2 != 0)
            sum += t->data;

        t = t->next;
        i++;
    }

    return sum;
}

int sum_even()
{
    if (!head)
    {
        cout << "No Node\n";
        return -1;
    }

    int sum = 0;
    shared_ptr<Node> t = head;
    int i = 1;

    while (t)
    {
        if (i % 2 == 0)
            sum += t->data;

        t = t->next;
        i++;
    }

    return sum;
}
};

int main()
{
    LinkedList list;
    int choice;

    while (cin >> choice && choice != 0)
    {
        int data,out;

        switch (choice)
        {
            case 1:
                cin >> data;
                list.insert_at_end(data);
                break;

            case 2:
                list.display();
                break;

            case 3:
                out=list.sum_odd();
                if(out!=-1)
                    cout << out << endl;
                break;

            case 4:
                out=list.sum_even();            
                if(out!=-1)
                    cout << out << endl;
                break;

            default:
                break;
        }
    }

    return 0;
}