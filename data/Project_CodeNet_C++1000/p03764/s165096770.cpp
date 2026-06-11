#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())

typedef long long ll;
const ll INF = 2e15+7;
const ll mod = 1e9+7;
const int MAX_N = 5e5+5;
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
vector<ll> prime;

ll inv[MAX_N],fac[MAX_N];

template <class T = int> T in(){T x;cin >> x;return (x);}
inline ll GCD(ll a,ll b){ll c;while(b!=0){c=a%b;a=b;b=c;}return a;}
inline ll LCM(ll a,ll b){return a*b/GCD(a,b);}
inline ll POW(ll a,ll b){ll c=1;while(b>0){if(b&1){c=a*c%mod;}a=a*a%mod;b>>=1;}return c;}
inline void _nCr(){fac[0]=1;for(int i=1;i<MAX_N;i++){fac[i]=fac[i-1]*i%mod;}for(int i=0;i<MAX_N;i++){inv[i]=POW(fac[i],mod-2);}}
inline ll nCr(ll n,ll r){return (fac[n]*inv[r]%mod)*inv[n-r]%mod;}
inline void PRI(ll n){bool a[n+1];for(int i=0;i<n+1;i++){a[i]=1;}for(int i=2;i<n+1;i++){if(a[i]){prime.pb(i);ll b=i;while(b<=n){a[b]=0;b+=i;}}}}

class UnionFind {
private:
	int par[MAX_N];
	int rank[MAX_N];
public:
	void init(int n);
	int find(int x);
	void unite(int x,int y);
	bool same(int x,int y);
};

void UnionFind::init(int n) {
	for (int i = 0;i < n;i++) {
		par[i] = i;
		rank[i] = 0;
	}
}

int UnionFind::find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void UnionFind::unite(int x,int y) {
	x = find(x);
	y = find(y);
	if (rank[x] < rank[y]) par[x] = y;
	else {
		par[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
}

bool UnionFind::same(int x,int y) {
	x = find(x);
	y = find(y);
	return x == y;
}

int main() {
	int n=in(),m=in();
	ll x[n],y[m],difx[n],dify[m];
	difx[0]=dify[0]=0;
	ll xsum,ysum=xsum=0;
	ll cnt=n-1;
	REP(i,n){x[i]=in();if(i)difx[i]=x[i]-x[i-1];}
	REP(i,m){y[i]=in();if(i)dify[i]=y[i]-y[i-1];}
	FOR(i,1,n){
		xsum=(xsum+difx[i]*cnt%mod)%mod;
		cnt=cnt-i*2+n-1;
	}
	cnt=m-1;
	FOR(i,1,m){
		ysum=(ysum+dify[i]*cnt%mod)%mod;
		cnt=cnt-i*2+m-1;
	}
	cout << xsum*ysum%mod << endl;
}