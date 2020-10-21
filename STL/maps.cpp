// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string,int> s;
    int casenum=0,query=0,mark=0;
    string name;
    cin >> casenum;
    for (int i=0; i < casenum; i++) {
        cin >> query >> name;
        auto studentFound = s.find(name);
        
        switch(query)
        {
            case 1:
               cin >> mark;
               if(studentFound != s.end()) {
              //     studentFound->second += mark; 
                     s[name] += mark;
               }
               else {
                // either ways work for map insert
                    s[name] = mark;
              //     s.insert( {name, mark} );
               }
               break;
            case 2:
                if(studentFound != s.end()) {
                    // either ways work for locate vale in a map
                    //s.at(name) = 0;
                    s[name] = 0;
                }
                break;
            case 3:
                if(studentFound != s.end()) {
                 //   cout << studentFound->second << endl;
                      cout << s[name] << endl;
                }
                else {
                    cout << "0" << endl;
                }
            break;
        }
    }
    return 0;
}



