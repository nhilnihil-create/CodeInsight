#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int sum=0;
vector<int> a[2500];	
int n,k;
int dfs(int x,int fa,int d)
{
	if(d>k/2) return 0; ++sum;
	for(int i=0;i<a[x].size();++i)
	{
		int son=a[x][i];
		if(son==fa) continue;
		dfs(son,x,d+1);
	}
	return 0;
}
int main ()
{

	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y); a[y].push_back(x);
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		sum=0;
		if(k%2==0) dfs(i,0,0);
		else dfs(i,a[i][0],0),dfs(a[i][0],i,0);
		ans=max(sum,ans);
//		cout<<ans<<" "<<sum<<"  "<<i<<endl;
	}
	printf("%d\n",n-ans);
       return 0;
}