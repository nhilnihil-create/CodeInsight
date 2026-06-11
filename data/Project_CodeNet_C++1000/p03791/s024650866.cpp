#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
const long long mod = 1000000007;
int x[100006];
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> x[i];
	int now = 1;
	rep(i, n) {
		if (now <= x[i]) {
			x[i] = now; now += 2;
		}
		else {
			now = x[i] + 1;
		}
	}
	queue<int>Q;
	rep(i, n - 1) {
		if (x[i + 1] - x[i] == 1)Q.push(i);
	}
	int res = 1, rem = 0;
	while (Q.size()) {
		int q = Q.front(); Q.pop();
		if (Q.size())Q.pop();
		res *= (q + 2 - rem);
		res %= mod;
		rem++;
	}
	rep(i, n-rem) {
		res *= i + 1; res %= mod;
	}
	cout << res << endl;
}
