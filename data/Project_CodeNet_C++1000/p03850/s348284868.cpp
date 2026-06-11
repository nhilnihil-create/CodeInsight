#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cerr << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int maxn = 100010;
const ll inf = -TEN(18);

ll dp[maxn][3];

int main() {
	rep(i, maxn) rep(j, 3) {
		dp[i][j] = inf;
	}

	dp[0][0] = 0;

	int N; cin >> N;
	rep(i, N) {
		bool neg = 0;
		if (i > 0) {
			string s; cin >> s;
			if (s == "-") {
				neg = 1;
			}
		}
		int x; cin >> x;

		ll tmp[3];
		rep(j, 3) tmp[j] = dp[i][j];

		for (int j = 1; j >= 0; --j) { //close
			chmax(tmp[j], tmp[j+1]);
		}

		rep(j, 3) if (tmp[j] != inf) {
			tmp[j] += ((j + neg) % 2 == 1) ? -x : x;
		}

		if (neg) {
			for (int j = 1; j >= 0; --j) { //open
				chmax(tmp[j+1], tmp[j]);
			}
		}

		rep(j, 3) dp[i+1][j] = tmp[j];
	}

	cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;

	return 0;
}