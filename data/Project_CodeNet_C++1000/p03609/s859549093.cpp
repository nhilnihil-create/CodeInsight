#include"bits/stdc++.h"
using namespace std;

int main() {
	int X, t;
	cin >> X >> t;
	X -= t;
	if (X < 0) {
		X = 0;
	}
	cout << X << endl;
	return 0;
}