#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if ((a == b + c) || (b == a + c) || (c == a + b)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
