// https://www.hackerrank.com/challenges/arrays-introduction/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/**
int main() {

    int eleNum=0;
    cin >> eleNum;  
    int ele[eleNum];
    for (int i=0; i < eleNum; i++)
        cin >> ele[i];
    for (int i=eleNum-1; i >= 0; i--)
        cout << ele[i] << " ";
    return 0;
}
**/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int eleNum,i=0;
    cin >> eleNum;
    int *v = new int[eleNum];  
    while (cin >> v[i++] );
    while (cout << v[--eleNum] << " " && eleNum > 0);
    delete[] v;
    return 0;
}
