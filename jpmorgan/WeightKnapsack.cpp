/***
* https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/ 
***/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int capacity, const vector<int>& value, const vector<int>& weight) {
	vector<int> dp(capacity + 1, 0);
	for (int i = 0; i <= capacity; i++) {
		for (int j = 0; j < value.size(); j++) {
			if (i - weight[j] >= 0){
				// dp[i] = max(notake, take)
				// notake = dp[i]
				// take = dp[i - weight[j]] + value[j]
				dp[i] = max(dp[i], dp[i - weight[j]] + value[j]);
			}
		}
	}

	return dp[capacity];
}

/* not efficient with recursive approach
int knapsackRecur(int i, int capacity, vector<int> value, vector<int> weight) {
	if (i == value.size())
		return 0;

	int take = 0;
	if (weight[i] <= capacity)
		take = value[i] + knapsackRecur(i, capacity - weight[i], value, weight);

	int notake = knapsackRecur(i + 1, capacity, value, weight);

	return max(take, notake);
}


int knapsack(int capacity, vector<int> value, vector<int> weight) {
	return knapsackRecur(0, capacity, value, weight);
}
*/


int main() {
	// vector<int> value = { 1,1 };
	// vector<int> weight = { 1,2 };
	// int capacity = 3;
	// output : 3

	// vector<int> value = { 1,30 };
	// vector<int> weight = { 1,50 };
	// int capacity = 100;
	// output : 100

	vector<int> value = { 10,40,50,70 };
	vector<int> weight = { 1,3,4,5 };
	int capacity = 8;
	// output : 110

	cout << knapsack(capacity, value, weight) << endl;
}
