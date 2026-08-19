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

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void sort()
    {
        int comparisons = 0;
        int swaps = 0;

        if (!head)
        {
            cout << 0 << endl;
            cout << 0 << endl;
            return;
        }

        shared_ptr<Node> end = nullptr;

        while (end != head)
        {
            shared_ptr<Node> curr = head;
            bool swapped = false;

            while (curr->next != end)
            {
                comparisons++;

                if (curr->data > curr->next->data)
                {
                    swap(curr->data, curr->next->data);
                    swaps++;
                    swapped = true;
                }

                curr = curr->next;
            }

            end = curr;

            if (!swapped)
                break;
        }

        cout << comparisons << endl;
        cout << swaps << endl;
    }

    void display()
    {
        shared_ptr<Node> curr = head;

        while (curr)
        {
            cout << curr->data;

            if (curr->next)
                cout << " ";

            curr = curr->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList list;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        list.insert_at_end(data);
    }

    list.sort();
    list.display();

    return 0;
}