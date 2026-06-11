#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define guo cerr<<"guo"<<endl
typedef long long ll;

ll n,top;
vector<int> ans;

inline void dfs(ll x)
{
	if(x==1)return;
	int v=++top;
	if(x&1)
		ans.push_back(v),dfs(x-1);
	else
		dfs(x>>1),ans.push_back(v);
}

int main()
{
	if(fopen("vj.in","r"))
	{
		freopen("vj.in","r",stdin);
		freopen("vj.out","w",stdout);
	}

	scanf("%lld",&n);
	dfs(n+1);
	printf("%d\n",ans.size()*2);
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans.size()-ans[i]+1);
	for(int i=0;i<ans.size();i++)
		printf("%d ",i+1);

	return 0;
}
