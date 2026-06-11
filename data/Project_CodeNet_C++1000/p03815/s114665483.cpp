#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int64_t x;
	cin >> x;

	int64_t n = x / 11;
	n *= 2;
	int64_t m = x % 11;

	if (m) {
		if (m <= 6) {
			n++;
		}
		else {
			n += 2;
		}
	}
	
	cout << n << endl;
}