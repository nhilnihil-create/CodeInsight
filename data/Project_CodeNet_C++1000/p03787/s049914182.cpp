#include<iostream>
#include<vector>
using namespace std;
vector<int>G[1<<17];
int n,m;
long a,b,c;
int v[1<<17];
bool dfs(int u,int col)
{
	v[u]=col;
	bool ans=1;
	for(int i=0;i<G[u].size();i++)
	{
		if(!v[G[u][i]])ans&=dfs(G[u][i],3-col);
		else
		{
			ans&=v[G[u][i]]==3-col;
		}
	}
	return ans;
}
main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=0;i++<n;)
	{
		if(!v[i])
		{
			if(G[i].size()==0)c++;
			else if(dfs(i,1))a++;
			else b++;
		}
	}
	cout<<2*c*n-c*c+2*a+b*b+a*(a-1)*2+a*b*2<<endl;
}