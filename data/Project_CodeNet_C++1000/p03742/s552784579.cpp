#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main () {
	long long x, y;
	cin >> x >> y;
	if (abs(x - y) >= 2) {
		cout << "Alice" << endl;
	}
	else {
		cout << "Brown" << endl;
	}
	return 0;
} 