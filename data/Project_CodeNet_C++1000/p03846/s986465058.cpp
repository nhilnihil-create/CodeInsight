#define MOD 1000000007L
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long pow(long a, long b) {
	if (!b) return 1L;
	long c = pow(a, b / 2L);
	if (b % 2L) c = a * c % MOD * c % MOD;
	else c = c * c % MOD;
	return c;
}

int main() {
	int N, A;
	cin >> N;
	vector<long> a((N + 1) / 2);
	for (int i = 0; i < N; i++) {
		cin >> A;
		if (N % 2) {
			if (A % 2) {
				cout << 0 << endl;
				return 0;
			}
		}
		else {
			if (A % 2 == 0) {
				cout << 0 << endl;
				return 0;
			}
		}
		a[A / 2]++;
	}
	if (N % 2) {
		if (a.front() != 1L || any_of(a.begin() + 1, a.end(), [](long& a) { return a != 2L; })) {
			cout << 0 << endl;
			return 0;
		}
	}
	else {
		if (any_of(a.begin(), a.end(), [](long& a) { return a != 2L; })) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << pow(2L, static_cast<long>(N) / 2L) << endl;
}