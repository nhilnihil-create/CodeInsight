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
	bool operator<(const P &b) const{ return cost < b.cost; }
	bool operator>(const P &b) const{ return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E &b) const{ return cost < b.cost; }
	bool operator>(const E &b) const{ return cost > b.cost; }
};
struct H {
	ll x, y;
	bool operator<(const H &b) const{
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H &b) const{
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H &b) const{ return x == b.x&&y == b.y; }
	bool operator!=(const H &b) const{ return (*this) != b; }
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
int n;
int a[1000];
H b[1000];
signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int m = 0;
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n&&a[j] == a[i]) j++;
		b[m++] = H{ a[i],j - i };
		i = j;
	}
	bool l = 1;
	int mi = a[0], ma = a[n - 1];
	if (mi != ceil(ma / 2.0)) l = 0;
	if (n > 2 && ma == 1) l = 0;
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			if (ma % 2 == 0 && b[0].y != 1) l = 0;
			if (ma % 2 == 1 && b[0].y != 2) l = 0;
		}
		else {
			if (b[i].y < 2) l = 0;
			if (b[i - 1].x != b[i].x - 1) l = 0;
		}
	}
	if (l) cout << "Possible\n";
	else cout << "Impossible\n";
}