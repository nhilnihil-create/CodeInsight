#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
using namespace std;
int p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<pin,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define sq(a) (a)*(a)
#define rev(s) reverse(s.begin(),s.end())
#define end_pr(s) cout << s <<endl;return 0
#define itn int
#define bs bitset<5001>

int kai_size = 1000001;
vel kai(kai_size, 1);
vel ink(kai_size, 1);
vel dist;
int sz(pin x) { return x.first*x.second; }
void make(int c, int pot, int d, vel &col, vel &max_use,vvel &way) {
	if (max_use[pot] < d) {
		if (col[pot] == 0) { col[pot] = c; }
		max_use[pot] = d;
		for (auto x : way[pot]) {
			make(c, x, d - 1, col, max_use, way);
		}
	}
}
signed main() {
	int n, m; cin >> n >> m;
	vvel way(n);
	rep(i, m) {
		int a, b; cin >> a >> b;
		a--;; b--;
		way[a].push_back(b);
		way[b].push_back(a);
	}
	int q; cin >> q;
	vel v(q), d(q), c(q);
	rep(i, q) {
		cin >> v[i] >> d[i] >> c[i]; v[i]--;
	}
	rev(v), rev(d), rev(c);
	vel col(n, 0);
	vel max_use(n, -1);
	rep(i, q) {
		make(c[i], v[i], d[i], col, max_use,way);
	}
	rep(i, n) {
		cout << col[i] << Endl;
	}
	return 0;
}
/*
13:40~

*/