// change the following hashmap to sort by value instead of sort of key
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>


using namespace std;

int main() {
	unordered_map<string,int> hashmap = {
				{"a", 11}, {"w", 9}, {"c", 7}, {"d", 5}, {"b", 4}, {"n", 1}, {"m", 1}
	};

	multimap<int, string> sortedMap;
	for (const auto& pair : hashmap) {
		sortedMap.insert({ pair.second, pair.first });
	}

	for (const auto& pair: sortedMap) {
		cout << pair.first << " " << pair.second << endl;
	}


	return 0;
}