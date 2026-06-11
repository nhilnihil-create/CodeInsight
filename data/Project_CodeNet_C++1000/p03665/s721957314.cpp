#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[100];
ll po(ll n, int a) {
	ll res = 1;
	rep(i,a) res *= n;
	return res;
}
int main() {
	int n, p;
	int even = 0, odd = 0;
	cin >> n >> p;
	rep(i,n) {
		cin >> a[i];
		if (a[i]%2 == 0) even++;
		else odd++;
	}
	
	if (even == n) {
		if (p == 0) cout << po(2,n) << endl;
		else cout << 0 << endl;
	} else {
		cout << po(2,n-1) << endl;
	}
	
	return 0;
}