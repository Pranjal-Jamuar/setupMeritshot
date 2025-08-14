// Question: 5
// Username Validator
// Language: C++

#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is a letter
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a letter or a digit
bool isLetterOrDigit(char c) {
    return isLetter(c) || (c >= '0' && c <= '9');
}

// Main validation function
bool isValidUsername(const string& username) {
    // Rule 2: Check for minimum length of 5 characters.
    if (username.length() < 5) {
        return false;
    }

    // Rule 1: Check if the first character is a letter.
    if (!isLetter(username[0])) {
        return false;
    }

    // Rule 3: Check that all other characters are letters or digits.
    // We start the loop from 1 since we've already checked the first character.
    for (int i = 1; i < username.length(); ++i) {
        if (!isLetterOrDigit(username[i])) {
            return false; // Found an invalid character
        }
    }

    // If all checks passed, the username is valid.
    return true;
}

int main() {
    string username;
    cout << "Enter a username to validate: ";
    getline(cin, username);

    if (isValidUsername(username)) {
        cout << "Valid Username" << endl;
    } else {
        cout << "Invalid Username" << endl;
    }

    return 0;
}

// My Approach
// The approach is to validate the username against the given rules sequentially.
// I first check for the minimum length. If that passes, I check if the first character
// is a letter. Finally, I loop through the rest of the string to ensure all
// characters are alphanumeric. If any rule fails, the function returns false immediately.