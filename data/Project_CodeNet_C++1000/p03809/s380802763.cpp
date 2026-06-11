#include<iostream>
#include<vector>
using namespace std;
bool flag=1;
int n;
long a[1<<17];
vector<int>G[1<<17];
long dfs(int u,int p)
{
	if(G[u].size()==1)return a[u];
	long sum=0;
	vector<long>x;
	for(int i=0;i<G[u].size();i++)
	{
		if(G[u][i]==p)continue;
		long y=dfs(G[u][i],u);
		x.push_back(y);
		sum+=y;
	}
	long k=sum-a[u];
	long l=2*a[u]-sum;
	if(k<0||l<0)flag=0;
	long ss=0;
	for(int i=0;i<x.size();i++)
	{
		ss+=x[i]<k?x[i]:k;
	}
	if(ss<2*k)flag=0;
	return l;
}
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		int x,y;cin>>x>>y;
		x--,y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(n==2)
	{
		cout<<(a[0]==a[1]?"YES":"NO")<<endl;
		return 0;
	}
	int root=0;
	for(int i=1;i<n;i++)
	{
		if(G[root].size()<G[i].size())
		{
			root=i;
		}
	}
	if(dfs(root,-1)!=0||!flag)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}