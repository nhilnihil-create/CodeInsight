#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int u32;
typedef pair<int, int> p;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int Inf = (1<<30);
ll inf = (1LL<<60);
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
	int n;
	cin >> n;
	int t;
	cin >> t;
	int i;
	ll ans = 0;
	int zen = 0;
	for (i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (n >= 1) ans += min(t, a - zen);
		zen = a;
	}
	ans += t;
	cout << ans;
	return 0;
}