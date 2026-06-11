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

const long long N = 200100;
long long n, a[N], dif[N], c[N], m, ans;

long long add(long long l, long long r) {
	dif[l]++;
	dif[r + 1]--;
	c[r + 1] -= (r - l + 1);
}

long long add_c(long long l, long long r, long long val) {
	// dbg(l, r, val);
	c[l] += val;
	c[r + 1] -= val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];
	
	for(long long i = 2; i <= n; i++) {
		if(a[i] > a[i - 1]) {
			ans += a[i] - a[i - 1];
			add(a[i - 1] + 2, a[i]);
		}
		else {
			ans += m + a[i] - a[i - 1];
			add(a[i - 1] + 2, m);
			add(1, a[i]);
			add_c(1, a[i], m - a[i - 1] - 1);
		}
	}
	// dbg_v(dif, m + 1);
	long long tot = ans;
	long long cc=  0, diff = 0;
	dbg(ans);
	for(long long i = 1; i <= m; i++){
		dif[i] += dif[i - 1];
		diff += dif[i];
		cc += c[i];
		ans = min(ans, tot - diff - cc);
	}

	// dbg_v(dif, m + 1);
	// dbg_v(c, m + 1);
	// dbg(ans);
	cout << ans << '\n';
}	

	