#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(register int i = l ; i <= r ; i++)
#define repd(i,r,l) for(register int i = r ; i >= l ; i--)
#define rvc(i,S) for(register int i = 0 ; i < (int)S.size() ; i++)
#define rvcd(i,S) for(register int i = ((int)S.size()) - 1 ; i >= 0 ; i--)
#define fore(i,x)for (register int i = head[x] ; i ; i = e[i].next)
#define forup(i,l,r) for (register int i = l ; i <= r ; i += lowbit(i))
#define fordown(i,id) for (register int i = id ; i ; i -= lowbit(i))
#define pb push_back
#define prev prev_
#define stack stack_
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&(-x))

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pr;

const ld inf = 2e18;
const int N = 3e6 + 10;
const int maxn = 4000020;
const ll mod = 1e9 + 7;

inline ll power(ll x,ll y){
	if ( y < 0 ) return 1;
	ll res = 1;
	while ( y ){
		if ( y & 1 ) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int n,T,a[maxn],mx,mn,k,cnt[maxn];
ll fac[maxn],inv[maxn],f[2020][2020];

void init(){
	fac[0] = inv[0] = 1;
	int tmp = n * k;
	rep(i,1,tmp) fac[i] = fac[i - 1] * i % mod;
	inv[tmp] = power(fac[tmp],mod - 2);
	repd(i,tmp - 1,1) inv[i] = inv[i + 1] * (i + 1) % mod;
}

inline void up(ll &x,ll y){ x = (x + y) % mod; }
inline ll C(int n,int m){
	if ( n < 0 || m < 0 || n < m ) return 0;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main(){
	cin>>n>>k;
	init();
	f[0][0] = 1;
	if ( k == 1 ){ printf("1\n"); return 0; }
	rep(i,0,n){
		rep(j,0,i){
			if ( !f[i][j] ) continue;
			if ( i > j ) up(f[i][j + 1],f[i][j] * C(n * k - i - j * (k - 1) - 1,k - 2) % mod * C(n - j,1));
			up(f[i + 1][j],f[i][j]);
		}
	}
	cout<<f[n][n]<<endl;
}

