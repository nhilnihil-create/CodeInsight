#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define int long long
int n, a, b, h[123456];
bool f(int k) {
	int r = 0;
	int p = a - b;
	for (int i = 0; i < n; i++) {
		r += max((int)0, (h[i] - (k*b) + (p - 1)) / p);
	}
	return (r <= k);
}
int f1(int l, int r) {
	if (l == r)return l;
	if (l + 1 == r) {
		if (f(r))return r;
		else return l;
	}
	int mid = (l + r) / 2;
	return (f(mid) ? f1(l, mid) : f1(mid, r));
}
signed main() {
	cin >> n >> a >> b;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		m = max(h[i], m);
	}
	cout << f1(0, (m + b - 1) / b) << endl;
}