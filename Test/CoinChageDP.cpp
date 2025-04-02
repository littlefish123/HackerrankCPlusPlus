/* 
* https://www.hackerrank.com/challenges/coin-change/problem?isFullScreen=true
* Input :
* 3 3
* 3 1 2
* Input :
* 4 3 
* 1 2 3
* OUtput : 4
*/
#include <iostream>
#include <vector>

using namespace std;

class Result {
public:
	static long getWays(int sum, int n, vector<long>& coins) {
		vector<long> dp(sum + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = coins[i]; j <= sum; j++)
				dp[j] += dp[j - coins[i]];
		}

		return dp[sum];
	}
};

int main() {
	int n, m;
	cout << "Enter sum : ";
	cin >> n;
	cout << "Enter m : ";
	cin >> m;

	vector<long> coins(m);
	cout << "Enter the coin denominations: ";
	for (int i = 0; i < m; i++)
		cin >> coins[i];

	long ways = Result::getWays(n, m, coins);
	cout << "No of ways : " << ways << endl;


	return 0;
}