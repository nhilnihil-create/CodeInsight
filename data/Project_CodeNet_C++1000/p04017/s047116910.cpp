#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=100000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u];i;i=sq[i].nxt)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
int n,a[100100],to[100100][20],len,q;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int main()
{
	n=read();
	rep(i,1,n) a[i]=read();
	len=read();
	rep(i,1,n)
	{
		int pos=upper_bound(a+1,a+1+n,a[i]+len)-a-1;
		if (pos<=n) to[i][0]=pos;
	}
	rep(j,1,19) rep(i,1,n)
		to[i][j]=to[to[i][j-1]][j-1];
	q=read();
	while (q--)
	{
		int u=read(),v=read();
		if (u>v) swap(u,v);
		if (u==v) {printf("0\n");continue;}
		int ans=1;
		per(i,19,0)
			if (to[u][i]<v)
			{
				u=to[u][i];
				ans+=(1<<i);
			}
		printf("%d\n",ans);
	}
	return 0;
}