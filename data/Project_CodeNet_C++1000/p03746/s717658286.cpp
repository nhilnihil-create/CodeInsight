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

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007
#define P pair<ll, ll>


ll n, m;
bool used[110000];
vector<ll> g[110000], x, y, ans;

void dfs(ll a, ll b) {
	vector<ll> res;
	if(b == 0) x.push_back(a);
	else y.push_back(a);
	REP(i, g[a].size()) {
		if (!used[g[a][i]]) {
			used[g[a][i]] = true;
			dfs(g[a][i], b);
			break;
		}
	}
}

int main() {
	cin >> n >> m;
	REP(i, m) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	used[0] = true;
	dfs(0, 0);
	reverse(ALL(x));
	if (g[0].size() >= 2) {
		dfs(0, 1);
		reverse(ALL(y));
		y.pop_back();
		reverse(ALL(y));
	}
	cout << (ll)x.size() + y.size() << endl;
	REP(i, x.size()) {
		if (i != 0)cout << " ";
		cout << x[i] + 1;
	}
	REP(i, y.size()) {
		cout << " " << y[i] + 1;
	}
	cout << endl;
}
