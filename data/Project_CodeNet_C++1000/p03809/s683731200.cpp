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
typedef pair<lli, lli> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;

const int N = (int)(1e6 + 5);
const int LOG = (int)(20);

lli n, ar[N], pe[N], root, tot, par[N];
vector<lli> v[N];
vector<ii> v2[N];

void dfs(lli x, lli back) {
	par[x] = back;
	lli tot = 0;
	for(auto i : v[x])
		if(i != back) {
			dfs(i, x);
			tot += pe[i];
		}
	if(v[x].size() == 1)
		pe[x] = ar[x];
	else
		pe[x] = ar[x] * 2 - tot;
} 

signed main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n;
	for(lli i = 1; i <= n; i++)
		cin >> ar[i];
	for(lli i = 1; i <= n - 1; i++) {
		lli a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}

	if(n == 2) {
		if(ar[1] == ar[2])
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}
	root = 0;
	while(v[++root].size() == 1);
	
	dfs(root, 0);

	if(pe[root] != 0) {
		cout << "NO";
		return 0;
	}

	for(int i = 1; i <= n; i++)
		if(pe[i] < 0) {
			cout << "NO";
			return 0;
		}
	for(int i = 1; i <= n; i++) {
		if(i == root)
			continue;
		v2[i].pb({par[i], pe[i]});
		v2[par[i]].pb({i, pe[i]});
	}

	bool fl = false;

	for(int i = 1; i <= n; i++) {
		if(v[i].size() == 1)
			continue;
		lli t = 0;
		for(auto j : v2[i])
			t += j.se;
		if(t % 2 == 1) {
			cout << "NO";
			return 0;
		}
		for(auto j : v2[i])
			if(j.se * 2 > t)
				fl = true;

	}
	if(fl) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
}