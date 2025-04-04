/*
 * A string is provided as input from console which consists
 * of integer value. Insert '*' if subsequent numbers are even
 * and insert '-' if subsequent numbers are odd.
 *
 * Input : 21462675756  Output: 214*6*2*67-5-7-56
 * INput : 98676555533 Output : 98*6765-5-5-5-5-3-3
 *
 * Read input character either by BufferedReader or by Scanner.
 */

#include <iostream>

using namespace std;

string detect(string& str) {
	string result = "";
	if (str.empty())
		return result;

	result += str[0]; // Add the first character to the result
	for (auto i = 1; i < str.size(); i++) {
		char prev = str[i - 1] - '0';
		char curr = str[i] - '0';
		if (prev % 2 == 0 && curr % 2 == 0) {
			result += '*';
		}
		else {
			if (prev % 2 != 0 && curr % 2 != 0) {
				result += '-';
			}
		}
		result += str[i]; // Add the current character to the result        
	}

	return result;

}

int main() {
	string input;
	cout << "Enter enter a number string : ";
	cin >> input;

	cout << "Output : " << detect(input) << endl;

	return 0;
}