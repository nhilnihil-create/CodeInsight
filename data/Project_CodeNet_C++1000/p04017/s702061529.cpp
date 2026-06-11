#include <bits/stdc++.h>
using namespace std;
#define int long long
#define testing 0
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
#define IAMSPEED ios_base::sync_with_stdio(false); cin.tie(0);
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << " , " << #y << "=" << y << endl
#define db3(a,b,c) cerr<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c<<endl
#define dbv(v) cerr << #v << ":"; for (auto i : v) cerr << i << ' '; cerr << endl
#define dbvp(v) cerr << #v << ":"; for (auto i : v) cerr << "{"  << i.f << ',' << i.s << "} "; cerr << endl
#define dba(a,ss,ee) cerr << #a << ":"; FOR(i,ss,ee) cerr << a[i] << ' '; cerr << endl
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long 
#define pb push_back
#define inf (int)1e9+500
#define oo (ll)1e18
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define reach cerr << "hi\n";
typedef pair <int, int> pi;
typedef pair <ll,ll> pl;
typedef pair <pi, int> pii;
typedef tuple<int,int,int> ti3;
string cts(char x) {string s(1,x); return s;}
const int MOD = 1e9 + 7;
template <typename T> void maxself(T& a, T b) {
	a = max(a, b);
}
template <typename T> void minself(T& a, T b) {
	a = min(a, b);
}
#define MAXN (int)1e5+5
#if !testing
#define cerr if(0)cout
#endif
int A[MAXN];
const int sqn = 400;
int cnt[sqn+5][sqn+5], nxt[sqn+5][sqn+5], id[sqn+5][sqn+5]; //ith element in the jth bucket 
//"inspiration" from holes
int32_t main() {
	IAMSPEED
	// set testing to 0 when submitting to judge
	int n; cin>>n;
	FOR(i,0,n-1)cin>>A[i];
	int L;cin>>L;
	cnt[(n-1)%sqn][(n-1)/sqn]=1;
	nxt[(n-1)%sqn][(n-1)/sqn]=id[(n-1)%sqn][(n-1)/sqn]=n+1;
	DEC(i,n-2,0) {
		int tgt = prev(upper_bound(A,A+n,A[i]+L))-A;
		if(i/sqn==tgt/sqn) {
			cnt[i%sqn][i/sqn]=cnt[tgt%sqn][tgt/sqn]+1;
			nxt[i%sqn][i/sqn]=tgt;
			id[i%sqn][i/sqn]=id[tgt%sqn][tgt/sqn];
		} else {
			cnt[i%sqn][i/sqn]=1;
			nxt[i%sqn][i/sqn]=id[i%sqn][i/sqn]=tgt;
		}
	}
	FOR(i,0,n-1) {
		//printf("cnt: %i nxt: %i id: %i\n",cnt[i%sqn][i/sqn],nxt[i%sqn][i/sqn],id[i%sqn][i/sqn]);
	}
	int Q;cin>>Q;
	while(Q--) {
		int a,b;cin>>a>>b;
		--a,--b;
		if(a>b)swap(a,b);
		int day = 0;
		int idx = a;
		FOR(i,a/sqn,b/sqn) {
			if(idx>=b)break;
			db2(idx,day);
			if(i==b/sqn) {
				while(idx<b) {
					++day;
					idx=nxt[idx%sqn][idx/sqn];
				}
			} else {
				day+=cnt[idx%sqn][idx/sqn];
				idx=id[idx%sqn][idx/sqn];
				if(idx>=b)break;
			}
		}
		cout<<day<<'\n';
	}
}
