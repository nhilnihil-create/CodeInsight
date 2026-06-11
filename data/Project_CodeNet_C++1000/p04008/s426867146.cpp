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
const ll mod = 1000000007;
const ll Mod = 998244353;
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
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j%i, i);
}
ll mod_pow(ll x, ll n, ll p = mod) {
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
int n, k;
int a[200000];
H b[200000];
vector<int>e[200000];
int c[200000];
signed main() {
	cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1) e[a[i]].push_back(i);
		if (i > 1 && i == a[i]) ans++;
		if (i == 1 && i != a[i]) {
			ans++;
			a[i] = 1;
		}
		b[i].y = i;
		b[i].x = Inf;
	}
	queue<int>q;
	b[1].x = 0;
	int m = 1;
	q.push(1);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = 0; i < e[t].size(); i++) {
			if (b[e[t][i]].x > b[t].x + 1) {
				b[e[t][i]].x = b[t].x + 1;
				q.push(e[t][i]);
				m++;
			}
		}
	}
	sort(b + 1, b + n + 1);
	for (int i = m; i > 1; i--) {
		int t = b[i].y;
		c[t]++;
		if (c[t] == k && a[t] != 1) {
			c[t] = 0;
			ans++;
		}
		c[a[t]] = max(c[a[t]], c[t]);
	}
	cout << ans << endl;
}