#include<iostream>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long sum = 0;
	if (a % 2 == 1 && b % 2 == 1 && c % 2 == 1) {
		if (a >= b && a >= c) {
			sum = b * c;
			cout << sum << endl;
		}
		else if (b >= a && b >= c) {
			sum = a * c;
			cout << sum << endl;
		}
		else if (c >= b && c >= a) {
			sum = a * b;
			cout << sum << endl;
		}
	}
	else {
		cout << 0 << endl;
	}
	//return 0;
}