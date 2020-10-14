// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> v;
    int a=0;
    char ch;
    stringstream ss(str);
    while (ss) {
        ss >> a >> ch;
        v.push_back(a);
    }

    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}