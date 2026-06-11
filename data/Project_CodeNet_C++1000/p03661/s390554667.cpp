#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<cstring>
#include<algorithm>
#define ll long long
#define Max(x,y) ((x) > (y) ? (x) : (y))
#define Min(x,y) ((x) < (y) ? (x) : (y))
#define Abs(x) ((x) > 0 ? (x) : -(x))
#define mod 1000000007
#define N 200010
using namespace std;
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

ll a[N];
ll l[N],r[N];
ll n,ans = 1e18;

signed main(){
	n = read();
	for(ll i = 1;i <= n;i++)
		a[i] = read();
	for(ll i = 1;i <= n;i++)
		l[i] = l[i-1]+a[i];
	for(ll i = n;i >= 1;i--)
		r[i] = r[i+1]+a[i];
	for(ll i = 1;i < n;i++)
		ans = min(ans,Abs(l[i]-r[i+1]));
	printf("%lld\n", ans);
	return 0;
}