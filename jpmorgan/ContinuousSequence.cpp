#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

void findContinuousSequence(const string& testcase) {
    string part;
    istringstream iss(testcase);
    vector<int> numbers;

    while (iss >> part) {
        try {
            numbers.push_back(stoi(part));
        }
        catch (invalid_argument) {
            cout << "invalid testcase : " << testcase << endl;
        }

    }

    vector < vector<int>> sequences;
    vector<int> temp;

    for (int num : numbers) {
        if (temp.empty() or num == temp[temp.size() - 1] + 1)
            temp.push_back(num);
        else {
            if (temp.size() > 1)
                sequences.push_back(temp);
            temp.clear();
            temp.push_back(num);
        }
    }

    if (temp.size() > 1)
        sequences.push_back(temp);

    for (const auto& seq : sequences) {
        copy(seq.begin(), seq.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

int main() {
    vector<string> TestCases = {
             "1 2 3 5 9 a 6 7 8 4 @ -5 -7 -3 -2 -1",
            "10 11 12 14 15 16 20",
            "a b c d e f",
            "5 6 7 8 -1 0 1 100 101",
            "3 5 7 9 -1 -2 -3 -4",
            "1 2 3 4 5 6 7 8 9 10",
            "-10 -9 -8 -7 0 1 2 3 4 5",
            "50 51 52 53 54 100 101 102"
    };

    for (const auto& testcase : TestCases) {
        cout << "Input : " << testcase << endl;
        findContinuousSequence(testcase);
        cout << endl;
    }

	return 0;
}