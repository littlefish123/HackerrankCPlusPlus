#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int NO_OF_CHARS = 256;

bool areAnagram(const string& str1, const string& str2) {
    if (str1.length() != str2.length())
        return false;

    int count[NO_OF_CHARS] = { 0 };

    for (auto i = 0; i < str1.length(); i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    for (auto i = 0; i < NO_OF_CHARS; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}

void findAnagram(const vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (areAnagram(arr[i], arr[j])) {
                cout << arr[i] << " is anagram of " << arr[j] << endl;
            }
        }
    }
}

int main() {
    vector<string> arr = { "geeksquiz", "geeksforgeeks", "abcd", "forgeeksgeeks", "zuiqkeegs" };
    findAnagram(arr);
    return 0;
}
