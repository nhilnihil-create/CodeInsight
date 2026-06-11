#include<bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPN(i,n) for(int i=1;i<=(n);i++)
using namespace std;
int n,fa[100050],num[100050];
vector<int>c[100050];
int dfs(int n,int f)
{
	fa[n]=f;
	int t=1;
	for(int i=0;i<c[n].size();i++)
	{
		if(c[n][i]!=f)
		{
			t+=dfs(c[n][i],n);
		}
	}	
	return num[n]=t;
}
int main()
{
	cin>>n;
	int a,b;
	REPN(i,n-1)
	{
		cin>>a>>b;
		c[a].push_back(b);
		c[b].push_back(a);
	}
	num[1]=dfs(1,1);
	int z=n,sum=0;
	while(fa[z]!=z)
	{
		sum++;
		z=fa[z];
	}
	z=n;
	REPN(i,(sum-1)/2)
	{
		z=fa[z];
	}
	if(num[z]>=n-num[z])
	{
		cout<<"Snuke"<<endl;
	}
	else 
	{
		cout<<"Fennec"<<endl;
	}
	return 0;
} 