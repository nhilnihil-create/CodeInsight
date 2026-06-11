#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
vector<vector<int> >mp(2010);
int temp;
int n,k;
void dfs(int v,int deep,int front)
{
//	cout<<v<<" "<<deep<<" "<<front<<endl;
	if(deep>k/2) temp++;
	if(mp[v].size()==1&&mp[v][0]==front) return;
	for(int i=0;i<mp[v].size();i++)
	{
		if(mp[v][i]!=front)
		{
			dfs(mp[v][i],deep+1,v);
		}
	}
}
int main()
{	
	scanf("%d %d",&n,&k);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	int res=inf;
	if(k%2==0)
	{
		for(int i=1;i<=n;i++)//Ã¶¾ÙÖÐÐÄµã i
		{
		//	cout<<"i= "<<i<<endl;
			temp=0;
			dfs(i,0,0);
			res=min(res,temp);
		//	cout<<endl;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<mp[i].size();j++)
			{
				if(mp[i][j]>i)
				{
				//	cout<<i<<" "<<mp[i][j]<<endl;
					temp=0;
					dfs(i,0,mp[i][j]);
					dfs(mp[i][j],0,i);
					res=min(res,temp);
				}
			}
		}
	}
	printf("%d",res);
} 