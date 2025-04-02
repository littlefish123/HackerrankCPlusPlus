#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void getTop10Words(string filePath) {
	ifstream file(filePath);
	if (!file.is_open()) {
		cout << "File not found" << endl;
		return;
	}

	unordered_map<string, int> wordCount;
	string line, word;
	while (getline(file, line)) {
		transform(line.begin(), line.end(), line.begin(), [](char c) {
			return isalpha(c) ? tolower(c) : (isspace(c) ? c : ' ');
			});

		istringstream iss(line);
		while (iss >> word) {
			wordCount[word]++;
		}
	}

	file.close();

	auto cmp = [](auto& a, auto& b) {
		return a.second < b.second;
	};

	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> maxheap(cmp);

	for (const auto& wc : wordCount) {
		maxheap.push(wc);
	}

	cout << "Top 10 frequent words : " << endl;
	for (int i = 0; i < 10 && !maxheap.empty(); i++) {
		auto top = maxheap.top();
		maxheap.pop();
		cout << top.first << " : " << top.second << endl;
	}

}

int main() {
	string filePath = "D:\\hackerranksolution\\java\\ubs\\src\\jpmorgan\\tenword.txt";
	getTop10Words(filePath);
	return 0;
}