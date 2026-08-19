#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 ? l1 : l2);

    return dummy->next;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int size1, size2;
    std::cin >> size1 >> size2;

    std::vector<int> array1(size1);
    for (int i = 0; i < size1; ++i) {
        std::cin >> array1[i];
    }

    std::vector<int> array2(size2);
    for (int i = 0; i < size2; ++i) {
        std::cin >> array2[i];
    }

    ListNode* list1 = createLinkedList(array1);
    ListNode* list2 = createLinkedList(array2);

    int choice;
    while (std::cin >> choice) {
        if (choice == 0) break;

        switch (choice) {
            case 1:
                std::cout << "List 1: ";
                printLinkedList(list1);
                break;
            case 2:
                std::cout << "List 2: ";
                printLinkedList(list2);
                break;
            case 3:
                ListNode* mergedList = mergeTwoLists(list1, list2);
                std::cout << "Merged List: ";
                printLinkedList(mergedList);

                // Clean up the merged list memory
                while (mergedList != nullptr) {
                    ListNode* temp = mergedList;
                    mergedList = mergedList->next;
                    delete temp;
                }
                break;
            default:
                std::cout << "Invalid choice. Please choose 1, 2, 3, or 0." << std::endl;
        }
    }

    // Clean up the original lists memory
    while (list1 != nullptr) {
        ListNode* temp = list1;
        list1 = list1->next;
        delete temp;
    }
    
    while (list2 != nullptr) {
        ListNode* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}
