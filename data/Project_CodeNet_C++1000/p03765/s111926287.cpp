#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define ph push
#define f first
#define s second
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define btinpct(x) __builtin_popcountll((x))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?b:gcd(b%a,a); }

#define ll long long int 
#define ld long double
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
typedef pair <ll, ll> pi; typedef pair <ll, pi> spi; typedef pair <pi, pi> dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (100006)
ll pA[MAXN], pB[MAXN];
void in(ll &x) {
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
}
int main()
{
	FAST
	char ch; ch=getchar();
	ll co = 1;
	while(ch=='A'||ch=='B') {
		pA[co] = pA[co-1] + (ch == 'A' ? 1 : 2);
		++ co;
		ch=getchar();
	}
	ch=getchar();
	co = 1;
	while(ch=='A'||ch=='B') {
		pB[co] = pB[co-1] + (ch == 'A' ? 1 : 2);
		++ co;
		ch=getchar();
	}
	ll q; in(q);
	FOR(i,0,q-1) {
		ll a, b, c, d; in(a), in(b), in(c), in(d);
		if((pA[b] - pA[a-1])%3 == (pB[d] - pB[c-1])%3) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
