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
#include <string>
#include <unordered_map>
#include <vector>

#define MOD 1000000007
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

int N, M, K, T, Q;
signed main() {
	cin >> N;
	int x;
	cin >> x;
	if (x == 1 || x == 2 * N - 1) {
		cout << "No" << endl;
		return 0;
	}
	if (N == 2) {

		cout << "Yes" << endl;
		cout << 1 << endl
			 << 2 << endl
			 << 3 << endl;
		return 0;
	}
	vector< bool > used(2 * N, false);
	used[x] = true;
	vector< int > M(4);
	M[1] = x;
	if (x == 2) {
		M[2] = 1;
		M[0] = 3;
		M[3] = 4;
		used[1] = used[3] = used[4] = true;
	} else {
		M[2] = x + 1;
		M[0] = 1;
		M[3] = 2;
		used[x + 1] = used[1] = used[2] = true;
	}
	cout << "Yes" << endl;
	int k = 1;
	rep(i, N - 2) {
		while (used[k])
			k++;
		cout << k++ << endl;
	}
	rep(i, 4) {
		cout << M[i] << endl;
	}
	rep(i, N - 3) {
		while (used[k])
			k++;
		cout << k++ << endl;
	}
	return 0;
}