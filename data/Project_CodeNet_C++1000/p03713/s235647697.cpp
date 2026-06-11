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
ll commax(ll x, ll y, ll z) {
	ll tmp = x;
	tmp = max(tmp, y);
	tmp = max(tmp, z);
	return tmp;
}
ll commin(ll x, ll y, ll z) {
	ll tmp = x;
	tmp = min(tmp, y);
	tmp = min(tmp, z);
	return tmp;
}
int main() {
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	if (x % 3 == 0) { // 縦に分割
		cout << 0;
		return 0;
	}
	else ans = y;
	if (y % 3 == 0) { // 横に分割
		cout << 0;
		return 0;
	}
	else ans = min(ans, x);
	int i;
	for (i = 1; i <= (x + 1) / 2; i++) { // 入出力例2のような切り分け方
		ll y1 = y / 2;
		ll y2 = y - y1;
		ll s1 = i * y;
		ll s2 = (x - i) * y1;
		ll s3 = (x - i) * y2;
		ll diff = commax(s1, s2, s3) - commin(s1, s2, s3);
		ans = min(ans, diff);
	}
	for (i = 1; i <= (y + 1) / 2; i++) { // 入出力例3のような切り分け方
		ll x1 = x / 2;
		ll x2 = x - x1;
		ll s1 = i * x;
		ll s2 = (y - i) * x1;
		ll s3 = (y - i) * x2;
		ll diff = commax(s1, s2, s3) - commin(s1, s2, s3);
		ans = min(ans, diff);
	}
	cout << ans;
	return 0;
}