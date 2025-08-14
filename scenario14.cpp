// Question: 14
// Language: C++

#include <iostream>
#include <string>
using namespace std;

// Node class for each employee in the hierarchy
class Node {
public:
    string employeeName;
    Node* left;
    Node* right;

    Node(const string& name) {
        employeeName = name;
        left = nullptr;
        right = nullptr;
    }
};

// BinaryTree class to manage the hierarchy
class BinaryTree {
private:
    Node* root;

    // Recursive helper function to insert a new node
    Node* insertRecursive(Node* current, const string& name) {
        if (current == nullptr) {
            return new Node(name);
        }
        if (name < current->employeeName) {
            current->left = insertRecursive(current->left, name);
        } else {
            current->right = insertRecursive(current->right, name);
        }
        return current;
    }

    // Recursive helper function for inorder traversal
    void inorderRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }
        inorderRecursive(current->left);
        cout << current->employeeName << " ";
        inorderRecursive(current->right);
    }

    // Recursive helper to delete all nodes and free memory
    void destroyRecursive(Node* current) {
        if (current != nullptr) {
            destroyRecursive(current->left);
            destroyRecursive(current->right);
            delete current;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroyRecursive(root);
    }

    void insert(const string& name) {
        root = insertRecursive(root, name);
    }

    void printInorder() {
        cout << "\n--- Employee Hierarchy (Inorder Traversal) ---" << endl;
        if (root == nullptr) {
            cout << "The hierarchy is empty." << endl;
        } else {
            inorderRecursive(root);
            cout << endl;
        }
        cout << "----------------------------------------------" << endl;
    }
};

// Function to display the user menu
void showMenu() {
    cout << "\nEmployee Hierarchy Menu:\n";
    cout << "1. Add an employee\n";
    cout << "2. Display hierarchy (inorder)\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    BinaryTree companyHierarchy;
    int choice;
    string name;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // Consume the newline character left by cin

        switch (choice) {
            case 1:
                cout << "Enter the employee name to add: ";
                getline(cin, name);
                companyHierarchy.insert(name);
                cout << "Added '" << name << "' to the hierarchy." << endl;
                break;
            case 2:
                companyHierarchy.printInorder();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

// --- Explanation of Approach ---
// I've implemented a binary search tree where each node stores an employee's name.
// The 'insert' function places new employees based on alphabetical order. The 'printInorder'
// method uses a recursive helper function that traverses the left subtree, prints the root node,
// and then traverses the right subtree. This naturally prints the employee names in alphabetical order.