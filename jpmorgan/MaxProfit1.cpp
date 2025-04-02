/* https://www.hackerrank.com/challenges/stockmax/problem

Your algorithms have become so good at predicting the market that you now know what the share price of Wooden Orange Toothpicks Inc. (WOT)will be for the next number of days.

Each day, you can either buy one share of WOT, sell any number of shares of WOT that you own, or not make any transaction at all.What is the maximum profit you can obtain with an optimum trading strategy ?

Example

Buy one share day one, and sell it day two for a profit of.Return .

No profit can be made so you do not buy or sell stock those days.Return .

Please use Dynamic Programming

Example

prices = [1,2] Output = 1
prices = [2,1] Output = 0

STDIN       Function
-----       --------
3           q = 3
3           prices[] size n = 3
5 3 2       prices = [5, 3, 2]
3           prices[] size n = 3
1 2 100     prices = [1, 2, 100]
4           prices[] size n = 4
1 3 1 2     prices =[1, 3, 1, 2]

STUDIN
------
3
7
100 180 260 310 40 535 695
6
10 22 5 75 65 80
5
100 90 80 50 25

Output:
2745
223
0

*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int maxProfit(vector<int>& prices) {
	int profit=0, maxprice = 0;
	for (int i = prices.size()-1; i >= 0; i--) {
		maxprice = max(maxprice, prices[i]);
		profit += max(0, maxprice - prices[i]);
	}

	return profit;
}

int main() {
	int q;
	cout << "Enter case number : ";
	cin >> q;
	while (q--) {
		int n;
		cout << "Enter price size : ";
		cin >> n;
		cin.ignore(1, '\n'); // ignore the newline character

		cout << "Enter price (space-separated) : ";
		string line;
		getline(cin, line);

		istringstream iss(line);
		int num;
		vector<int> prices;
		while (iss >> num)
			prices.push_back(num);

		cout << "Maximum Profit : " << maxProfit(prices) << endl;
	
	}
	return 0;
}