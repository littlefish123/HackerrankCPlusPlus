// https://www.thepoorcoder.com/hackerrank-deque-stl-solution/
// https://www.hackerrank.com/challenges/deque-stl/problem

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<pair<int,int>> q;
    for (int i=0 ; i < n; i++) {
        while (!q.empty() && i - q.front().second >= k)
            q.pop_front();
        while (!q.empty() && q.back().first <= arr[i])
            q.pop_back();
       // q.push_back(make_pair(arr[i],i));
        q.push_back({arr[i],i});
        if (i >= k-1)
            cout << q.front().first << " ";
    }
    cout << "\n";
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}