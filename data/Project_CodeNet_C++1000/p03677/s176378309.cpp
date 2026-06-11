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
#define double long double
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < A[i].size(); j++)
			os << A[i][j] << " ";
		os << endl;
	}
	return os;
}
template < typename T, typename U >
ostream &operator<<(ostream &os, const pair< T, U > &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

typedef pair< int, int > pii;
typedef long long ll;

struct edge {
	int from, to, d, c, i;
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

template < typename A, size_t N, typename T >
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
struct initializer {
	initializer() {
		cout << fixed << setprecision(20);
	}
};
initializer _____;

int N, M, K, T, Q, H, W;
signed main() {
	cin >> N >> M;
	vector< int > A(N);
	rep(i, N) cin >> A[i];
	rep(i, N) A[i]--;
	vector< int > count(M, 0);
	rep(i, N) {
		if (i > 0)
			count[A[i]] += (A[i] - A[i - 1] + M) % M - 1;
	}
	vector< int > count2(M, 0);
	rep(i, N - 1) {
		int a = A[i], b = A[i + 1];
		if (a < b) {
			count2[a + 1]++;
			count2[b]--;
		} else {
			count2[0]++;
			count2[b]--;
			count2[a + 1]++;
		}
	}
	rep(i, M - 1) count2[i + 1] += count2[i];
	int x = 0;
	int ans = 0;
	rep(i, N - 1) {
		int a = A[i], b = A[i + 1];
		if (b < a)
			b += M;
		int y = x;
		if (y < a)
			y += M;
		int tmp = LINF;
		if (y <= b)
			tmp = b - y + 1;

		chmin(tmp, b - a);

		ans += tmp;
	}
	//cerr << ans << endl;
	int tmp = ans;
	for (; x < M; x++) {
		tmp += count[x];
		tmp -= count2[x];
		//cerr << tmp << endl;
		chmin(ans, tmp);
	}
	cout << ans << endl;
	//cerr << count << count2;
	return 0;
}