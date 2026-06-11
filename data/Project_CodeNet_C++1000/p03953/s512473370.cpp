#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define pb push_back
typedef double db;
typedef long long ll;
typedef pair<int,int> P;
const int MAXN=1e5+10;
ll res[MAXN],k,top;
int vis[MAXN],st[MAXN];
int n,m,x,d[MAXN],nxt[MAXN];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&d[i]),nxt[i]=i;
	for(int i=n;i>=1;i--) d[i]=d[i]-d[i-1];
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d",&x),swap(nxt[x],nxt[x+1]);
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		top=0;
		for(int j=i;!vis[j];j=nxt[j])
		{
			st[++top]=j;
			vis[j]=1;
		}
		for(int j=1;j<=top;j++)
			res[st[j]]=d[st[(j+k-1)%top+1]];
	}
	for(int i=1;i<=n;i++)
		res[i]+=res[i-1],printf("%lld\n",res[i]);
	return 0;
}