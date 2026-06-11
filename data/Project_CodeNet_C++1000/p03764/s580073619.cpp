#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const int MOD=1e9+7; 
ll x[N],y[N];
int n,m;
int main()
{
	int n;
	scanf("%d%d",&n,&m);
	int maxX=-(1e9+7),minX=1e9+7;
	int maxY=-(1e9+7),minY=1e9+7;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&y[i]);
	}
	sort(x+1,x+n+1);
	sort(y+1,y+m+1);
	ll ans1=0,ans2=0;;
	for(int i=1;i<n;i++)
	{
	     ans1=(ans1%MOD+(((x[i+1]-x[i])%MOD*i%MOD*(n-i)%MOD)%MOD)%MOD)%MOD;

	}
	for(int i=1;i<m;i++)
	{
	     ans2=(ans2%MOD+((y[i+1]-y[i])%MOD*i%MOD*(m-i)%MOD)%MOD)%MOD;
	}
	
	 cout<<(ans1%MOD*ans2%MOD)%MOD<<endl;
    return 0;
}