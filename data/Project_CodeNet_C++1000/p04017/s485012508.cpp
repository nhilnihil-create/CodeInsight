#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N=2e5+20;
const int M=5e2+20;
const ll inf=2e15;
ll n,x[N],L,Q;
ll d[30][N];
void init()
{
	for(ll i=1;i<=20;i++)
	{
		for(int j=1;j<=N;j++)
		{
			d[i][j]=d[i-1][d[i-1][j]];
		}
	}
}
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			scanf("%I64d",&x[i]);
		cin>>L>>Q;
		for(int i=1;i<=n;i++)
		{
			int l=i+1,r=n;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(x[mid]-x[i]<=L)
					l=mid+1;
				else
					r=mid-1;
			}
			d[0][i]=l-1;
		}
		init();
		ll u,v;
		while(Q--)
		{
			scanf("%I64d%I64d",&u,&v);
			if(u>v)
				swap(u,v);	
			ll ans=0;
			for(ll i=20;i>=0;i--)
			{
				if(d[i][u]<v)
					ans+=(1ll<<i),u=d[i][u];
			}
			ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}

