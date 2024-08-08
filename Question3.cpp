#include <iostream>
#include <sstream>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

string toLowerCase(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string removePunctuation(const string &str) {
    string result;
    for (char c : str) {
        if (!ispunct(c)) {
            result += c;
        }
    }
    return result;
}

int main() {
    cout << "Enter a paragraph: ";
    string paragraph;
    getline(cin, paragraph);

    map<string, int> wordFrequency;

    stringstream ss(paragraph);
    string word;

    while (ss >> word) {
        word = removePunctuation(word);
        word = toLowerCase(word);

        if (!word.empty()) {
            wordFrequency[word]++;
        }
    }

    cout << "Word frequencies:\n";
    for (const auto &entry : wordFrequency) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
