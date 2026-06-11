#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(_i,_a,_n) for(int _i=_a;_i<=_n;++_i)
#define PER(_i,_a,_n) for(int _i=_n;_i>=_a;--_i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(_a) ({REP(_i,1,n) cout<<_a[_i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



#ifdef __APPLE__
const int N = 1e2+50;
#else
const int N = 1e6+50;
#endif


int n,k,u[N],v[N];
vector<int> g[N];
int dfs(int x, int f, int d) {
	int ans = d<0;
	for (int y:g[x]) if (y!=f) ans += dfs(y,x,d-1);
	return ans;
}
int main() {
	scanf("%d%d", &n, &k);
	REP(i,2,n) {
		scanf("%d%d",u+i,v+i);
		g[u[i]].pb(v[i]);
		g[v[i]].pb(u[i]);
	}
	int ans = n;
	if (k&1) {
		REP(i,2,n) ans=min(ans,dfs(u[i],v[i],k/2)+dfs(v[i],u[i],k/2));
	}
	else {
		REP(i,1,n) ans=min(ans,dfs(i,0,k/2));
	}
	printf("%d\n", ans);
}







