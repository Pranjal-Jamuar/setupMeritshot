// Question: 10
// Train Coach Management
// Language: C++

#include <iostream>
#include <string>
using namespace std;

// Node class represents a single coach in the train
class Node {
public:
    int coachID;
    Node* next;
    Node* prev;

    Node(int id) {
        coachID = id;
        next = nullptr;
        prev = nullptr;
    }
};

// Train class manages the doubly linked list of coaches
class Train {
private:
    Node* head;
    Node* tail;

public:
    Train() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor to free all allocated memory
    ~Train() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Adds a new coach to the front of the train
    void addFront(int id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Added coach " << id << " to the front." << endl;
    }

    // Adds a new coach to the end of the train
    void addEnd(int id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Added coach " << id << " to the end." << endl;
    }

    // Removes a coach by its ID
    void removeCoach(int id) {
        if (head == nullptr) {
            cout << "Train is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr && current->coachID != id) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Coach " << id << " not found." << endl;
            return;
        }

        if (current == head) { // Removing the head
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            else tail = nullptr; // List became empty
        } else if (current == tail) { // Removing the tail
            tail = tail->prev;
            tail->next = nullptr;
        } else { // Removing from the middle
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Removed coach " << id << "." << endl;
    }

    // Displays all coaches in the train from front to back
    void displayTrain() {
        cout << "\n--- Train Lineup ---" << endl;
        if (head == nullptr) {
            cout << "Train is empty." << endl;
        } else {
            Node* current = head;
            cout << "Engine <-> ";
            while (current != nullptr) {
                cout << "Coach(" << current->coachID << ") <-> ";
                current = current->next;
            }
            cout << "Caboose" << endl;
        }
        cout << "--------------------" << endl;
    }
};

void showMenu() {
    cout << "\nTrain Management Menu:\n";
    cout << "1. Add coach to front\n";
    cout << "2. Add coach to end\n";
    cout << "3. Remove a coach\n";
    cout << "4. Display train\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Train train;
    int choice, id;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter coach ID to add to front: ";
                cin >> id;
                train.addFront(id);
                break;
            case 2:
                cout << "Enter coach ID to add to end: ";
                cin >> id;
                train.addEnd(id);
                break;
            case 3:
                cout << "Enter coach ID to remove: ";
                cin >> id;
                train.removeCoach(id);
                break;
            case 4:
                train.displayTrain();
                break;
            case 5:
                cout << "Exiting system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

// --- Explanation of Approach ---
// I used a doubly linked list, with each Node having 'next' and 'prev' pointers.
// The Train class manages 'head' and 'tail' pointers for O(1) additions to both ends.
// The removeCoach function finds the specified coach and updates the 'next' and 'prev'
// pointers of the surrounding nodes to unlink it, handling the head, tail, and middle cases.
// A destructor is included to prevent memory leaks by deallocating all nodes.