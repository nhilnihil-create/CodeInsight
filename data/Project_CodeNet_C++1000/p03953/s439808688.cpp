#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int n,f[maxn][60],dsy[maxn],fxk[maxn],m,x;ll ans,a[maxn],p[maxn],k; 
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,n-1) p[i]=a[i+1]-a[i],f[i][0]=i,fxk[i]=i;
	scanf("%d%lld",&m,&k);
	rep(i,1,m) scanf("%d",&x),swap(f[x-1][0],f[x][0]);
	rep(i,1,59) rep(j,1,n-1) f[j][i]=f[f[j][i-1]][i-1];
	per(i,59,0) if(k&(1ll<<i)){
		rep(j,1,n-1) dsy[j]=f[fxk[j]][i];
		rep(j,1,n-1) fxk[j]=dsy[j];
	}
	printf("%lld.0\n",a[1]);ans=a[1];
	rep(i,1,n-1) ans+=p[fxk[i]],printf("%lld.0\n",ans);
	return 0;
}