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
int n;
int a[1000000];
int b[1000000];
int x[1000000];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		a[x[i]] = i;
		b[x[i]] = i;
	}
	int sum = 0;
	queue<H>q;
	for (int i = n * n; i >= 1; i--) {
		if (b[i] > 0 && b[i] < n) {
			q.push(H{ b[i],n - b[i] });
		}
	}
	for (int i = n * n; i >= 1; i--) {
		if (q.empty()) continue;
		if (b[i] == q.front().x) {
			cout << "No\n";
			return 0;
		}
		if (b[i] == 0) {
			a[i] = q.front().x;
			q.front().y--;
			if (q.front().y == 0) q.pop();
		}
	}
	if (!q.empty()) {
		cout << "No\n";
		return 0;
	}
	for (int i = 1; i <= n * n; i++) {
		if (b[i] > 0 && b[i] > 1) {
			q.push(H{ b[i],b[i] - 1 });
		}
	}
	for (int i = 1; i <= n * n; i++) {
		if (q.empty()) continue;
		if (b[i] == q.front().x) {
			cout << "No\n";
			return 0;
		}
		if (b[i] == 0 && a[i] == 0) {
			a[i] = q.front().x;
			q.front().y--;
			if (q.front().y == 0) q.pop();
		}
	}
	if (!q.empty()) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for (int i = 1; i <= n * n; i++) {
		cout << (i == 1 ? "" : " ") << a[i];
	}
	cout << endl;
}