#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> p;
bool cmp(p a,p b)
{
	if(a.fi==b.fi) return a.se<b.se;
	else return a.fi<b.fi;
}
p par[100007];
int a,n,cur,ans[100007];
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		par[i]=mp(a,i+1);
		cur=max(cur,a);
	}
	par[n]=mp(0,0);
	sort(par,par+n+1,cmp);
	int mn=1e9+7;
	for(int i=n-1;i>=0;i--)
	{
//		cout<<par[i+1].fi<<" "<<par[i+1].se<<endl;
		if(par[i].fi!=cur)
		{
			int x=par[i+1].fi,y=par[i+1].se;
			mn=min(mn,y);
			ans[mn]+=(cur-par[i].fi)*(n-i);
			cur=par[i].fi;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<endl;
	}
}