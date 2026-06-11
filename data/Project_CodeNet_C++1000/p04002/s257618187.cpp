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
const int dx[]={-1,-1,-1,0,0,0,1,1,1},dy[]={-1,0,1,-1,0,1,-1,0,1};
int n,m,k;
ll ans[11];
map<pii,int> col,vis;
pii p[100100];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int calc(pii st)
{
	int cnt=0;
	rep(i,0,8)
	{
		pii now;now.fir=st.fir+dx[i];now.sec=st.sec+dy[i];
		if (col.count(now)) cnt++;
	}
	//cout << st.fir << " " << st.sec << " " << cnt << endl;
	return cnt;
}

bool ok(pii now)
{
	return ((now.fir>=2) && (now.fir<=n-1) && (now.sec>=2) && (now.sec<=m-1));
}

int main()
{
	n=read();m=read();k=read();
	rep(i,1,k)
	{
		p[i].fir=read();p[i].sec=read();
		col[p[i]]=1;
	}
	rep(i,1,k)
	{
		rep(j,0,8)
		{
			pii now;
			now.fir=p[i].fir+dx[j];now.sec=p[i].sec+dy[j];
			if ((vis[now]) || (!ok(now))) continue;
			vis[now]=1;int tmp=calc(now);ans[tmp]++;
		}
	}
	ans[0]=1ll*(n-2)*(m-2);
	rep(i,1,9) ans[0]-=ans[i];
	rep(i,0,9) printf("%lld\n",ans[i]);
	return 0;
}
