#include<bits/stdc++.h>
#define pb push_back
#define opr iterator
#define vi vector<int>
typedef long long ll;
using namespace std;
int tot;
int n,k;
vector<int> can[2001];
bool visit[2001];
int dfs(int pos1,int pos2,int num,int nk)
{
	ll ans=1;
	int size=can[pos1].size();
	if(num!=nk)
	{
		for(int i=0;i<size;i++)
		{
			if(can[pos1][i]==pos2)
			{
				continue;
			}
			ans+=dfs(can[pos1][i],pos1,num+1,nk);
		}
	}
	return ans;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		can[a].pb(b);
		can[b].pb(a);
	}
	int cnt=0;
	if(k%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			cnt=max(cnt,dfs(i,-1,0,k/2));
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int p=0;p<can[i].size();p++)
			{
				int j=can[i][p];
				cnt=max(cnt,(dfs(i,j,0,(k-1)/2)+dfs(j,i,0,(k-1)/2)));
			}
		}
	}
	cout<<max(n-cnt,0)<<endl;
	return 0;
}