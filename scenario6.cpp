// Question: 6
// Word Frequency Counter
// Language: C++

#include <iostream>
#include <string>
#include <vector>
#include <sstream> // For stringstream method
#include <algorithm> // For transform method
using namespace std;

// Helper function to convert a string to lowercase
void toLower(string& str) {
    transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return tolower(c); });
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Using stringstream to easily parse words separated by spaces
    stringstream ss(sentence);
    string word;

    // Parallel vectors to store unique words and their counts
    vector<string> uniqueWords;
    vector<int> wordCounts;

    // Process each word from the stringstream
    while (ss >> word) {
        // Convert word to lowercase for case-insensitive comparison
        toLower(word);

        bool found = false;
        // Check if the word has been seen before
        for (int i = 0; i < uniqueWords.size(); ++i) {
            if (uniqueWords[i] == word) {
                // If found, increment its count and mark as found
                wordCounts[i]++;
                found = true;
                break;
            }
        }

        // If the word was not found, it's a new unique word
        if (!found) {
            uniqueWords.push_back(word);
            wordCounts.push_back(1); // Add its initial count of 1
        }
    }

    // Display the final word frequency count
    std::cout << "\n--- Word Frequency Report ---" << endl;
    for (int i = 0; i < uniqueWords.size(); ++i) {
        cout << "'" << uniqueWords[i] << "': " << wordCounts[i] << endl;
    }

    return 0;
}

// My Approach
// As maps were not allowed, I used two parallel vectors to track word frequencies.
// One vector stores the unique words, and the other stores their counts at corresponding indices.
// I parse the input sentence word by word, convert each to lowercase, and then search the unique words vector.
// If a word is found, its count is incremented; otherwise, the word and a count of 1 are added to the vectors.