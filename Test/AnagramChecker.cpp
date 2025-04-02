#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

bool areAanagram(string str1, string str2) {
	if (str1.length() != str2.length()) {
		return false;
	}
	str1.erase(remove_if(str1.begin(), str1.end(), [](char c) {
		return !isalnum(c);
		}), str1.end());
	str2.erase(remove_if(str2.begin(), str2.end(), [](char c) {
		return !isalnum(c);
		}), str2.end());

	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	return str1 == str2;
}

int main() {
	string word1 = "listen";
	string word2 = "silent";

	if (areAanagram(word1, word2)) {
		cout << word1 << " and " << word2 << " are anagrams." << endl;
	}
	else {
		cout << word1 << " and " << word2 << " are not anagrams." << endl;
	}

	return 0;
}