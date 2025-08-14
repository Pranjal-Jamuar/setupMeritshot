// Question: 13
// Circular Queue for Parking
// Language: C++

#include <iostream>
using namespace std;

const int MAX_SPOTS = 10; // Max parking spots, can be set up to 1000

class CircularQueue {
private:
    int data[MAX_SPOTS];
    int front;
    int rear;
    int currentSize;
    int capacity;

public:
    // Constructor
    CircularQueue() {
        capacity = MAX_SPOTS;
        front = -1;
        rear = -1;
        currentSize = 0;
    }

    // Checks if the parking lot is full
    bool isFull() {
        return currentSize == capacity;
    }

    // Checks if the parking lot is empty
    bool isEmpty() {
        return currentSize == 0;
    }

    // A car enters the lot
    void enqueue(int carNumber) {
        if (isFull()) {
            cout << "Parking lot is full. Car " << carNumber << " cannot enter." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // First car
        }
        rear = (rear + 1) % capacity; // Move rear to the next circular spot
        data[rear] = carNumber;
        currentSize++;
        cout << "Car " << carNumber << " has parked." << endl;
    }

    // The first car leaves the lot
    void dequeue() {
        if (isEmpty()) {
            cout << "Parking lot is empty. No car to leave." << endl;
            return;
        }
        int leavingCar = data[front];
        front = (front + 1) % capacity; // Move front to the next circular spot
        currentSize--;
        cout << "Car " << leavingCar << " has left." << endl;
    }

    // Shows all cars currently parked
    void display() {
        cout << "\n--- Parked Cars ---" << endl;
        if (isEmpty()) {
            cout << "The parking lot is empty." << endl;
        } else {
            int count = 0;
            int i = front;
            while (count < currentSize) {
                cout << "Spot " << (i + 1) << ": Car " << data[i] << endl;
                i = (i + 1) % capacity;
                count++;
            }
        }
        cout << "-------------------" << endl;
    }
};

void showMenu() {
    cout << "\nParking Lot Menu:\n";
    cout << "1. Park a car (enqueue)\n";
    cout << "2. A car leaves (dequeue)\n";
    cout << "3. Display parked cars\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    CircularQueue parkingLot;
    int choice;
    int carNumber = 101; // Starting car number

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                parkingLot.enqueue(carNumber++);
                break;
            case 2:
                parkingLot.dequeue();
                break;
            case 3:
                parkingLot.display();
                break;
            case 4:
                cout << "Closing the parking lot." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// --- Explanation of Approach ---
// I've implemented a circular queue using a fixed-size array and indices for 'front' and 'rear'.
// The modulo operator (%) is used to wrap the indices around, making the array circular and
// efficiently reusing space. The 'currentSize' variable helps to easily check for full and empty
// conditions. This approach manually implements the FIFO queue logic as required.