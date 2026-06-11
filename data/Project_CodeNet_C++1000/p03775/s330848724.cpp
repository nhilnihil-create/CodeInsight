#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)

// 約数の列挙O(√n)
vector<ll> divisor(ll n) {
	vector<ll> res;
	for (ll i = 1; i*i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i != n / i) res.push_back(n / i);
		}
	}
	return res;
}
ll digits(ll n) {
	ll ans = 1;
	while (1) {
		if (n / 10 == 0) break;
		n /= 10; ans++;
	}
	return ans;
}

int main() {
	ll N; cin >> N;
	vector<ll> v = divisor(N);
	sort(v.begin(), v.end());
	ll ans = INF;
	for (auto it = v.begin(); it != v.end(); it++) {
		ll tmp = digits(*it);
		ll tmp2 = digits(N / (*it));
		ans = min(ans, max(tmp, tmp2));
	}
	cout << ans << endl;
}