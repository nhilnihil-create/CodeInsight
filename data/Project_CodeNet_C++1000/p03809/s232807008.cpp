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
vector<int> G[100000];
int n; ll a[100000];
bool used[100000];
int sta;
pair<bool,ll> dfs(int x) {
	used[x] = true;
	int len = G[x].size();
	if (x!=sta&&len == 1) {
		return { true,a[x] };
	}
	ll sum = 0; ll ma = 0;
	rep(i, len) {
		int v = G[x][i];
		if (used[v])continue;
		pair<bool, ll> p = dfs(v);
		if (!p.first)return { false,0 };
		ma = max(ma, p.second); sum += p.second;
	}
	if (sum < a[x])return { false,0 };
	ll d = sum - a[x];
	ll chk = min(sum / 2, sum - ma);
	if (d > chk)return { false,0 };
	else return { true,a[x] - d };
}
int main() {
	cin >> n; fill(used, used + n, false);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n-1) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep(i, n) {
		if (G[i].size() == 1)sta = i;
	}
	if (dfs(sta).first)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}