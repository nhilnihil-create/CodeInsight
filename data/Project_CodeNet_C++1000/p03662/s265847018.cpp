#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007


ll n, root[114514], d[114514], ans[2], sc;
vector<vector<ll>> s(114514);

void rs(ll a, ll b) {
	d[a] = b;
	REP(i, s[a].size()) {
		if (s[a][i] != root[a]) {
			root[s[a][i]] = a;
			rs(s[a][i], b + 1);
		}
	}
}

void ns(ll a) {
	if (d[a] == d[n] / 2 + 1) {
		REP(i, s[root[a]].size()) {
			if (s[root[a]][i] == a)s[root[a]][i] = root[root[a]];
		}
		sc = a;
	}
	else ns(root[a]);
}

void dfs(ll a, ll b) {
	REP(i, s[a].size()) {
		if (s[a][i] != root[a]) {
			ans[b]++;
			dfs(s[a][i], b);
		}
	}
}

int main() {
	cin >> n;
	REP(i, n - 1) {
		ll a, b;
		cin >> a >> b;
		s[a].push_back(b);
		s[b].push_back(a);
	}
	root[1] = 1;
	rs(1, 0);
	ns(n);
	dfs(1, 0);
	dfs(sc, 1);
	cout << (ans[0] > ans[1] ? "Fennec" : "Snuke") << endl;

}


