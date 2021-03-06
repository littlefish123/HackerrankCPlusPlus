/* Enter your macros here */
// https://www.hackerrank.com/challenges/preprocessor-solution/problem

#define io(o) cin >> o
#define toStr(str) #str
#define INF (unsigned)!((int)0)
#define foreach(v,i)  \
    for (int i=0; i < v.size(); i++)
#define FUNCTION(func, pred)    \
    void func(int& a, int x) {  \
        if(!(a pred x)) a = x;  \
    }


#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}