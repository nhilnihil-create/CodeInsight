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
#define siz(x) ll(x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?llabs(b):gcd(b%a,a); }
 
typedef long long ll; 
typedef long double ld;
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
typedef pair<ll,ll>pi; typedef pair<ll,pi>spi; typedef pair<pi,pi>dpi;
 
#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (300006)
ll n, ma, mb, dp[51][55][55];
spi A[51];
int main()
{
	FAST
	cin>>n>>ma>>mb;
	FOR(i,0,n-1) cin>>A[i].s.f>>A[i].s.s>>A[i].f;
	mmst(dp,-1);
	function<ll(ll,ll,ll)>lol=[&](ll pos,ll x,ll y){
		if(~dp[pos][x][y]) return dp[pos][x][y];
		if(pos==n&&x==0&&y==0) return 0ll;
		if(x<0||y<0) return LLINF;
		if(x>50||y>50) return LLINF;
		if(pos==n) return LLINF;
		ll &ans=dp[pos][x][y]=LLINF;
		ans=lol(pos+1,x,y);
		ans=min(ans,lol(pos+1,x-A[pos].s.f,y-A[pos].s.s)+A[pos].f);
		return ans;
	};
	ll ans = LLINF;
	FOR(a,1,50) { if(a>=ma&&a%ma==0)
		ans=min(ans,lol(0, a, a/ma * mb));
	}
	cout<<(ans==LLINF?-1:ans);
}
