//#pragma comment(linker, "/STACK:1024000000,1024000000")
/* vim: set fdm=marker */
//{{{
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int iinf = 0x7fffffff;
const ll linf = ~(1LL<<63);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<ll, int> mli;
typedef map<ll, ll> mll;
template<typename T>
inline T gcd(T a, T b) {
	if(a < 0) return gcd(-a, b);
	if(b < 0) return gcd( a,-b);
	if(a < b) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll qpow(ll a, ll n, ll mod) {
	a %= mod;
	ll ans = 1LL;
	while(n) {
		if(n & 1) ans = (ans*a % mod);
		a = (a*a % mod);
		n >>= 1;
	}
	return ans;
}

inline ll rev(ll a, ll p) {
	return qpow(a, p - 2, p);
}

#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define rep(x, st, en) for(int x = st; x < en; x++)
#define rer(x, st, en) for(int x = st; x >= en; x--)
#define pb push_back
#define mp make_pair
#define dbgm(msg, var) cerr<<#msg<<" "<<#var<<" = "<<var<<endl; 
#define dbg(var) cerr<<#var<<" = "<<var<<endl;
#define X first
#define Y second
// build prefix sum
template<typename T>
inline void BPS(T* DST, T* SRC, int N, int s = 0) {
	DST[s] = SRC[s];
	rep(i, 1, N) DST[s + i] = DST[s + i - 1] + SRC[s + i];
}
inline int in() { int x; cin>>x; return x; }
#ifdef ALNDBG
namespace alndbg {
	clock_t s, e;
}
#endif

inline void tic() {
#ifdef ALNDBG
	alndbg::s = clock();
#endif
}

inline void toc() {
#ifdef ALNDBG
	alndbg::e = clock();
	cerr<<1000.0 * (alndbg::e - alndbg::s) / CLOCKS_PER_SEC<<" ms"<<endl;
#endif
}

//}}}

// -------------------- Spliters ------------------------
const int maxn = 10010;

ll sum(ll n) {
	return (1LL + n) * n / 2LL;
}

int main() {
	ios::sync_with_stdio(0);
	int N;
	cin>>N;
	while(N > 0) {
		ll l = 1, r = 10000000;
		ll last_ans = 0;
		while(l <= r) {
			ll mid = (l + r) / 2;
			ll s = sum(mid); 

			if(s <= N) {
				l = mid + 1;
				last_ans = max(last_ans, mid);
			} else {
				r = mid - 1;
			}
		}
		if(sum(last_ans) == N) {
			rep(i, 1, last_ans + 1) {
				cout<<i<<endl;
			}
			break;
		} else {
			if(last_ans <= N) {
				N -= last_ans + 1;
				cout<<last_ans + 1<<endl;
			} else {
				N -= last_ans;
				cout<<last_ans<<endl;
			}
		}
	}
	return 0;
}
// --USE C++11
// *-USE O2
