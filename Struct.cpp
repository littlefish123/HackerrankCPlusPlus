
//https://www.hackerrank.com/challenges/c-tutorial-struct/problem
// difference between class and struct in C++14
//https://blogs.sw.siemens.com/embedded-software/2014/06/02/struct-vs-class-in-c/#:~:text=The%20only%20difference%20between%20a,a%20class%20they%20are%20private.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    add code for struct here.
*/
struct Student {
    int age;
    string first_name;
    string last_name;
    string standard;
};

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}