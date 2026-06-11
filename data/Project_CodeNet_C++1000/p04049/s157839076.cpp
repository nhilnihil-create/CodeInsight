#include<iostream>
#include<cstdio>
#include<vector>
#include<limits>
#include<cmath>
using namespace std;
int n,k,minn,sum,aa[2500],bb[2500];vector<int>a[2500];
void dfs(int qian, int x,int z)
{
	if(z<k)
	for(int i=0;i<a[x].size();++i)
	{
		if(a[x][i]!=qian)
		{
		++sum;
		dfs(x,a[x][i],z+1);
	    }
	}
	
}
int main()
{	
	cin>>n>>k;minn=n;
	for(int i=0;i<n-1;++i)
	{
		scanf("%d%d",&aa[i],&bb[i]);
		a[bb[i]].push_back(aa[i]);
		a[aa[i]].push_back(bb[i]);
	}
	
	if(k%2)
	{
		k/=2;
		for(int i=0;i<n-1;++i)
		{
			sum=2;
			dfs(aa[i],bb[i],0);
			dfs(bb[i],aa[i],0);
			minn=min(minn,n-sum);
		}
		
	}
	else
	{
		k/=2;
		for(int i=1;i<=n;++i)
		{
			sum=1;
			dfs(0,i,0);
			minn=min(minn,n-sum);
		}
		
	}
	
	
	cout<<minn;
    
}