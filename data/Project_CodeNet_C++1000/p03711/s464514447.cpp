#include <bits/stdc++.h>

using namespace std;

int main() {

	long x, y;
	cin >> x >> y;

	if (x == 2 || y == 2 || x==11) { cout << "No" << endl; return 0; }
	if (x == 9 && y != 11) { cout << "No" << endl; return 0; }
	if (x == 6 && (y != 11 && y != 9)) { cout << "No" << endl; return 0; }
	if (x == 4 && (y != 11 && y != 9 && y != 6)) { cout << "No" << endl; return 0; }
	cout << "Yes" << endl;
}