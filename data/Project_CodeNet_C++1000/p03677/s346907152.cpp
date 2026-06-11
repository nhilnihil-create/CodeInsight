#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
using namespace std;
///////////////////library zone!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef long long ll;
typedef long double ld;
#define all(a) (a).begin(),(a).end()
const ll Mod = 1000000007;
const ll mod = 998244353;
struct H {
	ll x, y;
	bool operator<(const H &b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H &b) const {
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H &b) const { return x == b.x&&y == b.y; }
	bool operator!=(const H &b) const { return (*this) != b; }
};
struct P {
	ll pos, cost;
	bool operator<(const P &b) const { return cost < b.cost; }
	bool operator>(const P &b) const { return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E &b) const { return cost < b.cost; }
	bool operator>(const E &b) const { return cost > b.cost; }
};
template<typename T, typename U>
void chmin(T &a, U b) {
	if (a > b) a = b;
}
template<typename T, typename U>
void chmax(T &a, U b) {
	if (a < b) a = b;
}
template<typename T>
T max_0(T a) {
	if (a < 0) return 0;
	return a;
}
template<typename T>
T min_0(T a) {
	if (a > 0) return 0;
	return a;
}
ll read() {
	ll u;
	scanf("%lld", &u);
	return u;
}
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j%i, i);
}
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}//x^n%p
const ll Inf = 3023372036854775807;
const int inf = 1500000000;
#define int long long
//----------------------------------------------------
int n, m;
int a[200000];
int b[200000];
int c[200000];
int ma(int x) {
	x--;
	x %= m;
	x += m;
	x %= m;
	x++;
	return x;
}
signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1]) {
			ans += a[i + 1] - a[i];
			if (a[i + 1] < a[i] + 2) continue;
			b[a[i] + 2]++;
			b[a[i + 1] + 1]--;
			c[a[i + 1] + 1] += max_0(a[i + 1] - a[i] - 1);
		}
		else {
			ans += a[i + 1] + m - a[i];
			if (a[i] + 2 > m&&a[i + 1] < ma(a[i] + 2)) continue;
			if (a[i] + 2 > m) {
				b[ma(a[i] + 2)]++;
			}
			else {
				b[a[i] + 2]++;
				b[1]++;
				c[1] -= max_0(m - a[i] - 1);
			}
			b[a[i + 1] + 1]--;
			c[a[i + 1] + 1] += max_0(a[i + 1] + m - a[i] - 1);
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++) {
		if (i > 1) {
			b[i] += b[i - 1];
			c[i] += c[i - 1];
		}
		c[i] -= b[i];
		res = min(res, c[i]);
	}
	cout << ans + res << endl;
}