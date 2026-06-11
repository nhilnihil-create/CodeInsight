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
vector<int> C[100000];
int n; bool used[100000];
int dfs(int k) {
	int res = 0;
	int len = G[k].size();
	rep(i, len) {
		int v = G[k][i];
		res ^= dfs(v)+1;
	}
	return res;
}
int main() {
	cin >> n;
	rep(i, n - 1) {
		int x, y; cin >> x >> y; x--; y--;
		C[x].push_back(y);
		C[y].push_back(x);
	}
	fill(used, used + n, false);
	queue<int> q; q.push(0); used[0] = true;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int len = C[x].size();
		rep(i, len) {
			int v = C[x][i];
			if (used[v])continue;
			used[v] = true; q.push(v); G[x].push_back(v);
		}
	}
	if (dfs(0))cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}