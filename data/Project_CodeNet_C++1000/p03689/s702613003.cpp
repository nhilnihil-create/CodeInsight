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
int H, W, h, w;
int a[1000][1000];
signed main() {
	cin >> H >> W >> h >> w;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			a[i][j] = 1000;
		}
	}
	int res = 0;
	int t = -(h*w - 1) * 1000 - 1;
	a[h - 1][w - 1] = t;
	for (int i = h - 1; i < H; i += h) {
		for (int j = w - 1; j < W; j += w) {
			a[i][j] = t;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			res += a[i][j];
		}
	}
	if (res <= 0) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << (j == 0 ? "" : " ") << a[i][j];
		}
		cout << endl;
	}
}