// https://www.hackerrank.com/challenges/prettyprint/problem

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        // # - 0x  l - double   x - lowercase hexidecimal
        printf("%#lx\n",(long int)A);

        char str[16];  
        sprintf(str,"%+.2f\n", B);
        string a(str);
        for (int i=0; i < (15-a.length()+1); i++)
             printf("_");
        printf(str);

        printf("%.9E\n",C);

	}
	return 0;

}