#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
        ListNode* nextTemp = head->next;
        head->next = prev;
        prev = head;
        head = nextTemp;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Find the middle of the list
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    slow = reverseList(slow);

    // Compare the first and second halves
    ListNode* left = head, *right = slow;
    bool isPalindrome = true;
    while (right) {
        if (left->val != right->val) {
            isPalindrome = false;
            break;
        }
        left = left->next;
        right = right->next;
    }

    // Restore the list structure (optional, for maintaining original list)
    slow = reverseList(slow);
    if (fast) { // If fast != nullptr, then the length of the list is odd
        ListNode* temp = head;
        while (temp->next != slow) {
            temp = temp->next;
        }
        temp->next = slow;
    }

    return isPalindrome;
}

int main() {
    int N;
    std::cin >> N;

    if (N == 0) {
        std::cout << "True" << std::endl;
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;

        if (!head) {
            head = new ListNode(value);
            current = head;
        } else {
            current->next = new ListNode(value);
            current = current->next;
        }
    }

    bool result = isPalindrome(head);
    std::cout << (result ? "True" : "False") << std::endl;

    // Clean up memory
    current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}