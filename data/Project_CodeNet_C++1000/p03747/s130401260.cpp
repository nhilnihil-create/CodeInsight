#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
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
#define EPS (1e-5)
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
	ll k = scanf("%lld", &u);
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
vector<string>split(string s, char c = ' ') {
	vector<string>vec;
	string h = "";
	for (int i = 0; i < s.size();) {
		int j = i;
		while (j < s.size() && s[j] != ' ') {
			h += s[j++];
		}
		if (h.size() > 0) vec.push_back(h);
h = "";
i = j + 1;
	}
	return vec;
}
template<typename T>
void print_vec(vector<T>a) {
	for (int i = 0; i < a.size(); i++) {
		cout << (i == 0 ? "" : " ") << a[i];
	}
	cout << endl;
}
const ll Inf = 3023372036854775807;
const int inf = 1500000000;
#define int long long
//----------------------------------------------------
int n, l, t;
int x[200000], w[200000];
int a[200000];
int solve(int i, int j) {
	if (w[i] == 2) swap(i, j);
	ld k = (x[j] - x[i] + l) % l;
	k /= 2.;
	if (k > t) return 0;
	return (t - k)*2. / l + 1;
}
signed main() {
	cin >> n >> l >> t;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> w[i];
		if (w[i] == 1) a[i] = (x[i] + t) % l;
		else a[i] = ((x[i] - t) % l + l) % l;
	}
	int res = a[0];
	sort(a, a + n);
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (w[0] == 1 && w[i] == 2) {
			sum += solve(0, i);
		}
		if (w[0] == 2 && w[i] == 1) {
			sum += solve(0, i);
		}
	}
	sum %= n;
	if (w[0] == 1) sum = (n - (sum%n)) % n;
	int k;
	if (w[0] == 1) k = (upper_bound(a, a + n, res) - a - 1 + n + sum) % n;
	else k = (lower_bound(a, a + n, res) - a + sum) % n;
	for (int i = 0; i < n; i++) {
		cout << a[(i + k) % n] << endl;
	}
}