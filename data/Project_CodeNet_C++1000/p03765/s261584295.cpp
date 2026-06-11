#include <bits/stdc++.h>
using namespace std;
#define testing 1
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
#define MAXN 100005
#if !testing
#define cerr if(0)cout
#endif
pi sum1[MAXN],sum2[MAXN];
int32_t main() {
	IAMSPEED
	// set testing to 0 when submitting to judge
	string S,T;cin>>S>>T;
	int n = S.size();
	int m = T.size();
	S.insert(S.begin(),'0');
	T.insert(T.begin(),'0');
	FOR(i,1,n) {
		sum1[i]=sum1[i-1];
		if(S[i]=='A')sum1[i].f++;
		else sum1[i].s++;
	}
	FOR(i,1,m) {
		sum2[i]=sum2[i-1];
		if(T[i]=='A')sum2[i].f++;
		else sum2[i].s++;
	}
	int Q;cin>>Q;
	while(Q--) {
		int a,b,c,d;cin>>a>>b>>c>>d;
		cerr << sum1[b].f-sum1[a-1].f << ' ' << sum1[b].s-sum1[a-1].s << ' ' << sum2[d].f-sum2[c-1].f << ' ' << sum2[d].s-sum2[c-1].s << endl;
		int s1=sum1[b].f-sum1[a-1].f, s2=sum1[b].s-sum1[a-1].s, s3=sum2[d].f-sum2[c-1].f, s4=sum2[d].s-sum2[c-1].s;
		int m1 = (s1-s3);
		int m2 = (s2-s4);
		if(m1<m2)swap(m1,m2);
		m1%=3;
		m2%=3;
		if(m1>0&&m2>0) {
			m2-=3;
		}
		if(m1<0&&m2<0){
			m1+=3;
		}
		if(m1>=0&&m2<=0){
			if((abs(m1)+abs(m2))%3==0)cout << "YES\n";
			else cout << "NO\n";
		} else cout << "NO\n";
	}
}
