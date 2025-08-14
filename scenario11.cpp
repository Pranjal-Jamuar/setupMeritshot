// Question: 11
// Reverse a Linked List
// Language: C++

#include <iostream>
#include <string>
using namespace std;

// Node class represents a single element in the list
class Node {
public:
    string data;
    Node* next;

    Node(const string& val) : data(val), next(nullptr) {}
};

// LinkedList class to manage the list operations
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Helper function to add nodes for testing
    void add(const string& val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Displays the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Reverses the linked list in-place
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            // Store the next node before we change the pointer
            next = current->next;

            // Reverse the current node's pointer
            current->next = prev;

            // Move pointers one position ahead for the next iteration
            prev = current;
            current = next;
        }

        // After the loop, 'prev' will be the new head of the reversed list
        head = prev;
    }
};

int main() {
    LinkedList list;
    list.add("Song A");
    list.add("Song B");
    list.add("Song C");
    list.add("Song D");

    cout << "Original Playlist:" << endl;
    list.display();

    cout << "\nReversing the playlist..." << endl;
    list.reverse();

    cout << "\nReversed Playlist:" << endl;
    list.display();

    return 0;
}

// --- Explanation of Approach ---
// I implemented an in-place iterative reversal using three pointers: 'prev', 'current', and 'next'.
// The 'current' pointer traverses the list, and for each node, I reverse its 'next' pointer to
// point to the 'prev' node. I use the 'next' pointer to store the link to the rest of the
// list before reversing the link. This modifies the list directly, using O(1) extra space.