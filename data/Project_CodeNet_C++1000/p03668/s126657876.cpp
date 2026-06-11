#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5;
vector<int>lk[N];
int sg[N];

void dfs(int x,int fr)
{
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs(y,x);
		sg[x]^=sg[y]+1;
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	int n;
	cin>>n;
	rep(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	dfs(1,0);
	puts(sg[1]?"Alice":"Bob");
}