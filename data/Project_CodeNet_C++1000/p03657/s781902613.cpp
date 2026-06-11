#include<iostream>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	bool ok = false;
	if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0)ok = true;
	cout << (ok ? "Possible" : "Impossible") << endl;

	return 0;
}