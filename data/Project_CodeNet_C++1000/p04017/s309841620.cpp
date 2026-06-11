#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> ii;
int n,rmq[200005][25],x[200005],l,q;
signed main()
{
	queue<ii> que;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]; 
	}
	cin>>l>>q;
	for(int j=0;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			rmq[i][j]=200003;
		}
	}
	int cnt=0;
	while(1)
	{
		if(cnt==n+1) break;
		cnt++;
		que.push(ii(x[cnt],cnt));
		while(1)
		{
			if(x[cnt]-que.front().first>l)
			{
				rmq[que.front().second][0]=cnt-1;
				que.pop();
			}
			else break;
		}
	}
	while(!que.empty())
	{
		rmq[que.front().second][0]=n;
		que.pop();
	}
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
		    rmq[i][j]=rmq[rmq[i][j-1]][j-1];
		}
	}
	while(q--)
	{
		int u,v,res=0;
		cin>>u>>v;
		if(u>v) swap(u,v);
		for(int i=20;i>=0;i--)
		{
			if(rmq[u][i]<v)
			{
				res+=(1<<i);
				u=rmq[u][i];
			}
		}
		if(u!=v) res++;
		cout<<res<<"\n";
	}
}