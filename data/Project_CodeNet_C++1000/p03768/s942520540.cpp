//**************************
//*** writer  :  Alex Hu **
//************************

#include<bits/stdc++.h>

using namespace std;

#define CLEAN(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define pb push_back
#define rept(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=1e5+10;

int n,m,cnt,tot,fst[maxn],pnt[maxn<<1],nxt[maxn<<1],ans[maxn],dp[maxn][11];

void add(int x,int y)
{
	pnt[++tot]=y;
	nxt[tot]=fst[x];
	fst[x]=tot;
} 

int main()
{
	scanf("%d%d",&n,&m);
	int x,y;
	rept(i,1,m+1)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	scanf("%d",&cnt);
	rept(i,1,cnt+1)
	{
		scanf("%d%d%d",&x,&y,&ans[i]);
		dp[x][y]=i;
	}
	for (int i=9;i>=0;i--)
	{
		rept(x,1,n+1)
		{
			dp[x][i]=max(dp[x][i],dp[x][i+1]);
			for (int j=fst[x];j;j=nxt[j]) dp[x][i]=max(dp[x][i],dp[pnt[j]][i+1]);
		}
	}
	rept(i,1,n+1) printf("%d\n",ans[dp[i][0]]);
	return 0;
}