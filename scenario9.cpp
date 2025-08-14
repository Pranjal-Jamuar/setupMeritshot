// Question: 9
// Playlist Manager
// Language: C++

#include <iostream>
#include <string>
using namespace std;

// Node class represents a single song in the playlist
class Node {
public:
    string songName;
    Node* next;

    Node(const string& name) {
        songName = name;
        next = nullptr;
    }
};

// Playlist class manages the linked list of songs
class Playlist {
private:
    Node* head;

public:
    Playlist() {
        head = nullptr;
    }

    // Destructor to free all memory allocated for nodes
    ~Playlist() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    // Adds a new song to the end of the playlist
    void addSong(const string& name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode; // List is empty, new node is the head
        } else {
            // Traverse to the end of the list
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // Link the new node at the end
            current->next = newNode;
        }
        std::cout << "Added '" << name << "' to the playlist." << std::endl;
    }

    // Deletes a song by its name
    void deleteSong(const string& name) {
        if (head == nullptr) {
            cout << "Playlist is empty. Nothing to delete." << endl;
            return;
        }

        // Case 1: The node to be deleted is the head
        if (head->songName == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted '" << name << "' from the playlist." << endl;
            return;
        }

        // Case 2: The node is in the middle or at the end
        Node* current = head->next;
        Node* prev = head;
        while (current != nullptr) {
            if (current->songName == name) {
                prev->next = current->next; // Unlink the node
                delete current;
                cout << "Deleted '" << name << "' from the playlist." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Song '" << name << "' not found in the playlist." << endl;
    }

    // Displays all songs currently in the playlist
    void displayPlaylist() {
        cout << "\n--- Current Playlist ---" << endl;
        if (head == nullptr) {
            cout << "The playlist is empty." << endl;
        } else {
            Node* current = head;
            int count = 1;
            while (current != nullptr) {
                cout << count << ". " << current->songName << endl;
                current = current->next;
                count++;
            }
        }
        cout << "------------------------" << endl;
    }
};

void showMenu() {
    cout << "\nPlaylist Manager Menu:\n";
    cout << "1. Add a song\n";
    cout << "2. Delete a song\n";
    cout << "3. Display playlist\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Playlist myPlaylist;
    int choice;
    string songName;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // Consume the newline character left by std::cin

        switch (choice) {
            case 1:
                cout << "Enter the song name to add: ";
                getline(cin, songName);
                myPlaylist.addSong(songName);
                break;
            case 2:
                cout << "Enter the song name to delete: ";
                getline(cin, songName);
                myPlaylist.deleteSong(songName);
                break;
            case 3:
                myPlaylist.displayPlaylist();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// My Approach
// I've implemented a singly linked list with a 'Node' class for songs and a 'Playlist' class for management.
// The 'addSong' method traverses to the end of the list to append a new node. The 'deleteSong' method
// handles three cases: an empty list, deleting the head, or deleting a node from the middle/end.
// A destructor is included in the 'Playlist' class to ensure all node memory is deallocated, preventing leaks.