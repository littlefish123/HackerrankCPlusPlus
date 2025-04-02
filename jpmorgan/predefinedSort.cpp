// sort elements of a list in a predefined order
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	vector<int> elements = {100, 65, 70, 90, 3, 2,105};
	vector<int> predefinedOrder = { 2, 3, 65, 100, 70, 90, 105 };

	// Create a map to store the index of each element in the predefined order
	unordered_map<int, int> orderMap;
	for (size_t i = 0; i < predefinedOrder.size(); ++i) {
		orderMap[predefinedOrder[i]] = i;
	}

	// Sort elements based on their index in the predefined order
	sort(elements.begin(), elements.end(), [&orderMap](int a, int b) {
		return orderMap[a] < orderMap[b];
		});

	for_each(elements.begin(), elements.end(), [](int element) {
		cout << element << " " ;
		});
	cout << endl;

	return 0;
}