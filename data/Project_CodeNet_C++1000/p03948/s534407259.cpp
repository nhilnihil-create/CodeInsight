#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<18;
int n, t;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> t;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	int q = 0, r;
	for(int m = 1<<30, i = 0; i < n; i++) {
		m = min(m, a[i]);
		q = max(q, a[i] - m);
	}
	for(int m = 1<<30, i = 0; i < n; i++) {
		m = min(m, a[i]);
		r += q == (a[i] - m);
	}
	cout << r;
}
