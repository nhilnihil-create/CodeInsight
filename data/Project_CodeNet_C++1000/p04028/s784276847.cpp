#include "bits/stdc++.h"
#include <sys/timeb.h>
#include <fstream>

using namespace std;

#define repr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repr(i,0,n)
#define reprrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) reprrev(i,0,n)
#define repi(itr,ds) for(auto itr=ds.begin();itr!=ds.end();itr++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mp make_pair
#define mt make_tuple
#define INF 1050000000
#define INFL 1100000000000000000LL
#define EPS (1e-10)
#define MOD 1000000007
#define PI 3.1415926536
#define RMAX 4294967295

typedef long long ll;
typedef pair<int, int> Pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<Pi> vPi;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<double> > vvd;
typedef vector<vector<Pi> > vvPi;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<Pi, vector<Pi>, greater<Pi> > pqlP;
struct Edge {
	int from, to, cost;
	bool operator<(Edge e) {
		return cost < e.cost;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
template <class T>
using vec = vector<T>;
template<class T>
using pql = priority_queue<T, vector<T>, greater<T>>;

string debug_show(Pi a) {
	return "(" + to_string(a.first) + "," + to_string(a.second) + ")";
}

template<class T>
struct augEdge {
	T from, to;
	int cost;
	bool operator<(Edge e) {
		return cost < e.cost;
	}
	bool operator>(Edge e) {
		return cost > e.cost;
	}
};

ll powMod(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	string s;
	cin >> N >> s;
	int L = s.size();

	vvll dp(N + 1, vll(N + 2, 0));	// dp[i][j]=キーi回押下、現在j文字表示
	dp[0][0] = 1;

	repr(i, 1, N + 1)rep(j, N + 1) {
		if (j == 0) dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		else dp[i][j] = (dp[i - 1][j - 1] * 2 + dp[i - 1][j + 1]) % MOD;
	}
	ll inv = powMod(2, MOD - 2, MOD);
	ll ans = dp[N][L];

	rep(i, L) {
		ans *= inv;
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}