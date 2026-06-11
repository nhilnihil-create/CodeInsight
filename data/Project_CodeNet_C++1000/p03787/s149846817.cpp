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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;
long long n, m, use[N], a, b;
vector <long long> v[N];

long long dfs(long long node, long long col) {
	use[node] = col;
	long long ret = 1;
	for(auto i : v[node]) {
		if(!use[i])
			ret &= dfs(i, 3 - col);
		else if(use[i] == col)
			ret = 0;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(long long i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	long long nr = 0, bip= 0, fre = 0;
	for(long long i = 1; i <= n; i++) {
		if(!use[i]) {
			bip += dfs(i, 1), nr++;
			if(v[i].size()== 0) bip--, fre++;
		}
	}
	nr -= fre + bip;
	dbg(nr, bip, fre);
	// cout << 2 * (n - fre) * fre + 2 * fre * fre - fre + 4 * bip * bip - 2 * bip + 2 * bip * nr + 2 * nr * nr - nr << '\n';
	// cout << fre * fre + 2 * fre *(n - fre) << '\n';
	cout << fre * (2 * n - fre) + 2 * bip * bip + 2 * bip * nr + nr * nr << '\n';
}	

	