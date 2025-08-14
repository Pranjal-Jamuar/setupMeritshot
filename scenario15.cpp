// Question: 15
// Priority Based Job Scheduling(Heap)
// Language: C++

#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper functions to get parent and child indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Moves an element down the heap to its correct spot to maintain the max-heap property
    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            // Manual swap
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            heapifyDown(largest);
        }
    }

public:
    // Constructor: builds the max heap from an initial array of job priorities
    MaxHeap(const vector<int>& jobs) {
        heap = jobs;
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    // Extracts the root (highest priority job)
    int extractMax() {
        if (heap.empty()) {
            cerr << "Error: No jobs to process." << endl;
            return -1;
        }
        int highestPriorityJob = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return highestPriorityJob;
    }

    // Checks if the heap is empty
    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    // --- Get User Input ---
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<int> jobPriorities(n);
    cout << "Enter the " << n << " job priorities, separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> jobPriorities[i];
    }

    cout << "\nPriorities received. Building schedule..." << endl;

    // Create a MaxHeap. The constructor will automatically build the heap.
    MaxHeap jobScheduler(jobPriorities);

    cout << "\nProcessing jobs in order of priority:" << endl;
    while (!jobScheduler.isEmpty()) {
        int nextJob = jobScheduler.extractMax();
        if (nextJob != -1) { // Check for sentinel value in case of error
             cout << "Processing job with priority: " << nextJob << endl;
        }
    }

    return 0;
}


// --- Explanation of Approach ---
// I implemented a Max Heap using a vector to manage a list of job priorities.
// The core logic is in the 'heapifyDown' function, which ensures that every parent node
// is larger than its children. The constructor builds the initial heap. The 'extractMax'
// method removes and returns the highest-priority job (the root) and restores the heap property,
// simulating a priority-based job scheduler as required.