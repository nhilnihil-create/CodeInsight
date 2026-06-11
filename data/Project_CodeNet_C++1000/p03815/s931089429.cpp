#include <bits/stdc++.h>

using namespace std;

int main() {

	long long x;
	cin >> x;

	long long ten=0;
	long amari = 0;
	if (x <= 6) {
		ten = 1;
	}
	else if( x <= 11) {
		ten = 2;
	}
	else {
		ten = (x / 11)*2;
		amari = x % 11;
		if (amari == 0) {
			ten = ten;
		}
		else if (amari <= 6) {
			ten ++;
		}
		else {
			ten =ten+2;
		}
	}
	cout << ten << endl;
	return 0;
}