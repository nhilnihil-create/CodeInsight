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
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef complex<ld> Point;
const ll mod = 1000000007;
const ld INF = 1e+30;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)

bool used[1 << 17];
vector<int> G[1 << 17];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int l = 0, r = G[0][0]; used[0] = used[r] = true;
	vector<int> le({ 0 }), ri({ r });
	while (true) {
		bool f = true;
		rep(j, G[l].size()) {
			int to = G[l][j];
			if (used[to])continue;
			else {
				f = false;
				le.push_back(to);
				used[to] = true;
				l = to;
				break;
			}
		}
		if (f)break;
	}
	while (true) {
		bool f = true;
		rep(j, G[r].size()){
			int to = G[r][j];
			if (used[to])continue;
			else {
				f = false;
				ri.push_back(to);
				used[to] = true;
				r = to;
				break;
			}
		}
		if (f)break;
	}
	reverse(le.begin(), le.end());
	rep(i, ri.size())le.push_back(ri[i]);
	cout << le.size() << endl;
	rep(i, le.size()) {
		if (i > 0)cout << " ";
		cout << le[i]+1;
	}
	cout << endl;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}