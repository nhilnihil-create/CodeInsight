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
const ll MOD = (1e+9) + 7;
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
vector<int> G[100000]; int k; int out = 0; int d[100000];
int dfs(int x) {
	int len = G[x].size();
	if (len == 0)return 1;
	int res = 0;
	rep(i, len) {
		int v = G[x][i];
		res = max(res, dfs(v));
	}
	if (res >= k-1 && d[x] > 1) {
		out++; return 0;
	}
	else return res + 1;
}
int main() {
	int n; cin >> n >> k;
	int a[100000];
	d[0] = 0;
	cin >> a[0]; 
	Rep(i,1, n) {
		cin >> a[i]; a[i]--;
		G[a[i]].push_back(i);
	}
	if (a[0] != 1)out++;
	if (k == 1) {
		Rep(i,1, n) {
			if (a[i] != 0)out++;
		}
		cout << out << endl;
	}
	else {
		queue<int> q; q.push(0);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			int len = G[x].size();
			rep(j, len) {
				int v = G[x][j];
				d[v] = d[x] + 1;
				q.push(v);
			}
		}
		dfs(0);
		cout << out << endl;
	}
	return 0;
}
