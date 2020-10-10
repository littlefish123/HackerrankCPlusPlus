// https://www.hackerrank.com/challenges/vector-erase/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int size=0, position=0, pos1=0, pos2=0, a=0;
    vector<int> v;
    
    cin >> size; 
    for (int i=0; i < size; i++) {
            cin >> a;
            v.push_back(a);
    }
    cin >> position;
    v.erase(v.begin() + position-1);

    cin >> pos1 >> pos2;
    if (pos2 > pos1  && pos2 < v.size())
        v.erase(v.begin() + pos1 -1, v.begin() + pos2 -1);

    cout << v.size() << endl;
    for (auto& n : v) {
        cout << n << " ";
    }
    return 0;
}
