// Question: 4
// Find K Smallest Elements(Heaps)
// Language: C++

#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Helper functions to get parent and child indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // This function maintains the min-heap property from a given node downwards.
    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            // Manual swap
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;

            heapifyDown(smallest);
        }
    }

public:
    // Constructor to build the heap from an array.
    MinHeap(const vector<int>& array) {
        heap = array;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Function to extract the minimum element (the root).
    int extractMin() {
        // Simple error handling for an empty heap
        if (heap.empty()) {
            cerr << "Error: Heap is empty. Cannot extract." << endl;
            return -1; // Return a sentinel value
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return root;
    }

    // Function to check if the heap is empty.
    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    // User Input
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the " << n << " prices, separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int k;
    cout << "Enter the number (k) of cheapest items to find: ";
    cin >> k;

    // Input Validation
    if (k > n || k <= 0) {
        cout << "Error: k must be a positive number and not larger than the number of items." << std::endl;
        return 1; // Exit with an error
    }

    // Use the MinHeap to Find and Print Results
    MinHeap minHeap(prices);

    cout << "\nThe " << k << " cheapest items are: ";
    for (int i = 0; i < k; ++i) {
        if (!minHeap.isEmpty()) {
            cout << minHeap.extractMin() << " ";
        }
    }
    cout << endl;

    return 0;
}

// My Approach
// I have implemented a min-heap data structure manually as required.
// The solution first converts the entire array of prices into a min-heap in O(n) time.
// Then, it extracts the minimum element 'k' times, with each extraction taking O(log n) time.
// This approach efficiently finds the k smallest elements within the required time complexity.