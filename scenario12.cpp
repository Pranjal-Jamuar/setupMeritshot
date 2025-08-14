// Question: 12
// Undo Feature in Text Editor(stack)
// Language: C++

#include <iostream>
#include <string>
using namespace std;

const int MAX_CAPACITY = 100; // Define a max capacity for our array-based stack

class EditorStack {
private:
    string data[MAX_CAPACITY];
    int top; // Index of the top element

public:
    // Constructor initializes an empty stack
    EditorStack() {
        top = -1;
    }

    // Pushes a new word onto the stack
    void push(const string& word) {
        if (top >= MAX_CAPACITY - 1) {
            cout << "Error: Stack is full. Cannot add more words." << endl;
            return;
        }
        top++;
        data[top] = word;
        cout << "Typed: '" << word << "'" << endl;
    }

    // Pops the top word from the stack (Undo)
    void pop() {
        if (isEmpty()) {
            cout << "Undo failed: Nothing to undo." << endl;
            return;
        }
        cout << "Undo successful. Removed '" << data[top] << "'." << endl;
        top--;
    }

    // Returns the top word without removing it
    string peek() {
        if (isEmpty()) {
            return "Stack is empty.";
        }
        return data[top];
    }

    // Checks if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Displays the current text (all words in the stack)
    void displayText() {
        cout << "\n--- Current Text ---\n";
        if (isEmpty()) {
            cout << "[Empty]\n";
        } else {
            for (int i = 0; i <= top; ++i) {
                cout << data[i] << " ";
            }
            cout << "\n";
        }
        cout << "--------------------\n";
    }
};

void showMenu() {
    cout << "\nText Editor Menu:\n";
    cout << "1. Type a word (push)\n";
    cout << "2. Undo last word (pop)\n";
    cout << "3. View current text\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    EditorStack editor;
    int choice;
    string word;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter a word to type: ";
                cin >> word;
                editor.push(word);
                break;
            case 2:
                editor.pop();
                break;
            case 3:
                editor.displayText();
                break;
            case 4:
                cout << "Exiting editor." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


// --- Explanation of Approach ---
// I've manually implemented a stack using a fixed-size array and a 'top' index variable.
// The 'push' operation increments 'top' and adds an element, checking for overflow first.
// The 'pop' operation simulates 'undo' by simply decrementing 'top', effectively removing
// the last element. This LIFO (Last-In, First-Out) structure is managed entirely
// through array and index manipulation, as required by the constraints.