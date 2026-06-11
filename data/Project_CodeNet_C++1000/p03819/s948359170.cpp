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
#include <climits>
#include<fstream>
using namespace std;
///////////////////library zone!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef long long ll;
typedef long double ld;
#define all(a) (a).begin(),(a).end()
const ll Mod = 1000000007;
struct P {
	ll pos, cost;
	bool operator<(const P &b) { return cost < b.cost; }
	bool operator>(const P &b) { return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E &b) { return cost < b.cost; }
	bool operator>(const E &b) { return cost > b.cost; }
};
struct H {
	ll x, y;
	bool operator<(const H &b) {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H &b) {
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H &b) { return x == b.x&&y == b.y; }
	bool operator!=(const H &b) { return (*this) != b; }
};
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j%i, i);
}
ld mod_pow(ll x, ll n, ll p) {
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
struct A {
	int x, y, z;
};
bool operator<(A a, A b) {
	return a.z < b.z;
}
A a[400000];
int dat[800000];
void add(int x, int y) {
	while (x <= m) {
		dat[x] += y;
		x += x & -x;
	}
}
int sum(int x) {
	int sum = 0;
	while (x > 0) {
		sum += dat[x];
		x -= x & -x;
	}
	return sum;
}
signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].z = a[i].y - a[i].x + 1;
	}
	sort(a, a + n);
	int t = 0;
	for (int i = 1; i <= m; i++) {
		int ans = 0;
		ans += n - t;
		for (int j = i; j <= m; j += i) {
			ans += sum(j);
		}
		for (; t < n&&a[t].z == i; t++) {
			add(a[t].x, 1);
			add(a[t].y + 1, -1);
		}
		cout << ans << endl;
	}
}