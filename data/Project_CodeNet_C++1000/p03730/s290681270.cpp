#include<iostream>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	bool ok = false;
	for (int i = a; i <= a*b; i+=a) {
		if (i % b == c) {
			ok = true;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}