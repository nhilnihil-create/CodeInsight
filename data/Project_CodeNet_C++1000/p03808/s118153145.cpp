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
long long n, a[N], s;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	for(long long i = 1; i<= n; i++)
		cin >> a[i], s += a[i];
	
	long long p = n * (n + 1) / 2;

	if(s % p != 0) return cout << "NO\n", 0;

	long long cnt = s / p, nr = 0;
	a[n + 1] = a[1];

	for(long long i = 1; i <= n; i++) {
		long long dif = a[i + 1] - a[i];
		long long x = cnt - dif;

		if(x < 0 || x % n != 0) return cout << "NO\n", 0;
		x /= n;
		nr += x;
	}

	if(nr == cnt)
		cout << "YES\n";
	else cout << "NO\n";
}	

	