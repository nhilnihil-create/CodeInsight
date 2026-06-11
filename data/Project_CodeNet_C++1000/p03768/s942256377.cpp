#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, use[N], uz[N][12], a, b, c[N], d[N], m, q, x[N];
vector <int> v[N];

void dfs(int node, int d, int col) {
	// dbg(node, d);
	if(!use[node]) use[node] = col;
	uz[node][d] = 1;
	if(d == 0) return;

	for(auto i : v[node])
		if(uz[i][d - 1] == 0)
			dfs(i, d - 1, col);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cin >> q;
	for(int i = 1; i <= q ;i++) 
		cin >> x[i] >> d[i] >> c[i];

	for(int i = 1; i <= q ;i++) 
		dfs(x[q - i + 1], d[q - i + 1], c[q - i + 1]);
	
	for(int i = 1; i <= n; i++) 
		cout << use[i] << '\n';
}	

	