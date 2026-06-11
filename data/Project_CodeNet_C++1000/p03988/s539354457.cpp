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

int pow2(int n) { return 1 << n; }
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

int N, M, K, T, Q;
bool solve(vector< int > &A) {
	sort(A.begin(), A.end());
	int maxa = A[N - 1], mina = (maxa + 1) / 2;
	map< int, int > m;
	rep(i, N) m[A[i]]++;
	if (m[maxa] < 2)
		return false;
	if (A[0] < mina)
		return false;
	if (maxa & 1) {
		if (m[mina] != 2)
			return false;
	} else {
		if (m[mina] != 1) {
			return false;
		}
	}
	for (int k = mina + 1; k < maxa; k++) {
		if (m[k] < 2)
			return false;
	}
	return true;
}
signed main() {
	cin >> N;
	vector< int > A(N);
	rep(i, N) cin >> A[i];
	string ans = solve(A) ? "Possible" : "Impossible";
	cout << ans << endl;
	return 0;
}