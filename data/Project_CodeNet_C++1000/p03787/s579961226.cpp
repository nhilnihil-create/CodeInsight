#include<bits/stdc++.h>
using namespace std;
vector <int> des[200010];
int col[200010];
bool dfs(int s)
{
	bool ans=true;
	for (int k=0;k<des[s].size();k++)
	{
		if (col[des[s][k]]==-1) {col[des[s][k]]=!col[s];if (!dfs(des[s][k])) ans=false;}
		else if (col[des[s][k]]==col[s]) ans=false;
	}
	return ans;
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		des[u].push_back(v);des[v].push_back(u);
	}
	for (int i=1;i<=n;i++) col[i]=-1;
	long long yes=0,no=0,sig=0;
	for (int i=1;i<=n;i++) if (col[i]==-1)
	{
		col[i]=0;
		if (des[i].size()==0) sig++;
		else if (dfs(i)) yes++;else no++;
	}//cout<<sig<<' '<<yes<<' '<<no<<endl;
	printf("%lld\n",sig*sig+sig*(n-sig)*2+yes*yes*2+no*no+yes*no*2);
}