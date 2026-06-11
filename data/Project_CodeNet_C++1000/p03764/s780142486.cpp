#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define ld long double
int const M=2e5+10,M2=1e6+10,mod=1e9+7,mod2=1e9+9,inf=1e18+30;
int mn[M],cnt[M],x[M],y[M];
int32_t main()
{
	int n,m;
	cin>>n>>m;
	int l=0,r=0,sum=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=m;i++)cin>>y[i];
	sort(x+1,x+n+1);
	sort(y+1,y+m+1);
	for(int i=1;i<=n;i++)
	{
		int tmp=x[i];
		l+=tmp*(i-1);
		l-=sum;
		sum+=tmp;
	}
	sum=0;
	for(int i=1;i<=m;i++)
	{
		int tmp=y[i];
		r+=tmp*(i-1);
		r-=sum;
		sum+=tmp;
	}
	l%=mod,r%=mod;
	cout<<(l*r)%mod;
}	