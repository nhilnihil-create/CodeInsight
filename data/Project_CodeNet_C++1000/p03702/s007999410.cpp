#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a, b; vector<int>h;

bool check(int s) {
	int c = a - b;
	vector<int>t = h;
	for (int i = 0; i < n; i++) {
		t[i] = max(0LL, t[i] - 1LL * s * b);
	}
	long long req = 0;
	for (int i = 0; i < n; i++) {
		req += (t[i] + c - 1) / c;
	}
	return req <= s;
}

int main() {
	cin >> n >> a >> b; h.resize(n);
	for (auto&& x : h)cin >> x;
	int L = 0, R = 1e9;
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		if (check(mid))R = mid; else L = mid;
	}
	cout << R << endl;
	return 0;
}