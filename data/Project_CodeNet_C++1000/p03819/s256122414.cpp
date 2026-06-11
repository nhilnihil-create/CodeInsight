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

const long long N = 300100;
long long n, to_add[N], aib[N], m, l, r, ans[N];
vector <long long> to_erase[N], v[N];

long long lsb(long long k) { return k & (-k); }

void upd(long long pos, long long val) {
	for(; pos < N; pos += lsb(pos))
		aib[pos] += val;
}

long long que(long long pos) {
	long long ret = 0;
	for(; pos; pos -= lsb(pos))
		ret += aib[pos];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(long long i = 1; i<= n; i++) {
		cin >> l >> r;
		to_erase[r + 1].push_back(l);
		to_add[l]++;
	}

	for(long long i = 1; i <= m; i++)
		for(long long j = i; j <= m; j += i)
			v[j].push_back(i);

	for(long long i = 1; i <= m; i++) {
		upd(i, to_add[i]);
		for(auto j : to_erase[i])
			upd(j, -1);

		for(auto j : v[i]) {
			//[i - j + 1, i]
			ans[j] += que(i) - que(i - j);
		}
	}
	for(long long i = 1; i <= m; i++) cout << ans[i] << '\n';
}	

	 