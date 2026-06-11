#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = a; i >= b; i--)
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef double db;
const int N = 1e5+100;
const db EPS = 1e-9;
using namespace std;

void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}

int n,m,a[N],pre[N][70];
ll x[N],k,v[N],ans[N];

void init(){
	for(ll j = 1; (1ll<<j) <= k; j++)
		for(int i = 0; i <= n; i++)
			pre[i][j] = pre[pre[i][j-1]][j-1];
}

int query(int pos,ll t){
	if(t == 0) return pos;
	for(ll j = 62; j >= 0; j--)
		if((1ll<<j) <= t) return query(pre[pos][j],t-(1ll<<j));
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&x[i]);
	x[n+1] = x[n-1]; x[0] = x[2];
	v[0] = x[0];
	rep(i,1,n+1) v[i] = x[i]-x[i-1];
	rep(i,0,n+1) pre[i][0] = i;
	scanf("%d%lld",&m,&k);
	rep(i,1,m){
		scanf("%d",&a[i]);
		swap(pre[a[i]][0],pre[a[i]+1][0]);
	}
	init();
	rep(i,0,n+1) ans[i] = v[i];
	rep(i,1,n) ans[i] = v[query(i,k)];
	rep(i,1,n){
		ans[i] = ans[i-1]+ans[i];
		printf("%lld.0\n",ans[i]);
	}
	return 0;
}