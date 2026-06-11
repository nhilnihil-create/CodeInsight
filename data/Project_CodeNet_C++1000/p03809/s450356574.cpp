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
int n, y, b, a[N];
vector <int> v[N];

int dfs(int node, int ant = -1) {
	int sum = 0, mx = 0;
	if(v[node].size() == 1 && ant != -1)
		return a[node];	

	for(auto i : v[node]) {
		if(i == ant) continue;
		int k = dfs(i, node);
		sum += k;
		mx = max(k, mx);
	}

	int nr = sum - a[node];
	// dbg(node, sum, nr, a[node]);
	if(nr < 0 || nr > sum - mx) throw 4;

	// sum -= 2 * nr;
	if(a[node] < nr) throw 4;
	
	if(v[node].size() == 1) 
		return a[node] - sum;

	return a[node] - nr;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i < n; i++) {
		cin >> y >> b;
		v[b].push_back(y);
		v[y].push_back(b);
	}

	try {
		int x = dfs(1);
		if(x == 0)
			cout << "YES\n";
		else cout << "NO\n";
	} catch(int x) {
		dbg(x);
		cout << "NO\n";
	}
}	

	