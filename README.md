# Merge K Sorted Linked Lists 🔗

This repository contains a **C++ implementation** that efficiently merges `k` sorted linked lists into a single sorted linked list. The solution uses a **min-heap (priority queue)** to always extract the smallest available node, resulting in optimal performance.

---

## 📌 Problem Statement

Given an array of `k` linked lists, where each linked list is sorted in ascending order, merge all the linked lists into one sorted linked list and return its head.

### ✅ Example
Input: [[1,4,5], [1,3,4], [2,6]]
Output: [1,1,2,3,4,4,5,6

---

## 💡 Approach

- Use a **min-heap (priority queue)** to track the smallest head among the k lists.
- Always extract the smallest node and push its next node into the heap.
- Continue until the heap is empty.
- Time Complexity: **O(N log k)** where N is the total number of nodes.
- Space Complexity: **O(k)** for the heap.

---

## 🧰 Technologies Used

- **Language:** C++
- **Data Structures:** Linked List, Priority Queue (Min-Heap)
- **IDE:** Visual Studio 2022 (or any C++ compiler)

---

## ▶️ How to Run (Visual Studio 2022)

1. Open **Visual Studio 2022**
2. Go to **File > New > Project**
3. Choose **Console App (C++)**
4. Name your project (e.g., `MergeKLists`) and click **Create**
5. Replace the contents of `main.cpp` with the code from this repo
6. Press `Ctrl + F5` to build and run

---

## 📁 File Structure

main.cpp # Full implementation with sample input/output

ListNode definition # Singly linked list node structure

Helper functions # To build and print lists from vectors
