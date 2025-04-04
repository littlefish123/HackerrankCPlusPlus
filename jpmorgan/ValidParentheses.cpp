/* String input1 = "({{}]}}";
String input2 = "((([])))}";
*/ 

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string isBalanced(string s) {
	stack<char> stack;
	vector<char> open = { '(', '[', '{' };
	vector<char> close= { ')', ']', '}' };

	for (char ch : s) {
		if (find(open.begin(), open.end(), ch) != open.end())
			stack.push(ch);
		else if (find(close.begin(), close.end(), ch) != close.end()) {
			int pos = find(close.begin(), close.end(), ch) - close.begin();
			if (!stack.empty() && open[pos] == stack.top())
				stack.pop();
			else
				return "NO";
		}
	}

	return stack.empty() ? "YES" : "NO";
}

/*
int main() {
	int casenumber;
	cout << "Pls enter case number : ";
	cin >> casenumber;
	cin.ignore();

	for (int i = 0; i < casenumber; i++) {
		string s;
		getline(cin, s);

		cout << isBalanced(s) << endl;

	}

}
*/