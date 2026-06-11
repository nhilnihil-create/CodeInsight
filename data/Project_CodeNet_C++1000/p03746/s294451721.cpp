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

int n, m, mark[N];
vector<int> ed[N], v, v2;

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		ed[a].pb(b);
		ed[b].pb(a);
	}

	int ep1 = 1, ep2 = ed[1][0];
	mark[ep1] = 1;
	mark[ep2] = 1;
	
	bool fl = true;
	while(fl) {
		mark[ep1] = 1;
		v.pb(ep1);
		fl = false;
		for(auto i : ed[ep1]) {
			if(!mark[i]) {
				fl = true;
				ep1 = i;
				break;
			}
		}
	}

	fl = true;
	while(fl) {
		mark[ep2] = 1;
		v2.pb(ep2);
		fl = false;
		for(auto i : ed[ep2]) {
			if(!mark[i]) {
				fl = true;
				ep2 = i;
				break;
			}
		}
	}

	cout << v.size() + v2.size() << endl;
	for(int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << spc;
	for(auto i : v2)
		cout << i << spc;
}