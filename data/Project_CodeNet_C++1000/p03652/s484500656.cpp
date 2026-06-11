#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <deque>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define LL long long
#define Pair pair<int,int>
#define LOWBIT(x) x & (-x)
using namespace std;
 
const int MOD=1e9+7;
const int INF=1e9;
const int magic=348;
 
int n,m;
int a[348][348];
vector<int> v[348];
priority_queue<Pair> q;
int cur[348];
bool used[348];
 
bool check(int cmp)
{
	if (cmp==n) return true;
	int i,j;
	for (i=1;i<=n;i++) cur[i]=1;
	for (i=1;i<=m;i++) v[i].clear();
	for (i=1;i<=n;i++) v[a[i][1]].pb(i);
	//for (i=1;i<=m;i++) cout<<v[i].size()<<' ';
	//cout<<endl;
	for (i=1;i<=m;i++) used[i]=true;
	for (i=1;i<=m;i++)
	{
		int maxn=-1,max_pos;
		for (j=1;j<=m;j++)
		{
			int len=v[j].size();
			//cout<<j<<' '<<v[j].size()<<' '<<maxn<<' '<<used[j]<<endl;
			if (used[j]==true && len>maxn)
			{
				//cout<<"#";
				//cout<<j<<' '<<v[j].size()<<endl;
				maxn=v[j].size();
				max_pos=j;
			}
		}
		if (maxn<=cmp) return true;
		if (i==m) return false;
		used[max_pos]=false;
		for (j=0;j<v[max_pos].size();j++)
		{
			int x=v[max_pos][j];
			cur[x]++;
			while (!used[a[x][cur[x]]]) cur[x]++;
			v[a[x][cur[x]]].pb(x);
		}
	}
	return false;
}
 
int main ()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int l=1,r=n,mid,ans;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}