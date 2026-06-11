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
	int from, to, c;
	ll d;
	edge(int _from = 0, int _to = 0, ll _d = 0, int _c = 0) {
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
void dfs(vector< vector< int > > &G, vector< bool > &done, int v) {
	done[v] = true;
	rep(i, G[v].size()) {
		int next = G[v][i];
		if (done[next])
			continue;
		dfs(G, done, next);
	}
}
int main() {
	cin >> N >> M;
	edges es(M);
	rep(i, M) {
		cin >> es[i].from >> es[i].to >> es[i].d;
		es[i].from--;
		es[i].to--;
	}
	vector< vector< int > > G1(N), G2(N);
	rep(i, M) {
		edge e = es[i];
		G1[e.from].push_back(e.to);
		G2[e.to].push_back(e.from);
	}
	vector< bool > done1(N, false), done2(N, false), done(N, false);
	dfs(G1, done1, 0);
	dfs(G2, done2, N - 1);
	rep(i, N) done[i] = done1[i] & done2[i];
	vector< ll > d(N, -LINF);
	d[0] = 0;
	bool f = true;
	rep(k, N) {
		rep(i, M) {
			edge e = es[i];
			if (d[e.from] != -LINF && done[e.to] && d[e.from] + e.d > d[e.to]) {
				if (k == N - 1) {
					f = false;
					break;
				}
				d[e.to] = d[e.from] + e.d;
			}
		}
	}
	//cout << d;
	if (!f)
		cout << "inf" << endl;
	else
		cout << d[N - 1] << endl;
	return 0;
}