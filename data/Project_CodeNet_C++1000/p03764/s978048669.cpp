#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define pb push_back
using ll = long long;
using ld = long double;
constexpr ll mod = 1000000007LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> x(n);
	vector<ll> y(m);
	rep(i,n) cin >> x[i];
	rep(i,m) cin >> y[i];
	ll sum1 = 0;
	ll sum2 = 0;
	ll acm1 = 0;
	ll acm2 = 0;
	rep(i,n) {
		sum1 += i * x[i] - acm1;
		sum1 %= mod;
		acm1 += x[i];
	}
	rep(i,m) {
		sum2 += i * y[i] - acm2;
		sum2 %= mod;
		acm2 += y[i];
	}
	cout << (sum1 * sum2) % mod << endl;
	return 0;
}