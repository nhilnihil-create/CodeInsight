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
#define EPS 1e-9
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

int pow2(int n) { return 1LL << n; }
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
		cout << fixed << setprecision(20);
	}
};
initializer _____;
struct range {
	int l, r, c, i;
	range(int l = 0, int r = 0, int c = 0, int i = 0) : l(l), r(r), c(c), i(i) {}
	bool operator<(const range &rhs) const {
		return l < rhs.l;
	}
};
auto compare = [](const range &r1, const range &r2) {
	return r1.r > r2.r;
};
int N, M, K, T, Q, H, W;
signed main() {
	cin >> N;
	vector< int > x(N);
	rep(i, N) cin >> x[i];
	rep(i, N)-- x[i];
	vector< int > a(N * N, -1);
	vector< range > R;
	rep(i, N) {
		a[x[i]] = i + 1;
		if (i > 0)
			R.push_back(range(0, x[i], i, i + 1));
		if (i < N - 1)
			R.push_back(range(x[i] + 1, N * N, N - i - 1, i + 1));
	}
	sort(R.begin(), R.end());
	priority_queue< range, vector< range >, decltype(compare) > q{compare};
	int j = 0;
	rep(i, N * N) {
		if (a[i] != -1)
			continue;
		while (j < R.size() && R[j].l <= i) {
			q.push(R[j++]);
		}
		if (q.empty() || (q.top()).r <= i) {
			cout << "No" << endl;
			return 0;
		}
		a[i] = (q.top()).i;
		//cout << a;
		range r = q.top();
		q.pop();
		r.c--;
		if (r.c > 0)
			q.push(r);
	}
	cout << "Yes" << endl;
	rep(i, N * N) cout << a[i] << " ";
	cout << endl;
	return 0;
}