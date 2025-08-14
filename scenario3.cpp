// Question: 3
// Rotate an array
// Language: C++

#include <iostream>
#include <vector>
using namespace std;

// This function takes the array, a starting index, and an ending index.
void reverse(vector<int>& nums, int start, int end) {
    // Logic to reverse the elements between start and end inclusive.
    while (start < end)
    {
        // Manual Swap
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

// Main function to rotate the array
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0 || k <= 0 || k >= n) {
        return; // No rotation needed
    }

    // This handles cases where k might be larger than n
    k = k % n;

    // Step 1: Reverse the first k elements.
    reverse(nums, 0, k - 1);
    // Step 2: Reverse the remaining n-k elements.
    reverse(nums, k, n - 1);
    // Step 3: Reverse the entire array.
    reverse(nums, 0, n - 1);
}

int main() {
    // User Input
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter the number of positions to rotate left: ";
    cin >> k;

    // Print Original Array
    cout << "\n Original array: ";
    // Range based for loop
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Rotate and Print Result
    rotate(nums, k);

    cout << "Array after rotating by " << k << ": ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}

// My Approach
// This approach uses the Reversal Algorithm, which is highly efficient for this problem.
// It achieves the rotation in O(n) time and O(1) space by performing three
// in-place reversals on different segments of the array. This method avoids the high
// time complexity of one-by-one rotations and the high space complexity of using a temporary array.