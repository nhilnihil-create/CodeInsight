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
int n, x[N], l, q, a, b, jmp[N][33];


void pre() {
	for(int i = 1; i <= n; i++) {
		int nxt = upper_bound(x + 1, x + n + 1, x[i] + l) - x - 1;
		jmp[i][0] = nxt;
	}
	for(int j = 1; j <= 30; j++)
		for(int i = 1; i <= n; i++) {
			jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
		}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++ ) cin >> x[i];
	cin >> l >> q;
	pre();

	for(int i = 1; i <= q; i++) {
		cin >> a >> b;
		if(a > b) swap(a, b);

		int ans = 0;
		for(int i = 30; i >= 0; i--)
			if(jmp[a][i] < b)
				a = jmp[a][i], ans += (1 << i);
		cout << ans + 1 << '\n';
	}
}	

	