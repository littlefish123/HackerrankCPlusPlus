/*
 * Find smallest Kth element in an unsorted array
 * if smallest Kth element is not present return NULL.
 *
 * Input : 0 1 0 1 1 1 1 0 0 1 K=3 Output : NULL
 * Input : 9 3 2 7 2 5 3 8 K=4 Output : 7
 */

#include <iostream>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

int findKSmallest(set<int>& uniqueElements, int K) {
    if (K > uniqueElements.size())
        return -1;

    auto it = uniqueElements.begin();
    advance(it, K - 1);
    return *it;
}


int main() {
    cout << "Enter numbers (space-separated) : ";
    string line;
    getline(cin, line);

    cout << "Enter K : ";
    int K;
    cin >> K;

    istringstream iss(line);
    int num;
    set<int> uniqueElements;

    while (iss >> num)
        uniqueElements.insert(num);

    int result = findKSmallest(uniqueElements, K);

    cout << "Output : " << (result == -1 ? "NULL" : to_string(result)) << endl;

    return 0;
}
