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

// const long long N = ;
long long n, a, b, c, d;
int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> a >> b >> c >> d;

	long long req = b - a;
	for(long long i = 0; i < n; i++) {
		long long scad_min = - c * i;
		long long scad_max = - d * i;
		long long add_min = c * (n - 1 - i);
		long long add_max = d * (n - 1 - i);
		if(scad_min + add_max >= req && req >= scad_max + add_min)  {
			dbg(i, scad_min, scad_max, add_min, add_max);
			return cout << "YES\n", 0;
		}
	}
	cout << "NO\n";

}	

	