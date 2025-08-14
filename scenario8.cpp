// Question: 8
// Longest Repeating Character Replacement
// Language: C++

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For max method
using namespace std;

int characterReplacement(const string& s, int k) {
    int n = s.length();
    if (n == 0) {
        return 0;
    }

    int left = 0;
    int maxLength = 0;
    int maxFreq = 0; // Tracks the frequency of the most common character in the window
    vector<int> freqMap(26, 0); // Frequency map for uppercase letters 'A'-'Z'

    // The 'right' pointer expands the window
    for (int right = 0; right < n; right++) {
        // Increment the count of the character at the right pointer
        int charIndex = s[right] - 'A';
        freqMap[charIndex]++;

        // Update the max frequency seen in the current window
        maxFreq = max(maxFreq, freqMap[charIndex]);

        // Check if the current window is invalid.
        // The number of characters to replace is window_length - max_freq.
        int windowLength = right - left + 1;
        if (windowLength - maxFreq > k) {
            // If invalid, shrink the window from the left.
            // Decrement the count of the character leaving the window.
            freqMap[s[left] - 'A']--;
            left++;
        }

        // The current window size is a candidate for the max length.
        // The window only grows when a valid configuration is found.
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter the string (uppercase letters only): ";
    cin >> s;

    int k;
    cout << "Enter the max number of replacements (k): ";
    cin >> k;

    int result = characterReplacement(s, k);
    cout << "\n The length of the longest valid substring is: " << result << endl;

    return 0;
}


// --- Explanation of Approach ---
// I used the sliding window technique with two pointers, 'left' and 'right'.
// The core idea is to maintain a window where (window_length - most_frequent_char_count) <= k.
// I use a frequency map array to track character counts in the window. As I expand the window
// with 'right', I shrink it with 'left' only when the condition is violated, ensuring O(n) time complexity.