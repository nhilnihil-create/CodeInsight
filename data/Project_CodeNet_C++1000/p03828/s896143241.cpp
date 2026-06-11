#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

template<typename T>
map<T, ll> factorize(T x) {
	map<T, ll> res;
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			x /= i;
			res[i]++;
		}
	}
	if (x != 1) res[x]++;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	ll ans = 1;
	map<int, ll> res;
	for (int i = 2; i <= n; ++i) {
		map<int, ll> mp = factorize(i);
		for (auto& c : mp) {
			res[c.first] += c.second;
		}
	}
	for (auto& c : res) {
		(ans *= (c.second + 1)) %= mod;
	}
	cout << ans << endl;
	return 0;
}
