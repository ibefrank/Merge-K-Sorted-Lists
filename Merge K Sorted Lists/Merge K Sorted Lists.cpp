// Merge K Sorted Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Custom comparator for min-heap (priority_queue)
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap
    }
};

// Function to merge k sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    for (auto node : lists) {
        if (node) minHeap.push(node);
    }

    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while (!minHeap.empty()) {
        ListNode* minNode = minHeap.top();
        minHeap.pop();

        tail->next = minNode;
        tail = tail->next;

        if (minNode->next) {
            minHeap.push(minNode->next);
        }
    }

    return dummy->next;
}

// Utility function to convert vector to linked list
ListNode* buildLinkedList(const vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Utility function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: [[1,4,5],[1,3,4],[2,6]]
    vector<vector<int>> input = { {1,4,5}, {1,3,4}, {2,6} };
    vector<ListNode*> lists;

    // Convert input vectors to linked lists
    for (const auto& vec : input) {
        lists.push_back(buildLinkedList(vec));
    }

    // Merge all linked lists
    ListNode* result = mergeKLists(lists);

    // Print the result
    cout << "Merged Linked List: ";
    printLinkedList(result);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
