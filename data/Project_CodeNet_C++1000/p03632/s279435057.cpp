#include<iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b <= c) { cout << 0 << endl; return 0; }
	if (a <= c && c <= b && b <= d) { cout << b - c << endl; return 0; }
	if (a <= c && d <= b) { cout << d - c << endl; return 0; }
	if (c <= a && b <= d) { cout << b - a << endl; return 0; }
	if (c <= a && a <= d && d <= b) {
		cout << d - a << endl; return 0;
}
	if (d <= a)cout << 0 << endl;
}