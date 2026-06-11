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
int n,a[100100],m;
map<int,int> mp;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int main()
{
	n=read();m=read();
	rep(i,1,n) a[i]=read();
	int profit=0,cnt=0,mx=a[n];
	per(i,n-1,1)
	{
		int tmp=mx-a[i];
		if (tmp>profit) {profit=tmp;cnt=1;}
		else if (tmp==profit) cnt++;
		mx=max(mx,a[i]);
	}
	mp[a[n]]=1;int ans=0;
	per(i,n-1,1)
	{
		if (mp.count(a[i]+profit)) ans++;
		mp[a[i]]=1;
	}
	printf("%d",ans);
	return 0;
}
	