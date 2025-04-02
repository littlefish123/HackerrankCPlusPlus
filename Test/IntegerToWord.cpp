#include <iostream>
#include <vector>

using namespace std;

class IntegerToWord {
private:
	const vector<string> units = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const vector<string> tens = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	const vector<string> thousands = { "", "thousand", "million", "billion" };

	string convertBelowThousand(int number) {
		string words;
		if (number >= 100) {
			words += units[number / 100] + " hundred ";
			number %= 100;
		}

		if (number > 0) {
			if (number < 20)
				words += units[number];
			else {
				words += tens[number / 10];
				if (number % 10 != 0)
					words += "-" + units[number % 10];
			}
		}

		return words;
	}

public:
	string convert(int number) {
		if (number == 0)
			return "zero";

		string words;
		int i = 0;
		while (number > 0) {
			if (number % 1000 != 0) {
				words = convertBelowThousand(number % 1000) + " " + thousands[i] + " " + words;
			}
			number /= 1000;
			i++;
		}
		return words;
	}
};



int main() {
	IntegerToWord itw;
	cout << itw.convert(1812345) << endl;
	return 0;
}