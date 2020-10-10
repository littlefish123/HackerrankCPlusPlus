// https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size=0, query=0, a=0;
    vector<int> v;
    cin >> size;
    for (int i=0; i < size; i++) {
        cin >> a;
        v.push_back(a);
    }

    cin >> query;
    for (int i=0; i < query; i++) {
        cin >> a;
        vector<int>::iterator low = lower_bound(v.begin(), v.end(), a);
        if (v[low-v.begin()] == a)
            cout << "Yes " << low-v.begin()+1 << endl;
        else
            cout << "No " << low-v.begin()+1 << endl;
    }
    return 0;
}
