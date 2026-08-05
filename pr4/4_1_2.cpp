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

    void insert_at_front(int data)
    {
        auto newNode = make_shared<Node>(data);
        newNode->next = head;
        head = newNode;
        if (!tail)
            tail = newNode;
    }

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

    void insert_after(int givenData, int data)
    {
        shared_ptr<Node> curr = head;
        while (curr && curr->data != givenData)
            curr = curr->next;

        if (!curr)
        {
            // given node not found: fall back to inserting at the end
            insert_at_end(data);
            return;
        }

        auto newNode = make_shared<Node>(data);
        newNode->next = curr->next;
        curr->next = newNode;

        if (curr == tail)
            tail = newNode;
    }

    void delete_at_front()
    {
        if (!head) return;

        head = head->next;
        if (!head)
            tail = nullptr;
    }

    void delete_at_end()
    {
        if (!tail) return;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            shared_ptr<Node> curr = head;
            while (curr->next != tail)
                curr = curr->next;

            curr->next = nullptr;
            tail = curr;
        }
    }

    void display() const
    {
        if (!head)
        {
            cout << "List is Empty\n";
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
};

int main()
{
    LinkedList list;
    int choice;

    while (cin >> choice && choice != 0)
    {
        int data, givenData;

        switch (choice)
        {
            case 1:
                cin >> data;
                list.insert_at_front(data);
                break;

            case 2:
                cin >> data;
                list.insert_at_end(data);
                break;

            case 3:
                cin >> givenData >> data;
                list.insert_after(givenData, data);
                break;

            case 4:
                list.delete_at_front();
                break;

            case 5:
                list.delete_at_end();
                break;

            case 6:
                list.display();
                break;

            default:
                break;
        }
    }

    return 0;
}