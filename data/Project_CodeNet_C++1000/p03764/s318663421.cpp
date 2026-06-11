#include "bits/stdc++.h"
#define debug 0
#define esc(ret) cout << (ret) << endl,quick_exit(0)
#define fcout(d) cout << fixed << setprecision(d)
#define repU(i,s,t) for(int i = (int)(s); i <= (int)(t); ++i)
#define repD(i,s,t) for(int i = (int)(s); i >= (int)(t); --i)
#define rep(i,n) repU(i,0,(n) - 1)
#define rep1(i,n) repU(i,1,(n))
#define all(v) begin(v),end(v)
#define vct vector
#define prique priority_queue
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define qceil(n,d) ((n) > 0 ? ((n) - 1) / (d) + 1 : (n) / (d))
#define parity(a,b) (a & 1 ^ b & 1 ^ 1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<db,int> pdi;

const pii dir[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int mod = 1e9 + 7;
const int inf32 = (1 << 30) - 1;
const ll inf64 = (1LL << 62) - 1;

ll modpow(ll n, ll e, ll m = mod){
	ll res = 1;
	n %= m;
	e %= (m - 1);
	while(e) {
		if(e & 1) res = res * n % m;
		n = n * n % m;
		e >>= 1;
	}
	return res;
}

ll N,M,Q,K,L,H,W,D;
string S;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	vct<ll> x(N),y(M);
	rep(i,N) cin >> x[i];
	rep(j,M) cin >> y[j];
	vct<int> dx(N),dy(M);
	rep1(i,N - 1) dx[i] = x[i] - x[i - 1];
	rep1(i,M - 1) dy[i] = y[i] - y[i - 1];
	ll ans;
	ll pox = 0;
	ll poy = 0;
	rep1(i,N - 1){
	    pox += (ll)i * (N - i) * dx[i];
	    pox %= mod;
	}
	rep1(i,M - 1){
	    poy += (ll)i * (M - i) * dy[i];
	    poy %= mod;
	}
	ans = pox * poy % mod;
	esc(ans);
}
