// Question: 7
// Minimum Window Substring Finder
// Language: C++

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For transform method
#include <limits>    // For numeric_limits method
using namespace std;

// Helper function to convert a string to lowercase
void toLower(string& str) {
    transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return tolower(c); });
}

string findMinWindow(string text, string pattern) {
    // Handle case-insensitivity by converting both to lowercase
    toLower(text);
    toLower(pattern);

    if (pattern.length() > text.length() || pattern.empty()) {
        return "";
    }

    // Frequency map for the pattern string S
    vector<int> patternMap(128, 0);
    for (char c : pattern) {
        patternMap[c]++;
    }

    int left = 0, minLeft = -1, minLen = numeric_limits<int>::max();
    int required = pattern.length(); // Total characters we need to find
    int count = 0; // Characters from pattern found in the current window

    // The sliding window
    for (int right = 0; right < text.length(); ++right) {
        char rightChar = text[right];

        // If the current character is part of the pattern, decrement its required count.
        // A count > 0 means it's a character we still need.
        if (patternMap[rightChar] > 0) {
            count++;
        }
        patternMap[rightChar]--; // Decrement count for any character

        // When we have found all required characters, we have a valid window.
        // Now, try to shrink it from the left.
        while (count == required) {
            // Check if this window is the smallest one yet.
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }

            // Move the left pointer to shrink the window
            char leftChar = text[left];

            // If the character we are about to remove was a required character,
            // then by adding it back to the map, we will eventually break the while loop
            // because our window will no longer be valid.
            patternMap[leftChar]++;
            if (patternMap[leftChar] > 0) {
                count--;
            }
            left++;
        }
    }

    if (minLeft == -1) {
        return "No valid window found";
    }

    return text.substr(minLeft, minLen);
}

int main() {
    std::string text, pattern;

    std::cout << "Enter the text (T): ";
    std::getline(cin, text);

    std::cout << "Enter the pattern (S): ";
    std::getline(cin, pattern);

    string result = findMinWindow(text,pattern);
    cout << "\nSmallest window: \"" << result << "\"" << endl;

    return 0;
}


// My Approach
// I implemented the sliding window algorithm using two pointers, 'left' and 'right'.
// A frequency map array tracks the characters required by the pattern string 'S'.
// The 'right' pointer expands the window while I decrement character counts in the map.
// Once all required characters are found, I shrink the window from the 'left', updating the minimum
// window size found so far. This process continues until the end of the text is reached, ensuring O(n) time complexity.