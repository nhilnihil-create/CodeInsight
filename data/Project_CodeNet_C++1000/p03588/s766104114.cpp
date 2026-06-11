#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000;
const ll mod = 1000000007;
ll test[12345678], res[12345678], aa[1234][1234], bb[1234][1234];
ll dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
char maze[1234][1234];
signed main() {
	ll n, m, k, sum = 0, num = 1000000000000000, cnt = 0, ans = 0; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> m >> k;
		if (num > k) {
			sum = m; num = k;
		}
	}
	cout << sum + num << endl;
	return 0;
}