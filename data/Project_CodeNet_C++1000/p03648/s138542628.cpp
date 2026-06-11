#include<iostream>
using namespace std;

int main() {
	long long n = 50, k, a[50];
	cin >> k;
	for (int i = 0; i < n; i++) {
		a[i] = n - 1 + k / n;
	}
	k %= n;
	for (int i = 0; i < k % n; i++) {
		a[i] += n - k + 1;
	}
	for (int i = k % n; i < n; i++) {
		a[i] -= k;
	}
	cout << n << endl;
	for (auto&& x : a)cout << x << ' ';
	cout << endl;
	return 0;
}