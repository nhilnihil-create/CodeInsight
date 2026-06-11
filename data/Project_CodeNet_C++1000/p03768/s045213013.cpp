#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mid ((x + y) / 2)
#define left (ind * 2)
#define right (ind * 2 + 1)
#define mp make_pair
#define timer ((double)clock() / CLOCKS_PER_SEC)
#define endl "\n"
#define spc " "
#define d1(x) cerr<<#x<<":"<<x<<endl
#define d2(x, y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl
#define d3(x, y, z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;

const int N = (int)(1e6 + 5);
const int LOG = (int)(20);

int n, m, q, cl[N], mark[N][15];
vector<int> v[N];
stack<iii> s;

void dfs(int x, int d, int c) {
	if(mark[x][d])
		return;
	mark[x][d] = 1;
	if(d == 0) {
		cl[x] = c;
		return;
	}
	dfs(x, d - 1, c);
	for(auto i : v[x])
		if(mark[i][d - 1] == 0)
			dfs(i, d - 1, c);
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}

	cin >> q;
	for(int i = 1; i <= q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		s.push({{a, b}, c});
	}

	while(!s.empty()) {
		iii t = s.top();
		s.pop();
		dfs(t.fi.fi, t.fi.se, t.se);
	}
	for(int i = 1; i <= n; i++)
		cout << cl[i] << endl;
}