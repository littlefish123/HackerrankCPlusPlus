#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

string getCharCountSequence(string& input) {
	if (input.empty()) {
		return "";
	}

	unordered_map<char, int> charCount;
	for (char ch : input) 
		charCount[ch]++;
	
	ostringstream result;
	for (auto entry : charCount)
		result <<  entry.second << entry.first;

	return result.str();
}

string getCharCount(string& input) {
	if (input.empty()) {
		return "";
	}

	int count = 1;
	ostringstream result;
	for (auto i = 1; i < input.length(); i++) {
		if (i < input.length() - 1 && input[i] == input[i -1]) 
			count++;
		else {
			result << to_string(count) << input[i-1];
			count = 1;
		}
	}

	result << to_string(count) << input[input.length() - 1];

	return result.str();
}

int main() {
	string input = "aabbbbccdddfaab";
	cout << "Character count for " + input + " : " + getCharCount(input) << endl;	
	cout << "Character count by Sequence " + input + " : " + getCharCountSequence(input) << endl;
	return 0;
}