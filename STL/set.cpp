// https://www.hackerrank.com/challenges/cpp-sets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size=0, query=0, mark=0;
    set<int> s;
    cin >> size;
    for (int i=0; i < size; i++) {
        cin >> query >> mark;
        switch (query) {
            case 1:
                s.insert(mark);
                break;
            case 2:
                if (s.find(mark) != s.end())
                    s.erase(mark);
                break;
            case 3:
                if (s.find(mark) != s.end())
                    cout << "Yes\n";
                else
                    cout << "No\n";
                break;
        }
    }
    return 0;
}