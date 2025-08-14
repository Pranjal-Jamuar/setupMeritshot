// Question: 2
// Student Ranking
// Language: C++

#include <iostream>
#include <vector>
using namespace std;

// Function to perform selection sort in descending order
void selectionSort(vector<int>& marks) {
    int n = marks.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++)
            if (marks[j] > marks[maxIndex]) maxIndex = j;

        // Swapping the values using a temporary variable
        int temp = marks[i];
        marks[i] = marks[maxIndex];
        marks[maxIndex] = temp;
    }
}

int main() {
    // User Input
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<int> marks(numStudents);
    cout << "Enter the marks for each student: ";
    for (int i = 0; i < numStudents; i++) {
        cin >> marks[i];
    }

    // Calling the selectionSort function
    selectionSort(marks);

    // Providing the marks in descending order as the output
    cout << "\nSorted marks (descending order):" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    return 0;
}

// My Approach
// I implemented the Selection Sort algorithm to sort the marks in descending order.
// The code iterates through the array, finding the largest remaining element in each pass
// and swapping it into its correct position. This is done in-place and without
// using any built-in sorting functions as required.