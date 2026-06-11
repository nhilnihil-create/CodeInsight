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
#define maxd 1000000007
#define eps 1e-8
int n,m;
char s[5050];
ll f[5050][5050];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int main()
{
	n=read();scanf("%s",s+1);
	m=strlen(s+1);
	f[0][0]=1;
	rep(i,1,n) rep(j,0,n)
	{
		if (j)
			f[i][j]=(f[i-1][j-1]+f[i-1][j+1]*2)%maxd;
		else 
			f[i][j]=(f[i-1][j]+f[i-1][j+1]*2)%maxd;
	}
	printf("%lld",f[n][m]);
	return 0;
}
