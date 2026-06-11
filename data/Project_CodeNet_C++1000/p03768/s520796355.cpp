#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

P color[110000];
vi e[110000];

void dfs(int v,int d,int c) {
	if (color[v].second >= d)return;
	if (color[v].first == 0)color[v].first = c;
	color[v].second = d;
	if(d>0)for (int vv : e[v])dfs(vv, d - 1, c);
}

int main() {

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	int q;
	cin >> q;
	vi v, d, c;
	rep(i, q) {
		int vv, dd, cc;
		cin >> vv >> dd >> cc;
		vv--;
		v.push_back(vv);
		d.push_back(dd);
		c.push_back(cc);
	}
	reverse(all(v));
	reverse(all(d));
	reverse(all(c));
	rep(i, n)color[i].second = -1;
	rep(i, q)dfs(v[i], d[i], c[i]);
	rep(i, n)cout << color[i].first << endl;

}