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
long long n, a, b, v[55], nr1, nr2, sum;

long long choose(long long n, long long k) {
  long long r = 1;
  long long d;
  if (k > n) return 0;
  for (d=1; d <= k; d++) {
    r *= n--;
    r /= d;
  }
  return r;
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> a >> b;
	for(long long i = 1; i <= n; i++) 
		cin >> v[i];
	sort(v + 1, v + n + 1, greater <long long> ());

	for(long long i = 1; i <= a; i++) {
		sum += v[i];
		nr1 += (v[i] == v[a]);
	}


	for(long long i = a + 1; i <= n ;i++)
		nr2 += (v[i] == v[a]);
	
	if(v[1] == v[a]) {
		long long nrc = 0;
		for(int c = a; c <= b; c++)
			nrc += choose(nr1 + nr2, c);			

		cout << fixed << setprecision(9) << 1. * sum / a << '\n' << nrc << '\n';
		return 0;
	}
	cout << fixed << setprecision(9) << 1. * sum / a << '\n' << choose(nr1 + nr2, nr1) << '\n';

}	

	