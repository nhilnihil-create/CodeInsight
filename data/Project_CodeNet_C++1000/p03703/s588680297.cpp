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
string to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?b:gcd(b%a,a); }

#define ll long long int 
#define ld long double
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
typedef pair <ll, ll> pi; typedef pair <ll, pi> spi; typedef pair <pi, pi> dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (200006)
int n, k, A[MAXN];
struct node {
	int v;
	node *l,*r;
	node(ll _S,ll _E){
		v=0;
		l=r=0;
	}
	void update(ll s, ll e, ll x,ll nval) {
		ll m=(s+e)>>1;
		if(s==e) {
			v += nval;
			return;
		}
		if(x>m) cr(m+1,e), r->update(m+1,e,x,nval); else cl(s,m), l->update(s,m,x,nval);
		v=(l?l->v:0)+(r?r->v:0);
	}
	ll rmq(ll s,ll e,ll x,ll y) {
		ll m=(s+e)>>1;
		if(s==x&&e==y) return v;
		if(x>m) return r?r->rmq(m+1,e,x,y):0;
		else if(y<=m) return l?l->rmq(s,m,x,y):0;
		else return (l?l->rmq(s,m,x,m):0)+(r?r->rmq(m+1,e,m+1,y):0);
	}
	void cl(ll s,ll e) { if(!l) l=new node(s,e); }
	void cr(ll s,ll e) { if(!r) r=new node(s,e); }
} *seg;
int main()
{
	FAST
	cin>>n>>k;
	FOR(i,1,n) cin>>A[i];
	ll sum = 0, ans = 0;
	ll ofs=2e14;
	seg=new node(0, 4e14);
	seg->update(0, 4e14, ofs, 1);
	FOR(i,1,n) {
		sum += A[i];
		ans += seg->rmq(0, 4e14, 0, sum-i*k+ofs);
		seg->update(0, 4e14, sum-i*k+ofs, 1); 
	}
	cout<<ans<<'\n';
}
