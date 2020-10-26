// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int queueNum=0,query=0, eleNum, n=0;
    string line;
    unordered_map<int, vector<int>*> queueRepo;
    cin >> queueNum >> query;
    for (int i=0; i < queueNum; i++) {
        cin >> eleNum;
        vector<int> *queue = new vector<int>;
        for (int j=0; j < eleNum; j++) {
            cin >> n;
            queue->push_back(n);
        }
        queueRepo.insert({i, queue});
    }

    int idx=0,position=0;
    for (int i=0; i < query; i++) {
        cin >> idx >> position;
        auto queueFound = queueRepo.find(idx);
        if (queueFound != queueRepo.end()) {
            vector<int>* queue = queueFound->second;
            cout << queue->at(position) << endl;
        }

    }


    return 0;
}
