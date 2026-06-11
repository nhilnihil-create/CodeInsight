#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define MOD 1000000007
#define MOD2 998244353
#define int long long
//#define PI 3.14159265358979

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

template < typename T >
ostream &operator<<(ostream &os, const vector< T > &A) {
	for (int i = 0; i < A.size(); i++)
		os << A[i] << " ";
	os << endl;
	return os;
}
template <>
ostream &operator<<(ostream &os, const vector< vector< int > > &A) {
	int N = A.size();
	int M;
	if (N > 0)
		M = A[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			os << A[i][j] << " ";
		os << endl;
	}
	return os;
}

typedef pair< int, int > pii;
typedef long long ll;

struct edge {
	int from, to, d, c;
	edge(int _from = 0, int _to = 0, int _d = 0, int _c = 0) {
		from = _from;
		to = _to;
		d = _d;
		c = _c;
	}
	bool operator<(const edge &rhs) const {
		return (d == rhs.d) ? (c < rhs.c) : (d < rhs.d);
	}
};
struct aabb {
	int x1, y1, x2, y2;
	aabb(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

typedef vector< edge > edges;
typedef vector< edges > graph;
struct flow {
	int to, cap, rev, cost;
	flow(int to = 0, int cap = 0, int rev = 0, int cost = 0) : to(to), cap(cap), rev(rev), cost(cost) {}
};
typedef vector< vector< flow > > flows;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {-1, 0, 1, 0};
const int ci[5] = {0, 0, -1, 0, 1};
const int cj[5] = {0, -1, 0, 1, 0};
const ll LINF = LLONG_MAX / 2;
const int INF = INT_MAX / 2;
const double PI = acos(-1);

template < typename T, typename U >
bool chmin(T &x, const U &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}
template < typename T, typename U >
bool chmax(T &x, const U &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

struct initializer {
	initializer() {
		cout << fixed << setprecision(11);
	}
};
initializer _____;
struct range {
	int l, r, c;
	range(int l = 0, int r = 0, int c = 0) : l(l), r(r), c(c) {}
	bool operator<(const range &rhs) const {
		return l < rhs.l;
	}
};
int N, M, K, T, Q;
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll extgcd(ll a, ll b, ll &x, ll &y) {
	int d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1;
		y = 0;
	}
	return d;
}
ll factorial(ll x) {
	if (x == 1)
		return 1;
	else
		return x * factorial(x - 1);
}
ll Mfactorial(ll x, ll m) {
	ll ret = 1;
	for (ll i = 1; i <= x; i++) {
		ret *= i;
		ret %= m;
	}
	return ret;
}
vector< int > MfactTable(int n, int m) {
	vector< int > ret(n + 1);
	ret[0] = 1;
	int tmp = 1;
	for (int i = 1; i <= n; i++) {
		tmp *= i;
		tmp %= m;
		ret[i] = tmp;
	}
	return ret;
}
int Minverse(int a, int m) {
	int x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
int McombSmall(int n, int k, int m) {
	//O(n)
	int ret = Mfactorial(n, m);
	ret *= Minverse(Mfactorial(k, m), m);
	ret %= m;
	ret *= Minverse(Mfactorial(n - k, m), m);
	return ret % m;
}
int McombFromFactTable(vector< int > &T, int n, int k, int m) {
	if (k > n)
		return 0;
	int ret = T[n];
	ret *= Minverse(T[k], m);
	ret %= m;
	ret *= Minverse(T[n - k], m);
	return ret % m;
}
ll pow(ll x, int n) {
	if (n == 0)
		return 1;
	ll ret = (n & 1) ? x : 1;
	ll a = pow(x, n / 2);
	return ret * a * a;
}
ll Mpow(ll x, int n, int m) {
	if (n == 0)
		return 1;
	ll ret = (n & 1) ? x : 1;
	ll a = Mpow(x, n / 2, m);
	return (((ret * a) % m) * a) % m;
}
vector< vector< int > > combTable(int N) {
	vector< vector< int > > ret(N + 1, vector< int >(N + 1));
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				ret[i][j] = 1;
			else
				ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
		}
	return ret;
}
int countNmodPisQlr(int l, int r, int P, int Q) {
	//r>=l>=0
	return (r - Q + P) / P - (l - Q + P - 1) / P;
}
struct UFT {
	vector< int > par;
	int getpar(int i) {
		if (par[i] == i)
			return i;
		return par[i] = getpar(par[i]);
	}
	void unite(int i, int j) {
		int t = getpar(i);
		par[t] = getpar(j);
	}
	bool uf(int i, int j) {
		return getpar(i) == getpar(j);
	}
	UFT(int n) {
		par = vector< int >(n);
		for (int i = 0; i < n; i++)
			par[i] = i;
	}
};
struct SegT {
	vector< ll > container;
	int n;
	void update(int i, ll x) {
		int ii = i + n - 1;
		container[ii] = x;
		while (ii > 0) {
			ii = (ii - 1) / 2;
			//////////////////  update to better one  ////////////////////////
			container[ii] = max(container[2 * ii + 1], container[2 * ii + 2]);
		}
	}
	ll get(int l, int r, int l2 = 0, int r2 = -1, int k = 0) {
		if (r2 == -1)
			r2 = n;
		/////////////////  return worst  //////////////////
		if (r2 <= l || r <= l2)
			return 0;

		if (l <= l2 && r2 <= r)
			return container[k];
		ll vl = get(l, r, l2, (l2 + r2) / 2, 2 * k + 1);
		ll vr = get(l, r, (l2 + r2) / 2, r2, 2 * k + 2);
		/////////////  return better one  //////////////
		return max(vl, vr);
	}
	SegT(vector< int > &A) {
		n = pow(2, (int)log2(A.size()) + 1);
		container = vector< ll >(2 * n - 1, 0);
		for (int i = 0; i < A.size(); i++)
			update(i, A[i]);
	}
};
signed main() {
	cin >> N;
	int ans = 0;
	vector< int > A(N + 2, 0);
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	vector< int > B(N + 1);
	for (int i = 1; i <= N; i++)
		B[A[i]] = i;
	set< int > s1, s2;
	s1.insert(N + 1);
	s2.insert(0);
	for (int k = 1; k <= N; k++) {
		int i = B[k];
		s1.insert(i);
		s2.insert(-i);
		int r = *(s1.upper_bound(i)) - 1;
		int l = -*(s2.upper_bound(-i)) + 1;
		//cout << l << " " << r << endl;
		ans += k * (i - l + 1) * (r - i + 1);
	}
	cout << ans << endl;
	return 0;
}