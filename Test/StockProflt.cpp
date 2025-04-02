/*
https://www.geeksforgeeks.org/stock-buy-sell/
Given an array prices[] of size n denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.
*/

#include <iostream>
#include <vector>

using namespace std;

#ifdef DEBUG
int maxProfit(vector<int>& prices, int start, int end) {
	if (end <= start)
		return 0;
	int profit = 0;
	for (int i = start; i < end - 1; ++i) {
		if (prices[i + 1] > prices[i])
			profit += prices[i + 1] - prices[i];
	}
	return profit;
}
#endif

#ifdef DEBUG1
int maxProfit(vector<int>& prices, int start, int end) {
	if (end <= start)
		return 0;

	int profit = 0;
	for (size_t i = start; i < end; i++) {
		for (size_t j = i + 1; j < end; j++) {
			if (prices[j] > prices[i]) {
				int currentProfit = (prices[j] - prices[i]) + maxProfit(prices, j + 1, end)
					+ maxProfit(prices, start, i - 1);
				profit = max(profit, currentProfit);
			}
		}
	}

	return profit;
}
#endif

int main() {
	// DEBUG version
	vector<int> prices = { 100, 180, 260, 310, 40, 535, 695 };  // output : 865
	// vector<int> prices = { 10,22,5,75,65,80 };  // output : 97
	// vector<int> prices = {100,90,80,50,25};  // output : 0

	// vector<int> prices = { 100, 180, 260, 310, 40, 535, 695 };  // output : 865
	// vector<int> prices = { 10,22,5,75,65,80 };  // output : 97
	// vector<int> prices = { 100,90,80,50,25 };  // output : 0


	cout << "Maximum Profit : " << maxProfit(prices, 0, prices.size());
	return 0;
}