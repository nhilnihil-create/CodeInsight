#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
vector<int> G[100000]; bool used[100000];
int col[100000][2] = {};
int main() {
	int n, m; cin >> n >> m;
	rep(i, m) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int cnt = n; int c1 = 0; int c2 = 0;
	fill(used, used + n, false);
	rep(i, n) {
		if (used[i])continue;
		if (G[i].empty())cnt--;
		else {
			col[i][0] = 1;
			queue<P> q; q.push({ i,0 });
			while (!q.empty()) {
				P nex = q.front(); q.pop();
				used[nex.first] = true;
				int len = G[nex.first].size();
				rep(j, len) {
					int v = G[nex.first][j];
					if (col[v][1 - nex.second])continue;
					col[v][1 - nex.second] = 1;
					q.push({ v,1 - nex.second });
				}
			}
			if (col[i][1])c1++;
			else c2++;
		}
	}
	ll out = (ll)n*n - (ll)cnt*cnt;
	out += (ll)c1*c1 + (ll)2*c2*c2 + (ll)2 * c1*c2;
	cout << out << endl;
	return 0;
}