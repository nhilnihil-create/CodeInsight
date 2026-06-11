#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
int n,k,a,b;
vector<int>v[N];
int maxn=0,vis[N],cnt;
pair<int,int>edge[N];
void dfs(int val,int cs)
{
	if(vis[val]==1)
	return;
	vis[val]=1;
	if(cs==k/2+1)
	return;
	for(int i=0;i<v[val].size();i++)
	{
		if(vis[v[val][i]])
		continue;
		cnt++;
		dfs(v[val][i],cs+1);
	}
	return;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		if(a>b)
		swap(a,b);
		edge[i].first=a;
		edge[i].second=b;
	}
	int ma=0;
	if(k%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			vis[j]=0;
			cnt=1;
			dfs(i,1);
			ma=max(ma,cnt);
		}
		printf("%d\n",n-ma);
//		cout<<n-maxn<<endl;
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<=n;j++)
			vis[j]=0;
			int aa=edge[i].first,bb=edge[i].second;
			vis[bb]=1;
			cnt=1;
			dfs(aa,1);
			int sum=cnt;
//			cout<<sum<<" ";
			vis[aa]=1;
			vis[bb]=0;
			cnt=1;
			dfs(bb,1);
			sum+=cnt;
//			cout<<cnt<<endl;
			ma=max(ma,sum);
		}
		printf("%d\n",n-ma);
	}
}