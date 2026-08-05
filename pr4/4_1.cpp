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
    int count;

public:
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}

    static shared_ptr<Node> create_node(int data)
    {
        return make_shared<Node>(data);
    }

    void insert_at_front(int data)
    {
        auto newNode = create_node(data);
        newNode->next = head;
        head = newNode;
        if (!tail)
            tail = newNode;
        count++;
    }

    void insert_at_end(int data)
    {
        auto newNode = create_node(data);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void insert_at_position(int data, int pos)
    {
        if (pos <= 0 || !head)
        {
            insert_at_front(data);
            return;
        }
        if (pos >= count)
        {
            insert_at_end(data);
            return;
        }

        shared_ptr<Node> curr = head;
        for (int i = 0; i < pos - 1; i++)
            curr = curr->next;

        auto newNode = create_node(data);
        newNode->next = curr->next;
        curr->next = newNode;
        count++;
    }

    void delete_at_front()
    {
        if (!head) return;

        head = head->next;
        if (!head)
            tail = nullptr;

        count--;
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
        count--;
    }

    void remove_at_position(int pos)
    {
        if (pos < 0 || pos >= count) return;

        if (pos == 0) { delete_at_front(); return; }
        if (pos == count - 1) { delete_at_end(); return; }

        shared_ptr<Node> curr = head;
        for (int i = 0; i < pos - 1; i++)
            curr = curr->next;

        curr->next = curr->next->next;
        count--;
    }

    int number_of_nodes() const
    {
        return count;
    }

    void print() const
    {
        shared_ptr<Node> curr = head;
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
    LinkedList list;

    list.insert_at_end(10);
    list.insert_at_end(20);
    list.insert_at_end(30);
    list.print();

    list.insert_at_front(5);
    list.print();

    list.insert_at_position(15, 2);
    list.print();

    cout << "Count: " << list.number_of_nodes() << "\n";

    list.delete_at_front();
    list.print();

    list.delete_at_end();
    list.print();

    list.remove_at_position(1);
    list.print();

    cout << "Count: " << list.number_of_nodes() << "\n";

    return 0;
}