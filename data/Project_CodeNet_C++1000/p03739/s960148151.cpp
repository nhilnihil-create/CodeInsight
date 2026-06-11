#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int64_t n;
	cin >> n;

	vector<int64_t> v(n);
	for (int64_t i = 0; i < n; i++) {
		cin >> v.at(i);
	}

	int64_t a, b;
	a = 0;
	b = 0;

	int64_t sum = 0;
	for (int64_t i = 0; i < n; i++) { //plus first
		if (!i) {
			if (v.at(i) >= 0) {
				if (!v.at(0)) {
					a++;
					sum = 1;
				}
				else {
					sum = v.at(i);
				}
			}
			else {
				sum = 1;
				a += abs(v.at(i)) + 1;
			}
		}
		else {
			int64_t n = sum + v.at(i);
			//cout << "n:" << n << endl;

			if (i % 2) {
				if (n > 0) {
					a += abs(n) + 1;
					sum = -1;
				}
				else {
					if (!n) {
						a++;
						sum = -1;
					} else {
						sum = n;
					}
				}
			}
			else {
				if (n < 0) {
					a += abs(n) + 1;
					sum = 1;
				}
				else {
					if (!n) {
						a++;
						sum = 1;
					}
					else {
						sum = n;
					}
				}
			}
		}
	}

	for (int64_t i = 0; i < n; i++) { //minus first
		if (!i) {
			if (v.at(i) <= 0) {
				if (!v.at(0)) {
					b++;
					sum = -1;
				}
				else {
					sum = v.at(i);
				}
			}
			else {
				sum = -1;
				b += abs(v.at(i)) + 1;
			}
		}
		else {
			int64_t n = sum + v.at(i);

			if (i % 2) {
				if (n < 0) {
					b += abs(n) + 1;
					sum = 1;
				}
				else {
					if (!n) {
						b++;
						sum = 1;
					}
					else {
						sum = n;
					}
				}
			}
			else {
				int64_t n = sum + v.at(i);
				if (n > 0) {
					b += abs(n) + 1;
					sum = -1;
				}
				else {
					if (!n) {
						b++;
						sum = -1;
					}
					else {
						sum = n;
					}
				}
			}
		}
	}

	//cout << "a:" << a << endl;
	//cout << "b:" << b << endl;

	cout << min(a, b) << endl;
}