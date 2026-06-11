#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
vector<int> compose(const vector<int>& a, const vector<int>& b) {
	int n = a.size();
	vector<int> c(n);
	for (int i = 0; i < n; ++i) c[i] = a[b[i]];
	return c;
}
vector<int> power(vector<int> a, ll b) {
	int n = a.size();
	vector<int> x(n);
	iota(x.begin(), x.end(), 0);
	while (b) {
		if (b & 1) x = compose(x, a);
		a = compose(a, a);
		b >>= 1;
	}
	return x;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> perm(n);
	vector<ll> X(n);
	iota(perm.begin(), perm.end(), 0);
	for (int i = 0; i < n; ++i) scanf("%lld", &X[i]);
	int m;
	ll k;
	scanf("%d%lld", &m, &k);
	vector<int> A(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &A[i]);
		--A[i]; // swap A[i], A[i]+1.
		swap(perm[A[i]], perm[A[i] + 1]);
	}
	perm = power(perm, k);
	ll ans = X[0];
	printf("%lld\n", ans);
	for (int i = 1; i < n; ++i) {
		ans += X[perm[i]] - X[perm[i] - 1];
		printf("%lld\n", ans);
	}
}
