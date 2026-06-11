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
const ll MOD = 924844033;
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
int main() {
	int n; cin >> n;
	vector<int> G[100000];
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int d[100000];
	fill(d, d + n, -1);
	queue<int> q; q.push(0); d[0] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int len=G[x].size();
		rep(j, len) {
			int v = G[x][j];
			if (d[v] == -1) {
				d[v] = d[x] + 1;
				q.push(v);
			}
		}
	}
	int c[100000];
	fill(c, c + n, -1);
	q.push(n - 1); c[n - 1] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int len = G[x].size();
		rep(j, len) {
			int v = G[x][j];
			if (c[v] == -1) {
				c[v] = c[x] + 1; q.push(v);
			}
		}
	}
	int dis = d[n - 1];
	int ddis = dis / 2;
	int chk;
	rep(i, n) {
		if (d[i] == ddis && d[i] + c[i] == dis) {
			chk = i;
		}
	}
	q.push(n - 1);
	int cnt = 0;
	int used[100000] = {};
	used[n - 1] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int len = G[x].size();
		rep(j, len) {
			int v = G[x][j];
			if (used[v])continue;
			if (v == chk)continue;
			q.push(v); used[v] = 1; cnt++;
		}
	}
	int s = (n - 1) / 2;
	if (cnt >= s) {
		cout << "Snuke" << endl;
	}
	else {
		cout << "Fennec" << endl;
	}
	return 0;
}